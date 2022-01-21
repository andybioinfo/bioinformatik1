//
// Created by manjaro on 21.01.22.
//

#ifndef SNIPPER_SINGLESNP_H
#define SNIPPER_SINGLESNP_H

#include <vector>
#include "States.h"
#include "Classifics.h"

/** SNP (Column Xi)
 *
 *    Y X1 X2 X3
 * P1 1  1  2  0
 * P2 0  2  0  0
 * P3 1  0  2  1
 *
 * */

/** The X-Vector ( SNP )
 *
 *
 * */
class SingleSNP {

public:

    using X_Vector = std::vector<Genotype>;

    // Create SNP
    SingleSNP(Classifics &_clss);

    // Get SNP'S
    Genotype operator [](int idx) const;

    // get SNP Size / count of patients
    int getSize();

    // get matched Classification at row Position
    Classification getClassificationAt(int pos);

    // add a new classification aka row
    SingleSNP & operator << (Genotype const &g)
    {
        _snp.push_back(g);
        return *this;
    }


    void computeF();

    double fracFormula();


private:

    // List
    X_Vector _snp;            // The SNP
    Classifics *_class{};         // The classifications of the SNP-Vector
    std::vector<double> _frac; // ??




};


#endif //SNIPPER_SINGLESNP_H
