//
// Created by manjaro on 21.01.22.
//

#include "Snipper.h"


/** returns a single SNP via []-Operator
 *
 * */
SingleSNP Snipper::operator[](int idx) const {
    return _snpstack[idx];
}


/** returns the Y-Vector of this class
 *
 * */
Classifics &Snipper::getClassifics() {
    return _class;
}


/** counts all SNP's in this class
 *
 * */
int Snipper::getSNPcount() {
    return _snpstack.size();
}


/** for Testing (count Genotypes over all SNP's)
 *
 * @gen     genotype
 * */
int Snipper::getGenCount(Genotype gen) {

    int cnt = 0;
    for ( SingleSNP snp : _snpstack ) {

        for (int i = 0 ; i < snp.getSize() ; i++) {
            if (snp[i] == gen) { cnt++; }
        }
    }

    return cnt;
}

