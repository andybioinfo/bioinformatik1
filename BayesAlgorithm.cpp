//
// Created by manjaro on 27.01.22.
//


#include "NaiveBayes.h"

void NaiveBayes::BayesTrainingsstunde() {


    // ### Swap Test-Block k times
    for (int testblock = k_COUNT-1 ; testblock >= 0 ; testblock--) { // Swap Loop

        // ### init loop variables
        int k_id = 0;
        int kt_id = 0;
        vector<int> kids = NaiveBayes::intList(0,10);


        // ### run over all training-Blocks
        for (Block k: k_Blocks) {               // All Blocks Loop
            if (k_id != testblock) {            // is train block
                // train
                this->k_Blocks[k_id].trainBlock(*this);
                // end
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
            }
            kt_id++;
        }

    }

}
