//
// Created by manjaro on 21.01.22.
//

#include "Snipper.h"

double Snipper::computeF_all(int shuffles) {

    int matches = 0;

    for (SingleSNP snp : _snpstack) {

        double reference_F = snp.computeF();
        for (int sh = 0 ; sh < shuffles ; sh ++) {
            _class.shuffle();
            double new_F = snp.computeF();
            if (new_F > reference_F) {matches++;}

        }

    }

    return (double)matches / (double)shuffles;

}

void Snipper::computeMacaroni() {

}

void Snipper::computeFDR() {

}