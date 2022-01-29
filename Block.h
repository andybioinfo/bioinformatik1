//
// Created by manjaro on 28.01.22.
//

#ifndef BAYES_BLOCK_H
#define BAYES_BLOCK_H

/*

This Class is a Single k-Block:

Yi	Ypredict  *Ytruestates	*X1	*X2	*X3
____|________|______________|___|___|___
Y14	|	?	 |	Cancer		| 1 | 0	| 2
Y19	|	?	 |	Control		| 1 | 0	| 2
Y6	|	?	 |	Cancer		| 1 | 0	| 2
Y1	|	?	 |	Cancer		| 0 | 1	| 2
Y11	|	?	 |	Cancer		| 1 | 0	| 2

 # Yi            : is the row_id or Patient_id from the Input-SNP-File

 # Ypredict      : the calculated prediction

 # Ytruestates   : is the Y-Vector of the Input-SNP-File   (pointered)

 # Xi            : are the X-Vectors of the Input-SNP-File (pointered)

___________________________________________________________________________________

 ### Methods:

 static K_Fold Splitter(Snipper& S, int count)  => Create a Vector of k-Blocks with size 'count'

 void trainBlock ()                             => trains all patients in this block

 void testing ()                                => compare between Ypredict and Ytruestate

*/

#include <vector>
#include <random>
#include <algorithm>
#include <sstream>
#include <iostream>
#include "snipper/Snipper.h"
#include "console/Color.h"


class NaiveBayes;

class Block {

public:

    using K_Fold = std::vector<Block>;

    // Constructor

    explicit Block(Snipper& S,int id);

    // Methods

    static K_Fold Splitter(Snipper& S, int count);
    void trainBlock (NaiveBayes NB);
    void testing (NaiveBayes &NB, const std::vector<int>& trainings_block_ids );

    // Setter

    void addPatient(int id) {patient.push_back(id);predictions.push_back(Unknown);}

    // Getter

    std::vector<Classification> getBlockPredictions() {return predictions;}
    std::vector<int>    getBlockPatients()    {return patient;}
    [[nodiscard]] int size() const {return (int)patient.size();} // count of patients in this list
    void print();
    int getID() {return kid;}

private:

std::vector<Classification> predictions; // List of predictions  ( Ypredict's )
std::vector<int> patient;                // List of patients     ( Yi's )
Snipper S;
int kid = -1;

};


#endif //BAYES_BLOCK_H
