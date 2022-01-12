
#include "Markov.h"

/** set the value back in Range if it over 1.0 or under 0.0
 *
 * @val     value
 * @return  value in Range
 * */
double Markov::Range(double val) {
    if (val > 1.0) { return 1.0; }
    if (val < 0.0) { return 0.0; }
    return val;
}


/** Create from a String for every char { '0' -> Tail , '1' -> Head }
 *  a Vector of Flips. It returns an empty Vector if an wrong char in the String.
 *
 * @str     a string in format "101001"
 * @return  vector-list of Flip { Head , Tail}
 * */
std::vector<Flip> Markov::String2Sequence(string str) {
    std::vector<Flip> seq;
    for ( char& c : str) {
        // 0 is Tail
        if (c == '0') { seq.push_back(Tail); continue; }
        // 1 is Head
        if (c == '1') { seq.push_back(Head); continue; }
        // other char = return empty List
        seq.clear();
        break;
    }
    return seq;
}




/** returns the change-probability from a Fair/Unfair to a Fair/Unfair coin
 *
 * @from   Fair or Unfair coin
 * @to     Fair or Unfair coin
 * @return resulting probability of this change
 * */
double Markov::changeProbability(Coin from, Coin to) {

    // 0 = Unfair, 1 = Fair
    switch (from) {
        case Fair   : // from Fair
            switch (to) {
                case Fair   : return change.getValue(1,1);
                case Unfair : return change.getValue(1,0);
            }
            break;
        case Unfair : // from Unfair
            switch (to) {
                case Fair   : return change.getValue(0,1);
                case Unfair : return change.getValue(0,0);
            }
            break;
    }

    return -1;
}




/** returns the Flip-probability's with a Fair/Unfair coin to Head or Tail
 *
 * @cointype   with a Fair or Unfair coin?
 * @to         throw Head or Tail?
 * @return     resulting FLip-probability of this throw
 * */
double Markov::prodProbability(Coin cointype, Flip to) {

    // x0 = Tail, x1 = Head ; y0 = Unfair, y1 = Fair
    switch (cointype) {
        case Fair   : // from Fair
            switch (to) {
                case Tail   : return product.getValue(1,0);
                case Head   : return product.getValue(1,1);
            }
            break;
        case Unfair : // from Unfair
            switch (to) {
                case Tail   : return product.getValue(0,0);
                case Head   : return product.getValue(0,1);
            }
            break;
    }

    return -1;
}





Markov::Markov(double p_coinchange, double p_head_fair, double p_head_unfair) {

    // Create the matrix-values and set in Range
    double _change = Range(p_coinchange);
    double _same   = 1.0 - _change;

    double _fair_head   = Range(p_head_fair);
    double _fair_tail   = 1.0 - _fair_head;
    double _unfair_head = Range(p_head_unfair);
    double _unfair_tail = 1.0 - _unfair_head;

    // Create change matrix
    // 0 = Unfair, 1 = Fair
    this->change.setValue(1,1,_same);
    this->change.setValue(1,0,_change);
    this->change.setValue(0,1,_change);
    this->change.setValue(0,0,_same);

    // Create production matrix
    // x0 = Tail, x1 = Head ; y0 = Unfair, y1 = Fair
    this->product.setValue(1,0,_fair_tail);
    this->product.setValue(1,1,_fair_head);
    this->product.setValue(0,0,_unfair_tail);
    this->product.setValue(0,1,_unfair_head);


}





/** Print both matrices to console (std::cout)
 *  for check all matrix-values
 *
 * */
void Markov::print_matrices() {

    char RESET[]   = "\033[0m";
    char BBLUE[]   = "\033[1;34m";
    char BWHITE[]  = "\033[1;37m";
    char RED[]     = "\033[0;31m";
    char BYELLOW[] = "\033[1;33m";

    std::cout << BWHITE << "\n | Markov - Change-Matrix" << BBLUE; // 0 = Unfair, 1 = Fair
    std::cout << RED    << "\n | Fair   -> Fair   : " << BYELLOW << change.getValue(1,1);
    std::cout << RED    << "\n | Fair   -> Unfair : " << BYELLOW << change.getValue(1,0);
    std::cout << RED    << "\n | Unfair -> Fair   : " << BYELLOW << change.getValue(0,1);
    std::cout << RED    << "\n | Unfair -> Unfair : " << BYELLOW << change.getValue(0,0) << "\n";

    std::cout << BWHITE << "\n | Markov - Production-Matrix" << BBLUE; // x0 = Tail, x1 = Head ; y0 = Unfair, y1 = Fair
    std::cout << RED    << "\n | Fair   -> Head   : " << BYELLOW << product.getValue(1,1);
    std::cout << RED    << "\n | Fair   -> Tail   : " << BYELLOW << product.getValue(1,0);
    std::cout << RED    << "\n | Unfair -> Head   : " << BYELLOW << product.getValue(0,1);
    std::cout << RED    << "\n | Unfair -> Tail   : " << BYELLOW << product.getValue(0,0) << RESET << "\n";

}


/** Default Constructor
 *
 * */
Markov::Markov() {

}


/** (Getter for Testing) -> returns the change Matrix
 *
 * */
Matrix Markov::getChangeMatrix()      { return change; }


/** (Getter for Testing) -> returns the product Matrix
 *
 * */
Matrix Markov::getProductMatrix()      { return product; }
