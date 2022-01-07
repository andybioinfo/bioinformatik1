#ifndef BIOINFOUB10_VITERBI_H
#define BIOINFOUB10_VITERBI_H

#include <vector>
#include <string>
#include "Coin.h"
#include "console.h"
#include "Matrix.h"

using namespace std;


class Viterbi {
public:
    // Create HMM
        Viterbi(double p_begin, double p_unfair, double p_change, vector<Flip> _sequence);
    // Backtracking
        void backtracking();
    // Getter for Testing
       // Matrix getMatrix();
        double get_p_begin();
        double get_p_unfair();
        double get_p_change();
        std::vector<Flip> get_Sequence();
        std::vector<Coin> get_Result();
    // Result-String for Console Output
        string Sequence_toString(bool with_result);
private:
    Matrix M = Matrix(0, 0);
    double p_begin;
    double p_unfair;
    double p_change;
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


/** Returns an Viterbi-Object ans create the HMM_Matrix inside and fill
 *  his with the algorithm with values.
 *
 * @p_begin    Prob. for begin with the Fair Coin
 * @p_unfair   Prob. for throw the Unfair Coin
 * @p_change   Prob. for change between Coin{Fair,Unfair}
 * @_sequence  The Coin-Throw sequence Values: Flip{Head, Tail}
 * @return     Viterbi-Object with filled matrix
 * */
Viterbi::Viterbi(double p_begin, double p_unfair, double p_change, vector<Flip> _sequence) {

    // Check Arguments
    if (p_begin < 0.0 || p_begin > 1.0 )   {throw std::invalid_argument("argument p_begin out of range!");  }
    if (p_unfair < 0.0 || p_unfair > 1.0 ) {throw std::invalid_argument("argument p_unfair out of range!"); }
    if (p_change < 0.0 || p_change > 1.0 ) {throw std::invalid_argument("argument p_change out of range!"); }
    if (_sequence.empty())                 {throw std::invalid_argument("argument _sequence is empty!"); }

    // Initialize Fields
    this->p_begin  = p_begin;
    this->p_unfair = p_unfair;
    this->p_change = p_change;
    this->sequence = _sequence;

    // Initialize Matrix

    this->M = Matrix(2,_sequence.size() + 1);

    // Start Algorithm (Fill Matrix)

    std::ostringstream out;
    out.width(5);
    out.precision(4);
    out << 0.34235431;

    //cout << "double formatted: \n" << out.str();

    /*M.setValue(0,0,234234234230.012);
    M.setValue(0,1,0.23445345345345);
    M.setValue(0,2,0.0000012344565453);
    M.setValue(0,3,4);
    M.setValue(0,4,5);

    M.setValue(1,0,6);
    M.setValue(1,1,7);
    M.setValue(1,2,8);
    M.setValue(1,3,9);
    M.setValue(1,4,10);
    */

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
//Matrix Viterbi::getMatrix()      { return M; }
double Viterbi::get_p_begin()    { return p_begin; }
double Viterbi::get_p_unfair()   { return p_unfair; }
double Viterbi::get_p_change()   { return p_change; }
std::vector<Flip> Viterbi::get_Sequence() { return sequence;}
std::vector<Coin> Viterbi::get_Result() { return result;}


#endif //BIOINFOUB10_VITERBI_H
