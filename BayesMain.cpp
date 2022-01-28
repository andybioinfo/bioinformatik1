//
// Created by manjaro on 27.01.22.
//

#include "NaiveBayes.h"


NaiveBayes::NaiveBayes(Snipper XY, int k_divisions) {

    // ## get and check arguments
    int cols    = XY.getSNPcount();
    if (k_divisions < 1 )     { throw std::invalid_argument("your count of divisions is too small! Expected >= 1 but was: '" << k_divisions << "'"); }
    if (cols < 1 )            { throw std::invalid_argument("your count of SNP's is zero! Expected >= 1 but was: '" << cols << "'"); }
    if (X[0].getSize() < 1 )  { throw std::invalid_argument("your count of patients is zero! Expected >= 1 but was: '" << X[0].getSize() << "'"); }
    int rows = X[0].getSize();
    if (k_divisions > rows) { k_COUNT = rows; } else { k_COUNT = k_divisions; }
    this.X  = XY;
    k_COUNT = k_divisions;
    k_SIZE  = X[0].getSize() / k_COUNT;
    k_TEST = k_SIZE-1;

}



int NaiveBayes::get_k_SIZE()      {return k_SIZE;}
int NaiveBayes::get_k_COUNT()     {return k_COUNT;}
Snipper NaiveBayes::getSNPs()     {return X;}
Statistics NaiveBayes::getStats() {return stats;}

