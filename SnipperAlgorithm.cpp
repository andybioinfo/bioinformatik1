//
// Created by manjaro on 21.01.22.
//

#include "Snipper.h"

void Snipper::computeF_all() {

    for (SingleSNP snp : _snpstack) {

        snp.computeF();

    }

}

void Snipper::computeMacaroni() {

}

void Snipper::computeFDR() {

}