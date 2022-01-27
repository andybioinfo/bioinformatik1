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



// Tests if a custom Snipper build correct
TEST(Snipper, CustomSnipperTest)
    {

        // ## BUILD SNIPPER

        Snipper Snpr; 

        Snpr.getClassifics() << Cancer << Control << Cancer;        // Add Classifications to the Y-Vector

        SingleSNP x1(Snpr.getClassifics());                         // Create a empty SNP (Xi-Vector "X1")

        SingleSNP x2(Snpr.getClassifics());                         // Create a empty SNP (Xi-Vector "X2")

        x1 << Hetero << HomoMinor << HomoMajor << HomoMajor;        // Add Values to the SNP-Vector X1
        x2 << HomoMinor << HomoMajor << HomoMajor << Hetero;        // Add Values to the SNP-Vector X2

        Snpr << x1 << x2;                                           // Add both SNP's to the Snipper


        Genotype x0_0 = Snpr[0][0];                                 // Load the 4 Genotypes from SNP X0
        Genotype x0_1 = Snpr[0][1];                                 // => S[snp_id] [row_of_this_snp_id]
        Genotype x0_2 = Snpr[0][2];
        Genotype x0_3 = Snpr[0][3];
        Genotype x1_0 = Snpr[1][0];                                 // Load the 4 Genotypes from SNP X1
        Genotype x1_1 = Snpr[1][1];
        Genotype x1_2 = Snpr[1][2];
        Genotype x1_3 = Snpr[1][3];

        // ## TEST SNIPPER SNP- VALUES

        EXPECT_EQ( Hetero     , x0_0   );               // Load the 4 Genotypes from SNP X1       
        EXPECT_EQ( HomoMinor  , x0_1   );
        EXPECT_EQ( HomoMajor  , x0_2   );
        EXPECT_EQ( HomoMajor  , x0_3   );

        EXPECT_EQ( HomoMinor  , x1_0   );
        EXPECT_EQ( HomoMajor  , x1_1   );
        EXPECT_EQ( HomoMajor  , x1_2   );
        EXPECT_EQ( Hetero     , x1_3   );

        // ## TEST COUNT SNPs / SNP-VALUES / CLASSIFIC-VALUES

        int countHetero = Snpr.getGenCount(Hetero);     // Counts all Genotypes over all SNP's     
        int countMajor  = Snpr.getGenCount(HomoMajor);
        int countMinor  = Snpr.getGenCount(HomoMinor);
        int countSNPs = Snpr.getSNPcount();             // Counts all SNP's

        EXPECT_EQ( 2  , countHetero );                  // Genotype-Count correct?
        EXPECT_EQ( 4  , countMajor );
        EXPECT_EQ( 2  , countMinor );
        EXPECT_EQ( 2  , countSNPs );
        EXPECT_EQ( 3  , Snpr.getClassifics().count() ); // GetClassificsGenotype-Count correct?

    }



// Tests shuffling a SNP
TEST(Snipper, ShuffleTest)
    {

        Snipper S = getExercise4SNPs(); 

        EXPECT_EQ( 0  , 99 );

    }



// Tests compute Bonferroni
TEST(Snipper, BonferroniTest)
    {

        Snipper S = getExercise4SNPs(); 
        EXPECT_EQ( 2 , S.computeBonferroni(0.02));
    }


// Tests compute FDR
TEST(Snipper, FDRTest)
    {

        Snipper S = getExercise4SNPs(); 
        std::vector<double> adj_p_values;
        adj_p_values.push_back(1.0);adj_p_values.push_back(0.1);adj_p_values.push_back(2.0);
        S.computeFDR(adj_p_values);
        EXPECT_EQ( 0  , 99 );

    }



// Test Complete
TEST(Snipper, CompleteAlgorithmTest)
    {

        Snipper S = getExercise4SNPs();  

        EXPECT_EQ( 0  , 99 );

    }