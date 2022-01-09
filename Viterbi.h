#ifndef BIOINFOUB10_VITERBI_H
#define BIOINFOUB10_VITERBI_H

#include <vector>
#include <string>
#include "Coin.h"
#include "console.h"
#include "Matrix.h"
#include "Format.h"
#include "Markov.h"

using namespace std;


class Viterbi {
public:
    // Create HMM
        Viterbi(Markov _markov,double p_begin, vector<Flip> _sequence);

    // matrix calculate formula
        static double formula(double p_w_at_coin,double max_a1,double max_a2,double max_b1,double max_b2);

    // Backtracking
        void backtracking();

    // Getter for Testing
        Matrix getMatrix();
        double get_p_begin();
        Markov get_markov_matrices();
        std::vector<Flip> get_Sequence();
        std::vector<Coin> get_Result();

    // Result-String for Console Output
        string Sequence_toString(bool with_result);
private:
    Matrix M = Matrix(0, 0);
    Markov _markov;
    double p_begin;
    std::vector<Flip> sequence;
    std::vector<Coin> result;
};




/** Returns the Sequence of the Coin-Flips, if with_result chosen,
 *  the calculated Fair/Unfair throw will colorized in the String:
 *   [Red   = unfair throw]
 *   [Green = fair throw]
 *   [White = unknown (=error) ]
 *   (0 is Tail, 1 is Head)
 *
 * @with_result Colored fair-throw result
 * @return The sequence in format { 01011 }
 * */
string Viterbi::Sequence_toString(bool with_result) {

    string res = C::BWHITE;
    res += "{ ";
    int coin_pos = 0;

    for (Flip f : sequence) {

        if (with_result) {
            if (result[coin_pos] == Fair) {res += C::BGREEN;}
            else if (result[coin_pos] == Unfair) {res += C::BRED;}
            else {res += C::BWHITE;}
        }

        if (f == Tail) {res += "0";}
        if (f == Head) {res += "1";}

        if (with_result) { res += C::BWHITE;
            coin_pos ++ ;}

    }

    res += " }";res += C::RESET;

    return res;
}



/** Calculate a cell from the matrix.
 *
 * @p_w_at_coin   probabilty of this FLip with this coin
 * @max_a1
 * @max_a2
 * @max_b1
 * @max_b2
 * */
double Viterbi::formula(double p_w_at_coin, double max_a1, double max_a2, double max_b1, double max_b2) {

    double a = max_a1 * max_a2;
    double b = max_b1 * max_b2;

    double max_value = std::max(a,b);

    return p_w_at_coin * max_value;
}






/** Returns an Viterbi-Object ans create the HMM_Matrix inside and fill
 *  his with the algorithm with values.
 *
 * @p_begin    Prob. for begin with the Fair Coin
 * @p_unfair   Prob. for throw the Unfair Coin
 * @p_change   Prob. for change between Coin{Fair,Unfair}
 * @_sequence  The Coin-Throw sequence Values: Flip{Head, Tail}
 * @return     Viterbi-Object with filled matrix
 * */
Viterbi::Viterbi(Markov _markov, double p_begin, vector<Flip> _sequence) {

    // Check Arguments
    if (_sequence.empty())   {throw std::invalid_argument("argument _sequence is empty!"); }

    // Initialize Fields
    this->_markov = _markov;
    this->p_begin = p_begin;
    this->sequence = _sequence;

    // Initialize Matrix

    this->M = Matrix(2,_sequence.size() + 1);

    // ## Start Algorithm (Fill Matrix)

       // init

       double last_fair   = 0.0; // at row 0 (y = 0)
       double last_unfair = 0.0; // at row 1 (y = 1)
       int actual_column  = 1;
       int max_col        = _sequence.size() ;
       double pw_at_coin = 0.0;
       double max_a1 = 0.0;
       double max_a2 = 0.0;
       double max_b1 = 0.0;
       double max_b2 = 0.0;
       double resA    = 0.0;
       double resB    = 0.0;

       Flip Xi = _sequence[0];

       // column 1

       //last_fair   = formula(p_begin,1,1,0,0);
       //last_unfair = formula(1.0-p_begin,1,1,0,0);
     
       last_fair = p_begin*_markov.prodProbability(Fair,Xi);
       last_unfair = (1.0-p_begin)*_markov.prodProbability(Unfair,Xi);
       M.setValue(0,0,last_fair);
       M.setValue(1,0,last_unfair);

       // remaining colums

       while (actual_column <= max_col) { // start at col 2

           // FLip at Column

           Xi = _sequence[actual_column];

           // row 0 (fair)
           pw_at_coin = _markov.prodProbability(Fair,Xi);
           max_a1     = last_fair;
           max_a2     = _markov.changeProbability(Fair,Fair);
           max_b1     = last_unfair;
           max_b2     = _markov.changeProbability(Unfair,Fair);

           resA       = formula(pw_at_coin,max_a1,max_a2,max_b1,max_b2);

           M.setValue(0,actual_column,resA);

           // row 1 (unfair)
           pw_at_coin = _markov.prodProbability(Unfair,Xi);
           max_a1     = last_fair;
           max_a2     = _markov.changeProbability(Unfair,Unfair);
           max_b1     = last_unfair;
           max_b2     = _markov.changeProbability(Fair,Unfair);

           resB       = formula(pw_at_coin,max_a1,max_a2,max_b1,max_b2);

           M.setValue(0,actual_column,resB);

           // set last values for next column

           last_fair   = resA;
           last_unfair = resB;

           // continue to next column
           actual_column++;;
       }

    //_markov.print_matrices();
/*

    /*
    _markov.changeProbability(Fair,Fair);
    _markov.changeProbability(Fair,Unfair);

    _markov.prodProbability(Fair,Head);
    _markov.prodProbability(Unfair,Tail);

    M.setValue(1,3,4); // y = zeile // x = spalte
    M.setValue(0,4,5);
*/

    M.print();
    //M.print();





}








/** Backtracking in matrix for create the Result-Sequence of Coin{Fair,Unfair}
 *  for evaluate the Input/Throw-Sequence.
 *
 * @return     nix
 * */
void Viterbi::backtracking() {

    // Create result sequence

    int actual_column = sequence.size();

    while (actual_column >= 0) { // start at last column an move to first column

        // read first value in the actual column
        double row_A = M.getValue(0,actual_column);
        // read second value in the actual column
        double row_B = M.getValue(1,actual_column);

        // do something ... and add Fair or Unfair to result

        //result.push_back(Unfair);
        //result.push_back(Fair);

        // next column
        actual_column--;


    }





// reverse the backtracking-list



// - Backtracking END -








    result.push_back(Unfair);
    result.push_back(Fair);
    result.push_back(Fair);
    result.push_back(Unfair);
    result.push_back(Unfair);
    result.push_back(Fair);
    result.push_back(Unfair);
    result.push_back(Fair);
    result.push_back(Unfair);

}











// Getter
Matrix Viterbi::getMatrix()      { return M; }
double Viterbi::get_p_begin()    { return p_begin; }
std::vector<Flip> Viterbi::get_Sequence() { return sequence;}
std::vector<Coin> Viterbi::get_Result() { return result;}
Markov Viterbi::get_markov_matrices() { return _markov;}







#endif //BIOINFOUB10_VITERBI_H
