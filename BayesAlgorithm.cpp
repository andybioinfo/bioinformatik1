//
// Created by manjaro on 27.01.22.
//


#include "NaiveBayes.h"
#include "console/console.h"


double NaiveBayes::BayesFormula(Classification posterior) {

return 0;
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
            if (k.getID() != k_test_actual) {
                for (int id : k.getBlockPatients()) {
                    pids.push_back(id);
                }
            }
            kid++;
        }

    // Product over all SNPs
        int countpat = pids.size();
        int countXiC = 0;
        double probability = 1;
        for (int Xi = 0 ; Xi < snpcnt ; Xi++) { // SNP Xi

            int countXiC = 0;

            for (int Yi : pids ) { // all patients in TrainData

                if (X.getClassifics()[Yi] == cls && X[Xi][Yi] == gen) {countXiC++;}

                }

            probability *= ((double)countXiC / (double)countpat);
        }

        return probability;
     }





/** write both Tables
 *
 * */
void NaiveBayes::train(int patient_id) {

double val = 0.0;
int pid = patient_id;
if (patient_id >= X.getClassifics().count()) {pid = 0;}

  // Table Xi Cancer

       /* Hz Major | C */
       val = ProductSNPFormula(HomoMajor, Cancer);
       //M_Cancer.setValue(0,pid,val);

       /* Hetero   | C */
       val = ProductSNPFormula(Hetero,Cancer);
       //M_Cancer.setValue(1,pid,val);

       /* Hz Minor | C */
       val = ProductSNPFormula(HomoMinor, Cancer);
       //M_Cancer.setValue(2,pid,val);

  // Table Xi Control

       /* Hz Major | N */
       val = ProductSNPFormula(HomoMajor, Control);
       //M_Control.setValue(0,pid,val);

       /* Hetero   | N */
       val = ProductSNPFormula(Hetero, Control);
       //M_Control.setValue(1,pid,val);

       /* Hz Minor | N */
       val = ProductSNPFormula(HomoMinor, Control);
       //M_Control.setValue(2,pid,val);

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

    console C(k_COUNT*10);
    C.startcounter();
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
