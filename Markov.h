#ifndef VITERBI_MARKOV_H
#define VITERBI_MARKOV_H


#include "Coin.h"
#include "Matrix.h"

/** Class for creating markov-matrices for coin
 *  change and production-probabilitys.
 *  (Coin-Only)
 *
 * */
class Markov {

    public:

    // Create markov matrices
    Markov(double p_coinchange, double p_head_fair, double p_head_unfair);

    // Default constructor
    Markov();

    // returns the change-probability from a Fair/Unfair to a Fair/Unfair coin
    double changeProbability(Coin from,Coin to);

    // returns the Flip-probability's with a Fair/Unfair coin to Head or Tail
    double prodProbability(Coin cointype,Flip to);

    // Print both matrices in std::cout for check
    void print_matrices();

    // Set double back in Range
    static double Range(double val);

    // String to Flip-Sequence
    static std::vector<Flip> String2Sequence(string str);

    // Getter for Testing
    Matrix getChangeMatrix();
    Matrix getProductMatrix();

    private:

    Matrix change = Matrix(2,2);   // 0 = Unfair, 1 = Fair
    Matrix product = Matrix(2,2);  // x0 = Tail, x1 = Head ; y0 = Unfair, y1 = Fair

};


#endif //VITERBI_MARKOV_H
