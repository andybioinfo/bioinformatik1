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

    // SNP Start

    void startAlgorithm();

    // 1000x Shuffle...
    double computeF_shuffling(int shuffles, int snp_idx, double reference_F);

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

    std::vector<SingleSNP> _snpstack; // SNP-Stack
    Classifics _class;               // classifications
    
    std::vector<double> _resultA_p_value; // Exercise c)
    std::vector<double> _resultA_ref_F;
    std::vector<int>    _resultA_SNP_id;
    std::vector<double> _resultB_p_value; // Exercise d)
    std::vector<double> _resultB_ref_F; 
    std::vector<int>    _resultB_SNP_id;
    

};


#endif //SNIPPER_H
