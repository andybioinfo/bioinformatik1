#include "Viterbi.h"

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
 * @decision      The Cointype of the biggest value of max1+2 will return in this list for backtracking
 * @max_fair1     last value
 * @max_fair2     prob. of change
 * @max_unfair1   last value
 * @max_unfair2   prob. of change
 * */
double Viterbi::formula(double p_w_at_coin, double max_fair1, double max_fair2, double max_unfair1, double max_unfair2, vector<Coin>& decision) {

    double a = max_fair1 + log(max_fair2); // fair
    double b = max_unfair1 + log(max_unfair2); // unfair

    if (a > b) {decision.push_back(Fair);} else {decision.push_back(Unfair);}

    double max_value = std::max(a,b);

    return log(p_w_at_coin) + max_value;
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

    this->M = Matrix(2,_sequence.size() );

    // ## Start Algorithm (Fill Matrix)

    // init

    double last_fair   = 0.0; // at row 0 (y = 0)
    double last_unfair = 0.0; // at row 1 (y = 1)
    int actual_column  = 1;
    int max_col        = _sequence.size()-1 ;
    double pw_at_coin = 0.0;
    double max_a1 = 0.0;
    double max_a2 = 0.0;
    double max_b1 = 0.0;
    double max_b2 = 0.0;
    double resA    = 0.0;
    double resB    = 0.0;

    Flip Xi = _sequence[0];

    // column 1

    last_fair   = log(p_begin)     + log(_markov.prodProbability(Fair,Xi));
    last_unfair = log(1.0-p_begin) + log(_markov.prodProbability(Unfair,Xi));

    M.setValue(0,0,last_fair);
    M.setValue(1,0,last_unfair);

    decision_resA.push_back(Fair);
    decision_resB.push_back(Unfair);

    // remaining colums

    while (actual_column <= max_col) { // start next column

        // Flip at Column

        Xi = _sequence[actual_column];

        // row 0 (fair)
        pw_at_coin = _markov.prodProbability(Fair,Xi);
        max_a1     = last_fair;
        max_a2     = _markov.changeProbability(Fair,Fair);
        max_b1     = last_unfair;
        max_b2     = _markov.changeProbability(Unfair,Fair);

        resA       = formula(pw_at_coin,max_a1,max_a2,max_b1,max_b2,decision_resA);

        M.setValue(0,actual_column,resA);

        // row 1 (unfair)
        pw_at_coin = _markov.prodProbability(Unfair,Xi);
        max_a1     = last_fair;
        max_a2     = _markov.changeProbability(Fair,Unfair);
        max_b1     = last_unfair;
        max_b2     = _markov.changeProbability(Unfair,Unfair);

        resB       = formula(pw_at_coin,max_a1,max_a2,max_b1,max_b2,decision_resB);

        M.setValue(1,actual_column,resB);

        // set last values for next column

        last_fair   = resA;
        last_unfair = resB;

        // continue to next column
        actual_column++;;
    }

    printViterbi();

}





/** Backtracking in matrix for create the Result-Sequence of Coin{Fair,Unfair}
 *  for evaluate the Input/Throw-Sequence.
 *
 * @return     nix
 * */
void Viterbi::backtracking() {

    /* let this cat show you, where the most
       likely path is through this matrix

                 (meow!)
         /\_/\   )/
   ((   (=^.^=)
   ))    )   (
    (( /      \    ' '
     (   ) || ||     ' '
     '----''-''-'  >+++°>

    */

    // set the position on end of the input-sequence
    int actual_column = sequence.size() - 1;

    // read first value in the actual column
    double row_A = M.getValue(0,actual_column);

    // read second value in the actual column
    double row_B = M.getValue(1,actual_column);

    // Set row/coin cursor
    Coin actual;
    if (row_A > row_B) { actual = Fair; } else { actual = Unfair; }

    // Start backtracker
    while (actual_column >= 0) { // start at last column and move to first column

        // Add Type to Result-List
        result.push_back(actual);

        // Jump to Cell of the last max of Fair
        if (actual == Fair)   { actual = decision_resA[actual_column];
            actual_column--;
            continue;
        }

        // Jump to Cell of the last max of Unfair
        if (actual == Unfair) { actual = decision_resB[actual_column];
            actual_column--;
            continue;
        }
        actual_column--;
    }

    // reverse the backtracking-list
  /*
    string res = "\n";
    for (Coin f : result) {
        if (f == Fair) {res += "Fair ";}
        if (f == Unfair) {res += "Unfair ";}
    }
    cout << res;
*/
    std::reverse(result.begin(),result.end());

    // ##
/*
    res = "\n";
    for (Coin f : result) {
        if (f == Fair) {res += "Fair ";}
        if (f == Unfair) {res += "Unfair ";}
    }
    cout << res;
*/
}

/** Print the Matrix to console
 *  Value Green = Predecessor ist Fair
 *  Value Green = Predecessor ist Unfair
 * */
void Viterbi::printViterbi() {

    cout << C::BWHITE << "   | Backtracking: " << C::BBLUE << "Value Green: Predecessor is Fair, Value Red: Predecessor is Unfair" ;
    string line1 = "   |";
    string line2 = " F |";
    string line3 = "UF |";
    int pos = 0;
    int max = sequence.size();

    while (pos < max) {

        // create Xi's Strings
        if (sequence[pos] == Tail) {line1 += "     Tail";} else if (sequence[pos] == Head) {line1 += "     Head";} else {line1 += "    Error";}

        // create Fair's Strings
        if (decision_resA[pos] == Fair)  {line2 += C::BGREEN;} else if (decision_resA[pos] == Unfair) {line2 += C::BRED;} else {line2 += C::BWHITE;}
        line2 += Matrix::double2String(M.getValue(0,pos));

        // create Unfair's Strings
        if (decision_resB[pos] == Fair)  {line3 += C::BGREEN;} else if (decision_resB[pos] == Unfair) {line3 += C::BRED;} else {line3 += C::BWHITE;}
        line3 += Matrix::double2String(M.getValue(1,pos));

        // if last :
        if (pos == (max-1)) {
            double row_A = M.getValue(0,pos);
            double row_B = M.getValue(1,pos);
            if (row_A > row_B) { line2 += C::BWHITE;line2 += " <<"; } else { line3 += C::BWHITE;line3 += " <<"; }

        }

        pos++;

    }

    cout << "\n" << C::BWHITE  << line1;
    cout << "\n" << C::BWHITE  << line2;
    cout << "\n" << C::BWHITE  << line3 << "\n\n";
    cout << C::RESET;

}








/** Getter for Testing
 *
 * */
Matrix Viterbi::getMatrix()      { return M; }
double Viterbi::get_p_begin()    { return p_begin; }
std::vector<Flip> Viterbi::get_Sequence() { return sequence;}
std::vector<Coin> Viterbi::get_Result() { return result;}
std::vector<Coin> Viterbi::get_Decision_resA() { return decision_resA;}
std::vector<Coin> Viterbi::get_Decision_resB() { return decision_resB;}
Markov Viterbi::get_markov_matrices() { return _markov;}






