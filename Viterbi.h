#ifndef BIOINFOUB10_VITERBI_H
#define BIOINFOUB10_VITERBI_H

#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include "Coin.h"
#include "console.h"
#include "Matrix.h"
#include "Markov.h"
#include "Color.h"

using namespace std;


class Viterbi {
public:
    // Create HMM
    Viterbi(Markov _markov,double p_begin, vector<Flip> _sequence);

    // matrix calculate formula
    static double formula(double p_w_at_coin,double max_fair1, double max_fair2, double max_unfair1, double max_unfair2, vector<Coin>& decision);

    // Backtracking
    void backtracking();

    // Getter for Testing
    Matrix getMatrix();
    double get_p_begin();
    Markov get_markov_matrices();
    std::vector<Flip> get_Sequence();
    std::vector<Coin> get_Result();
    std::vector<Coin> get_Decision_resA();
    std::vector<Coin> get_Decision_resB();

    // Create Result-String for Console Output
    string Sequence_toString(bool with_result);

    //print Viterbi 
    void printViterbi();
    
private:
    Matrix M = Matrix(0, 0);
    Markov _markov;
    double p_begin;
    std::vector<Flip> sequence;
    std::vector<Coin> result;
    std::vector<Coin> decision_resA;
    std::vector<Coin> decision_resB;
};


#endif //BIOINFOUB10_VITERBI_H
