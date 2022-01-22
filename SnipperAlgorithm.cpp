//
// Created by manjaro on 21.01.22.
//

#include "Snipper.h"

double Snipper::computeF_shuffling(int shuffles,int snp_idx) {

    // count the matches
    int matches = 0;

    // reference Frac-Value
    double reference_F = _snpstack[snp_idx].computeF();

    // shuffling the Y-Vector
    for (int sh = 0 ; sh < shuffles ; sh ++) {

            _class.shuffle();

            // compute current Frac
            double new_F = _snpstack[snp_idx].computeF();

            // is the neu value a match?
            if (new_F > reference_F) {matches++;}

    }

    // return the probability of the matches of shuffling
    return (double)matches / (double)shuffles;

}





void Snipper::computeMacaroni(int snp_idx) { // Exercise d)

    // p-value * count Tests
    double p_value = Snipper::computeF_shuffling(1000,snp_idx);
    double count = _class.count();
    double _p_value = p_value * count;

    // p'value <= 0.05
    if (_p_value <= 0.05) {  }


}

void Snipper::computeFDR() { // Exercise d)

    


}