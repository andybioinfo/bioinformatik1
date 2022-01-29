//
// Created by manjaro on 21.01.22.
//

#include <stdexcept>
#include <valarray>
#include <iostream>
#include "SingleSNP.h"


/** Returns the probability of a chosen genotype in this SNP
 *
 * @chosen     the genotype to check
 * @return     probability
 * */
double SingleSNP::probability(Genotype chosen) {
    if (_snp.empty())   {throw std::invalid_argument("your count of genotypes is zero!"); }

    int complete_count  = _snp.size();
    int count    = 0;

    for (Genotype c : _snp) {
        if (c == chosen) {count++;}

    }

    return (double)count  / (double)complete_count;
}


/** Returns the probability of a chosen genotype at a 
 *  given classification in this SNP
 *
 * @_Y         the classification to check
 * @_X         the genotype to check
 * @return     probability
 * */
double SingleSNP::probability(Classification _Y, Genotype _X) {
    if (_snp.empty())   {throw std::invalid_argument("your count of genotypes is zero!"); }

    int complete_count  = _snp.size();
    int count    = 0;

    for (int idx = 0 ; idx < complete_count ; idx++) {
        Genotype gg = _snp[idx];
        Classification cc = _class->operator[](idx);
        if (gg == _X && cc == _Y) {count++;}
    }
    return (double)count  / (double)complete_count;

}


/** Compute the F-Value of this SNP with the Y-Vector
 *
 * @return     F-Value
 * */
double SingleSNP::computeF() {

    double pY0 =        _class->probability(Control);
    double pY1 =        _class->probability(Cancer);
    double pXi0 =       probability(HomoMajor);
    double pXi1 =       probability(Hetero);
    double pXi2 =       probability(HomoMinor);
    double pY0_Xi0 =    probability(Control,HomoMajor);
    double pY0_Xi1 =    probability(Control,Hetero);
    double pY0_Xi2 =    probability(Control,HomoMinor);
    double pY1_Xi0 =    probability(Cancer,HomoMajor);
    double pY1_Xi1 =    probability(Cancer,Hetero);
    double pY1_Xi2 =    probability(Cancer,HomoMinor);

   // std::cout << "p(y0): " << pY0 << " p(y1): " << pY1 << " p(x0): " <<pXi0 << " p(x1): " <<pXi1 << " p(x2): " <<pXi2 << " p(y0x0): " <<pY0_Xi0 << " p(y0x1): " <<pY0_Xi1 << " p(y0x2): " <<pY0_Xi2 << " p(y1x0): " <<pY1_Xi0 << " p(y1x1): " <<pY1_Xi1 << " p(y1x2): " <<pY1_Xi2 << " || ";

    double _IXY =   I_XY_Formula(pY0,pY1,pXi0,pXi1,pXi2,pY0_Xi0,pY0_Xi1,pY0_Xi2,pY1_Xi0,pY1_Xi1,pY1_Xi2);
    double _HX =    H_X_Formula(pY0,pY1);

    //std::cout << "\n                   I(X,Y) = " << _IXY << " / H(X) = " << _HX << " = ";

    return _IXY / _HX;

}




/** Compute I(X,Y)
 * 
 * @all     The probabilites of all Genotypes to Control and Cancer
 * @return  I(X,Y)  
 * */
double SingleSNP::I_XY_Formula(double pY0, double pY1, double pXi0, double pXi1, double pXi2, double pY0_Xi0, double pY0_Xi1,
                        double pY0_Xi2, double pY1_Xi0, double pY1_Xi1, double pY1_Xi2) {
    double res = 0;
    double s1 = pY0_Xi0 * log10(pY0_Xi0 / ( pY0 * pXi0 ) );
    double s2 = pY0_Xi1 * log10(pY0_Xi1 / ( pY0 * pXi1 ) );
    double s3 = pY0_Xi2 * log10(pY0_Xi2 / ( pY0 * pXi2 ) );
    double s4 = pY1_Xi0 * log10(pY1_Xi0 / ( pY1 * pXi0 ) );
    double s5 = pY1_Xi1 * log10(pY1_Xi1 / ( pY1 * pXi1 ) );
    double s6 = pY1_Xi2 * log10(pY1_Xi2 / ( pY1 * pXi2 ) );

    //std::cout << "   s1     " << s1 << "        s2        " << s2 << "        s3        " << s3 << "        s4        " << s4 << "        s5        " << s5 << "        s6        " << s6 << "\n                   ";

    if (s1 == s1) {res += s1;}
    if (s2 == s2) {res += s2;}
    if (s3 == s3) {res += s3;}
    if (s4 == s4) {res += s4;}
    if (s5 == s5) {res += s5;}
    if (s6 == s6) {res += s6;}


    return res;
}



/** Compute H(X)
 * 
 * @all     The probabilites of  Control and Cancer
 * @return  H(X)  
 * */
double SingleSNP::H_X_Formula(double pY0, double pY1) {

    double res = 0;
    double s1 = pY0 * log10( 1 /  pY0  );
    double s2 = pY1 * log10( 1 /  pY1  );
    if (s1 == s1) {res += s1;}
    if (s2 == s2) {res += s2;}


    return res;
}





void SingleSNP::SetRank(int rank, double pval){
this->rank = rank;
this->p_value = pval;
}




int SingleSNP::getRank()    {return rank;}
int SingleSNP::getP_Value() {return p_value;}

/** Getter
 * 
 * */
SingleSNP::SingleSNP(Classifics &_clss) { this->_class = &_clss; }
Genotype SingleSNP::operator[](int idx) const { return _snp[idx]; }
int SingleSNP::getSize() { return _snp.size(); }
Classification SingleSNP::getClassificationAt(int pos) { return (*_class)[pos]; }

Genotype SingleSNP::int2gen(int g) {
    if (g == 0) {return HomoMajor; }  // Int = 0
    if (g == 1) {return Hetero;    }  // Int = 1
                 return HomoMinor;    // Int = 2

}

