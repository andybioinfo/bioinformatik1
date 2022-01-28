//
// Created by manjaro on 27.01.22.
//

#include <stdexcept>
#include "NaiveBayes.h"
#include "snipper/Snipper.h"


NaiveBayes::NaiveBayes(Snipper XY, int k_divisions) {

    // ## get and check arguments
    int cols    = XY.getSNPcount();
    if (k_divisions < 1 )     { throw std::invalid_argument("your count of divisions is too small! Expected >= 1 but was: '"); }
    if (cols < 1 )            { throw std::invalid_argument("your count of SNP's is zero! Expected >= 1 but was: '"); }
    if (XY[0].getSize() < 1 )  { throw std::invalid_argument("your count of patients is zero! Expected >= 1 but was: '"); }
    int rows = XY[0].getSize();
    if (k_divisions > rows) { k_COUNT = rows; } else { k_COUNT = k_divisions; }

    // ## Create Fields
    this->X  = XY;
    k_COUNT = k_divisions;
    k_SIZE  = X[0].getSize() / k_COUNT;
    k_TEST = k_SIZE-1;
    this->stats = Statistics();

    // ## Create Empty k-Blocks
    for (int i = 0 ; i < k_COUNT ; i++) {
        Block K;
        k_Blocks.push_back(K);
    }



}



int NaiveBayes::get_k_SIZE() const      {return k_SIZE;}

int NaiveBayes::get_k_COUNT() const     {return k_COUNT;}

Snipper NaiveBayes::getSNPs()     {return X;}

Statistics& NaiveBayes::getStats() {return stats;}

std::vector<Block> NaiveBayes::getK_Blocks() { return k_Blocks; }

