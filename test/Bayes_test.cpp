//
// Created by manjaro on 24.01.22.
//

#include <gtest/gtest.h>
#include "../Snipper.h"



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



// 
TEST(Model, Test)
    {

    EXPECT_TRUE(false);

    }


      


