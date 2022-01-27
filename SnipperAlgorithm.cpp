//
// Created by manjaro on 21.01.22.
//

#include "Snipper.h"
#include <bits/stdc++.h>


/** Compute the F-Value of this SNP with shuffling
 *
 * @shuffles     how many shuffles of this SNP
 * @snp_idx      the index of this SNP
 * @reference_F  the reference F-Value
 * @return       F-Value
 * */
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




/** compute Bonferroni
 *
 * */
double Snipper::computeBonferroni(double p_value) { // Exercise d)
    //p-value * Snp anzahl
    return p_value*100.0;
}


/** compute FDR
 *
 * */
double Snipper::computeFDR(std::vector<double> p_values) { // Exercise d)
    // sortieren
    sort(p_values.begin(), p_values.end());
    for (auto x : p_values){
         std::cout << x << " " ;
    }
    
    // (rang / p-value) * False Discovery Rate (0.05)
    std::vector<double> BH;
    double rang = 0.0;
    for (auto p : p_values){
        BH.push_back((rang/p)*0.05);
        rang += 1.0;
    }
    return 1.0;


}

/** Starts the algorithm for all computation-Steps
 *  and write the results in the result-arrays in this class
 *
 * */
void Snipper::startAlgorithm() {

    // get the fraction values
    std::vector<double> reference_F;
    std::vector<double> adj_p_values;
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

        // Adjustierung Bonferroni
        adj_p_values.push_back(computeBonferroni(p));
        
    }
    // compute FDR

/*
double p_ad2 = computeFDR(p_ad);
        if(p_ad2<=0.05){
            _resultB_p_value.push_back(p_ad2);
            _resultB_ref_F.push_back(reference_F[snp_id]);
            _resultB_SNP_id.push_back(snp_id);
        }
*/
}
