//
// Created by manjaro on 21.01.22.
//

#ifndef SNIPPER_H
#define SNIPPER_H


#include <string>
#include "SingleSNP.h"

class Snipper {

public:

    // ### SnipperFile ###

        // Create Snipper without file (for testing)
        Snipper();

        // Create Snipper with file
        Snipper(std::string filename);

        // add a new SNP-Vector to the array
        Snipper & operator<<(SingleSNP const &s)
        {
            _snpstack.push_back(s);
            return *this;
        }


    // ### SnipperAlgorithm ###

        // shuffle x1000, returns p-value
        double computeF_all(int shuffles);

        // ??
        void computeMacaroni();

        // ??
        void computeFDR();


    // ### SnipperMain ###

        // get classifications
        Classifics& getClassifics();

        // count snips
        int getSNPcount(); 

        // for Testing (count Genotypes over all SNP's)
        int getGenCount(Genotype gen);

        // Get SNP'S per [] - operator
        SingleSNP operator [](int idx) const;


private:

    // List
    std::vector<SingleSNP> _snpstack; //
    Classifics _class;               //
};


#endif //SNIPPER_H
