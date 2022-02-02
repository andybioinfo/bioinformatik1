#include <gtest/gtest.h>

#include <memory>
#include <initializer_list>
#include <set>
#include <vector>
#include <deque>
#include <string>
#include <ostream>
#include <istream>
#include <sstream>
#include <iostream>
#include "../Statistics.h"
#include "../NaiveBayes.h"
#include "../Model.h"
#include "../snipper/Snipper.h"
#include "../Examples.h"


/**
 *  Tests for Creating Naive Bayes Class
 * 
 * 
 */




// Create correct Naive Bayes - No Exception Throw
TEST(Bayes, CreateNoException)
    {


    Snipper S1 = createExample2();  // create premixed Database
    Snipper S2 = createSNPs();     // create unmixed  Database

    NaiveBayes NB1(S1, 10,false);   // no shuffling, SNP-database is premixed
    NaiveBayes NB2(S2, 10,false);   // no shuffling, SNP-database is premixed

}



// Create invalid Naive Bayes - Exception Throw
TEST(Bayes, CreateInvalidException)
    {

    Snipper S1; // 5 Patients, 1 SNP
    S1.getClassifics() << Cancer << Control << Cancer << Cancer << Cancer;
    Snipper S2; // 10 Patients, 0 SNP
    S2.getClassifics() << Cancer << Control << Cancer << Cancer << Cancer << Cancer << Control << Cancer << Cancer << Cancer;
    Snipper S3; // 10 Patients, 1 SNP
    S3.getClassifics() << Cancer << Control << Cancer << Cancer << Cancer << Cancer << Control << Cancer << Cancer << Cancer;

    SingleSNP s1(S1.getClassifics());
    SingleSNP s3(S3.getClassifics());

    s1 << HomoMajor << Hetero << HomoMajor << Hetero << HomoMajor;
    s3 << HomoMajor << Hetero << HomoMajor << Hetero << HomoMajor << HomoMajor << Hetero << HomoMajor << Hetero << HomoMajor;

    S1 << s1;
    S3 << s3;

    NaiveBayes NB1(S1, 10,false);  // too less patients exception  
    NaiveBayes NB2(S2, 10,false);  // no SNP's exception
    NaiveBayes NB3(S3, 0,false);   // no Fold-division exception 

}



// Create Naive Bayes - Correct Field values after creating
TEST(Bayes, CreateCorrectFields)
    {

    Snipper S1 = createExample2();  // create premixed Database
    Snipper S2 = createSNPs();      // create unmixed  Database

    NaiveBayes NB1(S1, 10,false);   // no shuffling 
    NaiveBayes NB2(S2, 10,false);   // no shuffling

    int a1 = NB1.get_k_COUNT(); // 10 blocks
    int a2 = NB2.get_k_COUNT(); // 10 blocks

    int b1 = NB1.get_k_SIZE(); // Block Size 5
    int b2 = NB2.get_k_SIZE(); // Block Size 4

    EXPECT_EQ( 10  , a1 );
    EXPECT_EQ( 10  , a2 );
    EXPECT_EQ(  5  , b1 );
    EXPECT_EQ(  4  , b2 );

}




// Create Naive Bayes - Correct Model Size values after creating
TEST(Bayes, CreateCorrectModelSize)
    {

        Snipper S1 = createExample2();  // create premixed Database
        Snipper S2 = createSNPs();      // create unmixed  Database

        NaiveBayes NB1(S1, 10,false);  
        NaiveBayes NB2(S2, 10,false);   

        int a1 = NB1.getModel().getSNPcount(); // 3
        int a2 = NB2.getModel().getSNPcount(); // 8

        int b1 = NB1.getModel().getGenProbAtXi(Cancer,Hetero,2); // no out-of-bounds
        int b2 = NB2.getModel().getGenProbAtXi(Cancer,Hetero,7); // no out-of-bounds

        EXPECT_EQ( 3  , a1 );
        EXPECT_EQ( 8  , a2 );
        EXPECT_EQ( 0  , b1 );
        EXPECT_EQ( 0  , b2 );

    }








