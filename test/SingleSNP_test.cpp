//
// Created by manjaro on 21.01.22.
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





TEST(SingleSNP, ProbabilityTest)
{
Snipper S = getExercise4SNPs(); 

double x0a = S[0].probability(Hetero);
double x0b = S[0].probability(HomoMinor);
double x0c = S[0].probability(HomoMajor);
double x0d = S[0].probability(Cancer,Hetero);
double x1a = S[1].probability(Hetero);
double x1b = S[1].probability(HomoMajor);
double x2  = S[2].probability(Hetero);

EXPECT_TRUE(S.doubleCompare(0.33333  , x0a  ));
EXPECT_TRUE(S.doubleCompare(0.33333  , x0b  ));
EXPECT_TRUE(S.doubleCompare(0.33333  , x0c  ));
EXPECT_TRUE(S.doubleCompare(0.33333  , x0d  ));
EXPECT_TRUE(S.doubleCompare(0.33333  , x1a  ));
EXPECT_TRUE(S.doubleCompare(0.5      , x1b  ));
EXPECT_TRUE(S.doubleCompare(0.5      , x2   ));

}



TEST(SingleSNP, IndexOperatorTest)
{

    Snipper S; 

    S.getClassifics() << Cancer << Control << Cancer << Cancer << Control << Cancer;

    SingleSNP x1(S.getClassifics()); 

    x1 << Hetero << HomoMinor << HomoMajor << HomoMajor << HomoMinor << Hetero;

    S << x1;
    auto xx1 = S[0][2];
    auto xx2 = S[0][3];
    auto xx3 = S[0][4];

    EXPECT_EQ( HomoMajor  , xx1   );
    EXPECT_EQ( HomoMajor  , xx2   );
    EXPECT_EQ( HomoMinor  , xx3   );

}





TEST(SingleSNP, PushBackOperatorTest)
{

    Snipper S; 

    S.getClassifics() << Cancer << Control << Cancer << Cancer << Control << Cancer;

    SingleSNP x1(S.getClassifics()); 

    x1 << Hetero << HomoMinor;

    S << x1;

    EXPECT_EQ( 2  , S[0].getSize() );

    auto a = S[0][0];
    auto b = S[0][3];

    EXPECT_EQ( Hetero     , a );
    EXPECT_EQ( HomoMajor  , b );

}


