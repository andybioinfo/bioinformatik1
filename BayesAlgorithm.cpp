//
// Created by manjaro on 27.01.22.
//


#include "NaiveBayes.h"
#include "console/console.h"



/** returns the result with "log odd ratio" to calc Cancer or Control
 *
 * @all     The probabilitys for the bayes-formula
 * @return  return Cancer if the result of LOR < 0 otherwise Control
 * */
Classification NaiveBayes::LOR_Formula(double pXiC, double pXiN, double pC, double pN) {
    double res = 0;

    double s1 = log10(pXiC);
    double s2 = log10(pC);
    double s3 = log10(pXiN);
    double s4 = log10(pN);

    s1 == s1 ? res+= s1 : res;
    s2 == s2 ? res+= s2 : res;
    s3 == s3 ? res-= s3 : res;
    s4 == s4 ? res-= s4 : res;

    if (res < 0) {return Control;}
    return Cancer;

}





/** trains the model with the given trainingblocks/data
 *
 * @S               Your complete SNP-Database
 * @trainingblocks  The patient-ids from the training-blocks
 * @result          Filled matrices with prob. values
 * */
void NaiveBayes::train(Snipper& S,std::vector<Block*> trainingblocks ) {

    // Extract patient id's of all blocks
    std::vector<int> patient_ids;
    for (Block* k :trainingblocks) {
        for (int id : k->getBlockPatients()) {
            patient_ids.push_back(id);
        }
    }

    // Classification count for p(C) and p(N) - Matrices
    int snps = patient_ids.size();
    int cancer =  0;
    int control = 0;

    for (int id : patient_ids) { S.getClassifics()[id] == Cancer ? cancer++ : control++; }
    this->M.setPCancer (  (double)cancer  / (double)snps );
    this->M.setPControl(  (double)control / (double)snps );

    // Run over all Xi's for  p(Xi|C) and p(Xi|N) - Matrices
    for (int Xi = 0; Xi < this->X.getSNPcount(); Xi++) {
        // Xi-Variables
        int cancer_homoMJ  = 0;  // Homo Mayor | Cancer
        int cancer_hetero  = 0;  // Hetero     | Cancer
        int cancer_homoMN  = 0;  // Homo Minor | Cancer
        int control_homoMJ = 0;  // Homo Mayor | Control
        int control_hetero = 0;  // Hetero     | Control
        int control_homoMN = 0;  // Homo Minor | Control

        // count all combinations of this Xi over all ids of the trainingblocks
        for (int id : patient_ids) {
            Classification cls = S.getClassifics()[id];
            Genotype gen = S[Xi][id];
            cls == Cancer  && gen == HomoMajor ? cancer_homoMJ++  : cancer_homoMJ;
            cls == Cancer  && gen == Hetero    ? cancer_hetero++  : cancer_hetero;
            cls == Cancer  && gen == HomoMinor ? cancer_homoMN++  : cancer_homoMN;
            cls == Control && gen == HomoMajor ? control_homoMJ++ : control_homoMJ;
            cls == Control && gen == Hetero    ? control_hetero++ : control_hetero;
            cls == Control && gen == HomoMinor ? control_homoMN++ : control_homoMN;
        }

        // set all Values to the matrices of this Xi
        this->M.setGenProbAtXi(Cancer ,HomoMajor,Xi, (double)cancer_homoMJ  / (double)snps );
        this->M.setGenProbAtXi(Cancer ,Hetero   ,Xi, (double)cancer_hetero  / (double)snps );
        this->M.setGenProbAtXi(Cancer ,HomoMinor,Xi, (double)cancer_homoMN  / (double)snps );
        this->M.setGenProbAtXi(Control,HomoMajor,Xi, (double)control_homoMJ / (double)snps );
        this->M.setGenProbAtXi(Control,Hetero   ,Xi, (double)control_hetero / (double)snps );
        this->M.setGenProbAtXi(Control,HomoMinor,Xi, (double)control_homoMN / (double)snps );

    }

}



void NaiveBayes::BayesTrainingsstunde() {

    console C(k_COUNT*10);
    C.startcounter();
    // ### Swap Test-Block k times
    for (int testblock = k_COUNT-1 ; testblock >= 0 ; testblock--) { // Swap Loop

        // ### init loop variables
        int k_id = 0;
        int kt_id = 0;
        this->k_test_actual = testblock;
        vector<int> kids = NaiveBayes::intList(0,10);

        // ### training-data-set
        std::vector<Block*> training_blocks;

        // ### run over all training-Blocks
        for (Block k: k_Blocks) {               // All Blocks Loop
            if (k_id != testblock) {            // is train block
                // add
                training_blocks.push_back(&this->k_Blocks[k_id]);
                // end
                C.stepcounter();
            }
            k_id++;
        }

        // ### start training over all training-blocks

        train(X,training_blocks);

        // ### run over all to find test-Block
        for (Block k: k_Blocks) {               // All Blocks Loop
            if (kt_id == testblock) {           // is test block
                // decrease kids
                kids.erase(kids.begin() + kt_id);
                // testing
                k_Blocks[kt_id].predict(M,X);
                k_Blocks[kt_id].calcStatistics(*this);
                // end
                C.stepcounter();
            }
            kt_id++;
        }

    }

}
