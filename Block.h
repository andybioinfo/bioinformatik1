//
// Created by manjaro on 28.01.22.
//

#ifndef BAYES_BLOCK_H
#define BAYES_BLOCK_H

/*

This Class is a Single k-Block: ( can train or tested )

Yi   Ypredict  *Ytruestates  *X1 *X2 *X3
____|________|______________|___|___|___
Y14 |   ?    | Cancer       | 1 | 0 | 2
Y19 |   ?    | Control      | 1 | 0 | 2
Y6  |   ?    | Cancer       | 1 | 0 | 2
Y1  |   ?    | Cancer       | 0 | 1 | 2
Y11 |   ?    | Cancer       | 1 | 0 | 2

 # Yi            : is the row_id or Patient_id from the Input-SNP-File

 # Ypredict      : the calculated prediction               (use the predict method to compute)

 # Ytruestates   : is the Y-Vector of the Input-SNP-File   (pointered from SNP-Database, use [patient-list] for id )

 # Xi            : are the X-Vectors of the Input-SNP-File (pointered from SNP-Database, use [patient-list] for id )

___________________________________________________________________________________


*/

#include <vector>
#include <random>
#include <algorithm>
#include <sstream>
#include <iostream>
#include "snipper/Snipper.h"
#include "console/Color.h"
#include "Model.h"


class NaiveBayes;

class Block {

public:

    using K_Fold = std::vector<Block>;

    // Constructor

    explicit Block(Snipper& S,int id) {
        this->S = S;
        this->kid = id;
        }

    // Methods

    static K_Fold Splitter(Snipper &S, int count, bool shuffle_patient_list);
    void predict (Model& M, Snipper& S);
    void calcStatistics(NaiveBayes& NB);

    // Setter

    void addPatient(int id)         {patient.push_back(id);predictions.push_back(Unknown);}

    // Getter

    std::vector<Classification> getBlockPredictions()   {return predictions;}
    std::vector<int>            getBlockPatients()      {return patient;}
    [[nodiscard]] int size() const                      {return (int)patient.size();} // count of patients in this list
    int getID()                                         {return kid;}

    // Print to console
    void print() {
    std::stringstream s("");

        s << C::BWHITE <<"\n K-Block id:"<<kid<<" size: "<< C::BBLUE << patient.size()  
          << C::BRED << " [ *SNPs: " << S.getSNPcount() << " Pat: " 
          << S.getClassifics().count() << " ]";
        s << C::BWHITE << " Pat(true->pred): { ";
        int idx = 0;
        for (int pat : patient ) {
            std::stringstream pre("");
            Classification trueS = S.getClassifics()[pat];
            Classification preS  = predictions[idx];
            pre << "t " << trueS << " -> " << preS;

            s << C::BBLUE << pat << C::BCYAN << " (" << pre.str() << ") ";
            if (idx != (int)patient.size() - 1) {s << "; ";}
            idx++; }
        s << C::BWHITE << "} ";
        std::cout << s.str() << C::RESET;
    }



private:

std::vector<Classification> predictions; // List of predictions  ( Ypredict's )
std::vector<int> patient;                // List of patients     ( Yi's )
Snipper S;
int kid = -1;

};


#endif //BAYES_BLOCK_H
