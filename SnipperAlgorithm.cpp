//
// Created by manjaro on 21.01.22.
//

#include "Snipper.h"

double Snipper::computeF_shuffling(int shuffles,int snp_idx, double reference_F) {

    // count the matches
    int matches = 0;

    // shuffling the Y-Vector
    for (int sh = 0 ; sh < shuffles ; sh ++) {

            _class.shuffle();

            // compute current Frac
            double new_F = _snpstack[snp_idx].computeF();

            // is the neu value a match?
            if (new_F > reference_F) {matches++;}

    }

    // return the probability of the matches of shuffling
    return (double)matches + 1.0 / (double)shuffles;

}





void Snipper::computeMacaroni(int snp_idx) { // Exercise d)

    // p-value * count Tests
    // reference Frac-Value
    double reference_F = _snpstack[snp_idx].computeF();
    double p_value = Snipper::computeF_shuffling(1000,snp_idx,reference_F);
    double count = _class.count();
    double _p_value = p_value * count;

    // p'value <= 0.05
    if (_p_value <= 0.05) {  }


}

void Snipper::computeFDR() { // Exercise d)

    


}

void Snipper::startAlgorithm() {

    // get the fraction values
    std::vector<double> reference_F;
    for (int snp_id = 0 ; snp_id < getSNPcount() ; snp_id++) {
        // reference Frac-Value
        reference_F.pushback( _snpstack[snp_id].computeF());
    }
    // Shuffle over all SNP's
    for (int snp_id = 0 ; snp_id < getSNPcount() ; snp_id++) {
        //get p-value 
        double p = computeF_shuffling(1000,snp_id,reference_F[snp_id]);
        if(p<=0.05){
            _resultA_p_value.pushback(p);
            _resultA_ref_F.pushback(reference_F[snp_id]);
            _resultA_SNP_id.pushbacl(snp_id);
        }
    }

    // compute


    // compite FDR



}
