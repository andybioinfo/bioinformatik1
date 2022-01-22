//
// Created by manjaro on 21.01.22.
//

#ifndef SNIPPER_H
#define SNIPPER_H


#include <string>
#include "SingleSNP.h"

class Snipper {

public:

    // Create Snipper without file (for testing)
    Snipper();

    // Create Snipper with file
    Snipper(std::string filename);

    // Get SNP'S
    SingleSNP operator [](int idx) const;

    // add a new SNP-Vector to the array
    Snipper & operator<<(SingleSNP const &s)
    {
        _snpstack.push_back(s);
        return *this;
    }

    // 1000x Shuffle...
    double computeF_shuffling(int shuffles, int snp_idx);

    //
    void computeMacaroni(int snp_idx);

    //
    void computeFDR();

    //
    Classifics& getClassifics();

    // count snips
    int getSNPcount();

    // for Testing (count Genotypes over all SNP's)
    int getGenCount(Genotype gen);

private:

    // List
    std::vector<SingleSNP> _snpstack; //
    Classifics _class;               //
};


#endif //SNIPPER_H
