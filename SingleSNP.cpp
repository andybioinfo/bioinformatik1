//
// Created by manjaro on 21.01.22.
//

#include "SingleSNP.h"

SingleSNP::SingleSNP(Classifics &_clss) {
 this->_class = &_clss;
}

Genotype SingleSNP::operator[](int idx) const {
    return _snp[idx];
}

int SingleSNP::getSize() {
    return _snp.size();
}

Classification SingleSNP::getClassificationAt(int pos) {
    return (*_class)[pos];
}

void SingleSNP::computeF() {


 for (Genotype g : _snp) {

     double res = fracFormula();
     _frac.push_back(res);


 }

 //_snp;

 // Y-Vector:

 //_class;

 // return:

 // frac;

}

double SingleSNP::fracFormula() {

    return 0;
}
