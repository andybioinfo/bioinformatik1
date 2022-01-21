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

    // ## Constructors

    SingleSNP(Classifics &_clss);
    SingleSNP & operator << (Genotype const &g)
    {
        _snp.push_back(g);
        return *this;
    }

    // ## Formulas

    double probability(Genotype chosen);
    double probability(Classification _Y, Genotype _X);
    double computeF();

    static double I_XY_Formula(double pY0, double pY1, double pXi0,double pXi1, double pXi2, double pY0_Xi0, double pY0_Xi1, double pY0_Xi2, double pY1_Xi0, double pY1_Xi1, double pY1_Xi2 );
    static double H_X_Formula(double pXi0,double pXi1, double pXi2);

    // ## Getter

    Classification getClassificationAt(int pos);
    Genotype operator [](int idx) const;
    int getSize();

private:

    // List
    X_Vector _snp;             // The SNP
    Classifics *_class{};      // The classifications of the SNP-Vector
    std::vector<double> _frac; // ??

};


#endif //SNIPPER_SINGLESNP_H
