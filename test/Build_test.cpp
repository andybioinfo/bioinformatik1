//
// Created by manjaro on 21.01.22.
//
#include <gtest/gtest.h>
#include "../Snipper.h"

TEST(SNP_BUILD, CreatingTest)
{

Snipper S; // Exercise 4 SNPs
S.getClassifics() << Cancer << Control << Cancer << Cancer << Control << Cancer;
SingleSNP x1(S.getClassifics());
SingleSNP x2(S.getClassifics());
SingleSNP x3(S.getClassifics());
x1 << Hetero    << HomoMinor << HomoMajor << HomoMajor << HomoMinor << Hetero;
x2 << HomoMinor << HomoMajor << HomoMinor << Hetero    << Hetero    << HomoMinor;
x3 << HomoMajor << HomoMajor << Hetero    << HomoMajor << Hetero    << Hetero;
S << x1 << x2  << x3;

double x0r2 = S[0][2];
double x1r0 = S[1][0];
double x2r4 = S[2][4];

EXPECT_EQ(HomoMajor, x0r2);
EXPECT_EQ(HomoMinor, x1r0);
EXPECT_EQ(Hetero, x2r4);

}


TEST(SNP_BUILD, SizeTest)
{
/*
Snipper S; // Exercise 4 SNPs
S.getClassifics() << Cancer << Control << Cancer << Cancer << Control << Cancer;
SingleSNP x1(S.getClassifics());
SingleSNP x2(S.getClassifics());
SingleSNP x3(S.getClassifics());
x1 << Hetero    << HomoMinor << HomoMajor << HomoMajor << HomoMinor << Hetero;
x2 << HomoMinor << HomoMajor << HomoMinor << Hetero    << Hetero    << HomoMinor;
x3 << HomoMajor << HomoMajor << Hetero    << HomoMajor << Hetero    << Hetero;
S << x1 << x2  << x3;

double x0 = S[0].getSize();
double x1 = S[1].getSize();
double x2 = S[2].getSize();
double cc = S[0].getSize();
/*
EXPECT_EQ(HomoMajor, x0r2);
EXPECT_EQ(HomoMinor, x1r0);
EXPECT_EQ(Hetero, x2r4);
*/
}