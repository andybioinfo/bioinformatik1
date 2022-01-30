//
// Created by manjaro on 27.01.22.
//


#include "NaiveBayes.h"


double NaiveBayes::BayesFormula(Classification posterior) {




}



/** P(X|C) = product98 ( P(Xi|C) )
 *
 * */
double NaiveBayes::ProductSNPFormula(Genotype gen, Classification cls) {

double res = 0.0;
int snpcnt = X.getSNPcount();

// Extract patient ids of all current training-blocks
int kid = 0;
std::vector<int> pids;

for (Block k : k_Blocks) {

    if (k.getID != k_test_actual) {
        for (int id : k.getBlockPatients) {
            pids.push_back(id);
        }
    }
    kid++;
}



// Product

for (int i = 0 ; i < snpcnt ; i++) {





    
}
return res;
}


/** write Tables
 *
 * */
void NaiveBayes::train(int patient_id) {

double val = 0.0;

  // Table Xi Cancer

       /* Hz Major | C */


M_Cancer.setValue(0,patient_id,val);
       /* Hetero   | C */

M_Cancer.setValue(1,patient_id,val);
       /* Hz Minor | C */
  
M_Cancer.setValue(2,patient_id,val);

  // Table Xi Control

       /* Hz Major | N */

M_Control.setValue(0,patient_id,val);
       /* Hetero   | N */

M_Control.setValue(1,patient_id,val);
       /* Hz Minor | N */

M_Control.setValue(2,patient_id,val);


}






/** returns for patient X (patient_id) the log odd ratio of Cancer / Control
 *
 * @patient_id     Patient to predict the classification
 * @return         Type of Classification
 * */
Classification NaiveBayes::predict(int patient_id) {

        Classification predict;

    // calc values

        double pC_X = 0;

        double pN_X = 0;

        double LOR = log ( pC_X / pN_X );

    // if LOR < 0 then Control otherwise Cancer

        LOR < 0 ? predict = Control : predict = Cancer; 

        return predict;

}






void NaiveBayes::BayesTrainingsstunde() {


    // ### Swap Test-Block k times
    for (int testblock = k_COUNT-1 ; testblock >= 0 ; testblock--) { // Swap Loop

        // ### init loop variables
        int k_id = 0;
        int kt_id = 0;
        this->k_test_actual = testblock;
        vector<int> kids = NaiveBayes::intList(0,10);


        // ### run over all training-Blocks
        for (Block k: k_Blocks) {               // All Blocks Loop
            if (k_id != testblock) {            // is train block
                // train
                this->k_Blocks[k_id].trainBlock(*this);
                // end
                C.stepcounter();
            }
            k_id++;
        }


        // ### run over all to find test-Block
        for (Block k: k_Blocks) {               // All Blocks Loop
            if (kt_id == testblock) {           // is test block
                // decrease kids
                kids.erase(kids.begin() + kt_id);
                // testing
                k_Blocks[kt_id].testing(*this,kids);
                // end
                C.stepcounter();
            }
            kt_id++;
        }

    }

}
