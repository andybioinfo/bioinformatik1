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
#include "matrix/Matrix.h"



/** Bayes
 *
 *
 * */
class NaiveBayes {

public:

    // #### BayesAlgorithm ####

        // Algorithm Complete
        void BayesTrainingsstunde();

        // prediction
        Classification predict(int patient_id); 

        // train
        void train(int patient_id); 

        // train
        double BayesFormula(Classification posterior); 

        double ProductSNPFormula(Genotype gen, Classification cls);

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
        Matrix getMatrixM_Ctl();
        Matrix getMatrixM_Ccr();
        Matrix getMatrixM_pCtl();
        Matrix getMatrixM_pCcr();

private:
    
// Tables:
Matrix M_Control    = Matrix(1,1); // y = rows (Genotypes ; x = Xi's
Matrix M_Cancer     = Matrix(1,1); // y = rows (Genotypes ; x = Xi's
Matrix M_p_Control  = Matrix(1,1);
Matrix M_p_Cancer   = Matrix(1,1);
    
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



