//
// Created by manjaro on 27.01.22.
//


#include "NaiveBayes.h"



NaiveBayes::NaiveBayes(Snipper XY, int k_divisions) {

    // ## get and check arguments
    int cols    = XY.getSNPcount();
    if (k_divisions < 1 )       { throw std::invalid_argument("your count of divisions is too small! Expected >= 1"); }
    if (cols < 1 )              { throw std::invalid_argument("You need at least one SNP in your database. Please ask your patients for a medical Sample"); }
    if (XY[0].getSize() < 10 )  { throw std::invalid_argument("You cannot do a 10-Fold on less than 10 Patients, or cut your patients in pieces to reach 10 :D "); }
    int rows = XY[0].getSize();
    if (k_divisions > rows) { k_COUNT = rows; } else { k_COUNT = k_divisions; }


    // ## Create Fields
    this->X  = XY;
    k_COUNT = k_divisions;
    k_SIZE  = X[0].getSize() / k_COUNT;
    k_TEST = k_SIZE-1;
    this->stats = Statistics();

    // ## Create K-Fold
    this->k_Blocks = Block::Splitter(XY,k_divisions);

    // ## Create Tables
    this->M = Model(XY.getSNPcount());


}











int NaiveBayes::get_k_SIZE() const      {return k_SIZE;}
int NaiveBayes::get_k_COUNT() const     {return k_COUNT;}
Snipper NaiveBayes::getSNPs()     {return X;}
Statistics& NaiveBayes::getStats() {return stats;}
std::vector<Block>& NaiveBayes::getK_Blocks() { return k_Blocks; }

std::vector<int> NaiveBayes::intList(int start, int end) {

    std::vector<int> n;
    for (int i = start; i < end ; i++) {n.push_back(i);}
    return n;
}


