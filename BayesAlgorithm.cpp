//
// Created by manjaro on 27.01.22.
//

#include <iostream>
#include "NaiveBayes.h"
#include "snipper/Classifics.h"
#include "snipper/Snipper.h"
#include "console/Color.h"


/*
void NaiveBayes::train(const Snipper &X, const Classifics &Y) {

}

Classifics NaiveBayes::predict(const Snipper &X) const {
    return ;
}

*/



void NaiveBayes::BayesTrainingsstunde() {

    // ## Fill all k-Blocks with patients
    int _block = 0;
    for (Block k : k_Blocks) { // all k-Blocks
        for (int i = 0 ; i < k_SIZE ; i++) {
            k.interval.push_back( i + _block * k_SIZE);
        }
        _block++; // next block id
    }

    std::cout << "\n Blocks: " << k_COUNT << "\n";
    // ## Test-Block-Moves
    //
    for (int testblock = k_COUNT-1 ; testblock >= 0 ; testblock--) { // repeat every Block-Move ( k moves )
        std::cout << C::BLUE << "\n :: Testblock Move => Testblock at " << testblock << "\n"<< C::RESET;
        // ## Run over all k-Blocks from 0 to k
        //
        int k_id = 0;
        for (Block k: k_Blocks) { // all k-Blocks

            // k-Block is testing Block?
            //
            if (k_id == testblock) { std::cout << C::BGREEN << " Test(" << k_id << ") "<< C::RESET;
                // testblock-Algorithm
                for (int id : k.interval) {
                    //X.getClassifics()[id] /*Test*/
                }
                k.tested = true;

            }

            // k-Block is training Block?
            //
            if (k_id != testblock) { std::cout << C::BCYAN << "Train(" << k_id << ") "<< C::RESET;
                // training-Algorithm
                for (int id : k.interval) {
                    //X.getClassifics()[id] /*Training*/
                }
            }
            // ##
            k_id++;
            
            // calculation of statistics of this k
            
            double TP = 0.3;
            double FP = 0.3;
            double TN = 0.3;
            double FN = 0.3;/*
            
            double ac = Accuracy( TP,  TN,  FP,  FN);
            double se = Sensitivity( TN,  FP);
            double sp = Specificity( TP,  FN);
            double pr = Precision( TP,  FP);
            double f1 = F1Score( pr,  se);
            double av = Average(std::vector<double> list);
            double dv = Standard_deviation(std::vector<double> Xi,std::vector<double> pXi);
            
            stats.addStatsSet(ac,se,sp,pr,f1,av,dv);*/

        }

    }

    std::cout << C::BLUE << "\n :: Algorithm finish \n"<< C::RESET;
    // ## Create Statistic after algorithm


    // Provisorisch zum Testen des Output

    stats.addStatsSet(0,20,80,40,20,10,60);
    stats.addStatsSet(2,20,80,40,20,10,60);
    stats.addStatsSet(2,20,80,40,20,10,60);
    stats.addStatsSet(0,20,80,40,20,10,60);
    stats.addStatsSet(1,20,80,40,20,10,60);

    stats.addStatsSet(0,20,80,40,20,10,60);
    stats.addStatsSet(0,20,80,40,20,10,60);
    stats.addStatsSet(0,20,80,40,20,10,60);
    stats.addStatsSet(0,20,80,40,20,10,60);
    stats.addStatsSet(0,20,80,40,20,10,60);


}
