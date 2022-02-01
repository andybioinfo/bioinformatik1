//
// Created by manjaro on 27.01.22.
//

#ifndef BAYES_H
#define BAYES_H

#include <stdexcept>
#include <vector>
#include <iostream>
#include "Block.h"
#include "Statistics.h"
#include "Model.h"


/** Bayes
 *
 *
 * */
class NaiveBayes {

public:

    // #### BayesAlgorithm ####

        // Algorithm Complete
        void BayesTrainingsstunde();

        // Log Odd Ratio Formula
        static Classification LOR_Formula(double pXiC, double pXiN, double pC, double pN);

    // #### BayesFile ####

        // Statistic-Output
        void outputFile(std::string output_file);


    // #### BayesMain ####

        // Constructor
        using K_Fold = std::vector<Block>;
        NaiveBayes(Snipper XY, int k_divisions);

        // Helper
        static std::vector<int> intList(int start,int end);

        // Getter
        [[nodiscard]] int get_k_SIZE() const;
        [[nodiscard]] int get_k_COUNT() const;
        Snipper getSNPs();
        Statistics &getStats();
        std::vector<Block> &getK_Blocks();
        //Matrix getMatrixM_Ctl();


private:

// Tables:
    Model M;
    
// The SNPs
Snipper X;
Statistics stats;
K_Fold k_Blocks;

int k_SIZE;
int k_TEST;
int k_COUNT;
int k_test_actual;

};



#endif //BAYES_H



