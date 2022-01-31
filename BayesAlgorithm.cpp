//
// Created by manjaro on 27.01.22.
//


#include "NaiveBayes.h"
#include "console/console.h"


/** returns the result from log odd with Cancer or Control
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

    if (res < 0) {return Cancer;}
    return Control;

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

        M.train(X,training_blocks);

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
