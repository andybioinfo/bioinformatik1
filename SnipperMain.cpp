//
// Created by manjaro on 21.01.22.
//

#include "Snipper.h"

SingleSNP Snipper::operator[](int idx) const {
    return _snpstack[idx];
}

Classifics &Snipper::getClassifics() {
    return _class;
}

int Snipper::getSNPcount() {
    return _snpstack.size();
}

int Snipper::getGenCount(Genotype gen) {

    int cnt = 0;
    for ( SingleSNP snp : _snpstack ) {

        for (int i = 0 ; i < snp.getSize() ; i++) {
            if (snp[i] == gen) { cnt++; }
        }
    }

    return cnt;
}