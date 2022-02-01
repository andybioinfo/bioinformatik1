//
// Created by manjaro on 28.01.22.
//

#ifndef BAYES_BLOCK_H
#define BAYES_BLOCK_H

#include <vector>
#include <random>
#include <algorithm>
#include <sstream>
#include <iostream>
#include "NaiveBayes.h"
#include "Model.h"

class Block {

public:

    using K_Fold = std::vector<Block>;

    // Constructor

    explicit Block(Snipper& S,int id);

    // Methods

    static K_Fold Splitter(Snipper& S, int count);
    void predict (Model& M, Snipper& S);
    void calcStatistics(NaiveBayes& NB);

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
