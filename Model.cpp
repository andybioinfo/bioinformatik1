//
// Created by manjaro on 31.01.22.
//


#include "Model.h"



/** trains the model with the given trainingblocks/data
 *
 * @S               Your complete SNP-Database
 * @trainingblocks  The patient-ids from the training-blocks
 * @result          Filled matrices with prob. values          
 * */
void Model::train(Snipper& S,std::vector<Block> trainingblocks ) {

           // Extract patient id's of all blocks
           std::vector<int> patient_ids;
           for (Block k :trainingblocks) {
             for (int id : k.getBlockPatients()) {
                patient_ids.push_back(id);
             }          
           }

           // Classification count for p(C) and p(N) - Matrices
           int snps = patient_ids.size();
           int cancer =  0;
           int control = 0;

           for (int id : patient_ids) { S.getClassifics()[id] == Cancer ? cancer++ : control++; }
           setPCancer (  (double)cancer  / (double)snps ); 
           setPControl(  (double)control / (double)snps );

           // Run over all Xi's for  p(Xi|C) and p(Xi|N) - Matrices
           for (int Xi = 0; Xi < SNP_COUNT; Xi++) {
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
               this->setGenProbAtXi(Cancer ,HomoMajor,Xi, (double)cancer_homoMJ  / (double)snps );
               this->setGenProbAtXi(Cancer ,Hetero   ,Xi, (double)cancer_hetero  / (double)snps );
               this->setGenProbAtXi(Cancer ,HomoMinor,Xi, (double)cancer_homoMN  / (double)snps );
               this->setGenProbAtXi(Control,HomoMajor,Xi, (double)control_homoMJ / (double)snps );
               this->setGenProbAtXi(Control,Hetero   ,Xi, (double)control_hetero / (double)snps );
               this->setGenProbAtXi(Control,HomoMinor,Xi, (double)control_homoMN / (double)snps );

           }

}