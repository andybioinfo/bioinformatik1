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
    return (double)( matches + 1 ) / (double)shuffles;

}





double Snipper::computeBonferroni(double p_value) { // Exercise d)
    //p-value * Snp anzahl
    return p_value*100.0;
}

double Snipper::computeFDR(double p_value) { // Exercise d)

    return 1.0;


}

void Snipper::startAlgorithm() {

    // get the fraction values
    std::vector<double> reference_F;
    for (int snp_id = 0 ; snp_id < getSNPcount() ; snp_id++) {
        // reference Frac-Value
        reference_F.push_back( _snpstack[snp_id].computeF());
    }
    // Shuffle over all SNP's
    for (int snp_id = 0 ; snp_id < getSNPcount() ; snp_id++) {
        //get p-value 
        double p = computeF_shuffling(1000,snp_id,reference_F[snp_id]);
        if(p<=0.05){
            _resultA_p_value.push_back(p);
            _resultA_ref_F.push_back(reference_F[snp_id]);
            _resultA_SNP_id.push_back(snp_id);
        }

        // Adjustierung
        double p_ad = computeBonferroni(p);
        double p_ad2 = computeFDR(p_ad);
        if(p_ad2<=0.05){
            _resultB_p_value.push_back(p_ad2);
            _resultB_ref_F.push_back(reference_F[snp_id]);
            _resultB_SNP_id.push_back(snp_id);
        }
    }

    // compute


    // compite FDR



}
