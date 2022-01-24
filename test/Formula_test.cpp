//
// Created by manjaro on 21.01.22.
//

#include <gtest/gtest.h>
#include "../Snipper.h"
#include "../SingleSNP.h"


// Builder for "Exercise 4 SNPs"
Snipper getExercise4SNPs() {

    Snipper S; // Exercise 4 SNPs
    S.getClassifics() << Cancer << Control << Cancer << Cancer << Control << Cancer;
    SingleSNP x1(S.getClassifics());
    SingleSNP x2(S.getClassifics());
    SingleSNP x3(S.getClassifics());
    x1 << Hetero    << HomoMinor << HomoMajor << HomoMajor << HomoMinor << Hetero;
    x2 << HomoMinor << HomoMajor << HomoMinor << Hetero    << Hetero    << HomoMinor;
    x3 << HomoMajor << HomoMajor << Hetero    << HomoMajor << Hetero    << Hetero;
    S << x1 << x2 << x3;
    return S;
}



// Tests the I(X,Y) Formula
TEST(SNP_FORMULA, I_XY_FormulaTest)
{

    double pY0 = 2.0/6.0;double pY1 = 4.0/6.0;                                          // Exercise 4

    double pXi0 = 2.0/6.0;double pXi1 = 2.0/6.0;double pXi2 = 2.0/6.0;                  // Exercise 4

    double pY0_Xi0 = 0;         double pY0_Xi1 = 0;         double pY0_Xi2 = 2.0/6.0;   // Exercise 4
    double pY1_Xi0 = 2.0/6.0;   double pY1_Xi1 = 2.0/6.0;   double pY1_Xi2 =    0;      // Exercise 4

    double X1 = SingleSNP::I_XY_Formula(pY0,pY1,pXi0,pXi1,pXi2,pY0_Xi0,pY0_Xi1,pY0_Xi2,pY1_Xi0,pY1_Xi1,pY1_Xi2);

    pXi0 = 2.0/6.0;     pXi1 = 2.0/6.0;     pXi2 = 2.0/6.0;

    pY0_Xi0 = 1.0/6.0;  pY0_Xi1 = 1.0/6.0;  pY0_Xi2 = 0.0/6.0;
    pY1_Xi0 = 0.0/6.0;  pY1_Xi1 = 1.0/6.0;  pY1_Xi2 = 3.0/6.0;

    double X2 = SingleSNP::I_XY_Formula(pY0,pY1,pXi0,pXi1,pXi2,pY0_Xi0,pY0_Xi1,pY0_Xi2,pY1_Xi0,pY1_Xi1,pY1_Xi2);

    pXi0 = 3.0/6.0;     pXi1 = 3.0/6.0;     pXi2 = 0.0/6.0;

    pY0_Xi0 = 1.0/6.0;  pY0_Xi1 = 1.0/6.0;  pY0_Xi2 = 0.0/6.0;
    pY1_Xi0 = 2.0/6.0;  pY1_Xi1 = 2.0/6.0;  pY1_Xi2 = 0.0/6.0;

    double X3 = SingleSNP::I_XY_Formula(pY0,pY1,pXi0,pXi1,pXi2,pY0_Xi0,pY0_Xi1,pY0_Xi2,pY1_Xi0,pY1_Xi1,pY1_Xi2);

    EXPECT_EQ(0.2764345909, X1); // Exercise 4
    EXPECT_EQ(0.1760912591, X2); // Exercise 4
    EXPECT_EQ(0           , X3); // Exercise 4

}



// Tests the H(X) Formula
TEST(SNP_FORMULA, H_X_FormulaTest)
{

    double pY0 = 2.0/6.0; 
    double pY1 = 4.0/6.0;

    double H1 = SingleSNP::H_X_Formula(pY0,pY1); // Exercise 4

    pY0 = 0.0/6.0; 
    pY1 = 6.0/6.0;

    double H2 = SingleSNP::H_X_Formula(pY0,pY1); // Zero Test p(Y1)=0

    pY0 = 6.0/6.0; 
    pY1 = 0.0/6.0;

    double H3 = SingleSNP::H_X_Formula(pY0,pY1); // Zero Test p(Y0)=0

    EXPECT_EQ(0.2764345909 , X1);
    EXPECT_EQ(0            , X2);
    EXPECT_EQ(0            , X3);

}



// Tests the computeF-Method
TEST(SNP_FORMULA, ComputeF_Test)
{

Snipper S = getExercise4SNPs(); // Exercise 4

    double X1 = S[0].computeF();
    double X2 = S[1].computeF();
    double X3 = S[2].computeF();

    EXPECT_EQ(0        , X1);
    EXPECT_EQ(0.637009 , X2);
    EXPECT_EQ(0        , X3);

}





