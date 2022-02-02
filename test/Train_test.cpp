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
//#include "../Statistics.h"
#include "../NaiveBayes.h"
#include "../Model.h"
#include "../snipper/Snipper.h"
#include "../Examples.h"


/**
 *  Tests for Model and Training
 * 
 * 
 */







// Create Naive Bayes - Training -> Matrix-Columns are 1
TEST(Model, CreateTest)
    {

        Snipper S1 = createExample2();  // create premixed Database
        Snipper S2 = createSNPs();      // create unmixed  Database

        NaiveBayes NB1(S1, 10,false);  
        NaiveBayes NB2(S2, 10,false); 

    // ## Test Model - Naive Bayes Small

    double pCN = 0;
    double pXiCN = 0;

    pCN   += NB1.getModel().getPCancer();  //  pCancer
    pXiCN += NB1.getModel().getPControl(); //  pControl

    EXPECT_EQ( 1 , pCN + pXiCN ); // prob's = 1

    pXiCN = 0;

    pXiCN += NB1.getModel().getGenProbAtXi(Cancer,HomoMajor,1);  // Column SNP Xi = 1 / Cancer
    pXiCN += NB1.getModel().getGenProbAtXi(Cancer,Hetero,1);     //
    pXiCN += NB1.getModel().getGenProbAtXi(Cancer,HomoMinor,1);  //

    pXiCN += NB1.getModel().getGenProbAtXi(Control,HomoMajor,1);  // Column SNP Xi = 1 / Control
    pXiCN += NB1.getModel().getGenProbAtXi(Control,Hetero,1);     //
    pXiCN += NB1.getModel().getGenProbAtXi(Control,HomoMinor,1);  //

    EXPECT_EQ( 1 , pXiCN );  // prob's = 1

    // ## Test Model - Naive Bayes Big

    pCN = 0;
    pXiCN = 0;

    pCN   += NB2.getModel().getPCancer();  //  pCancer
    pXiCN += NB2.getModel().getPControl(); //  pControl

    EXPECT_EQ( 1 , pCN + pXiCN );  // prob's = 1

    pXiCN = 0;

    pXiCN += NB2.getModel().getGenProbAtXi(Cancer,HomoMajor,1);  // Column SNP Xi = 1 / Cancer
    pXiCN += NB2.getModel().getGenProbAtXi(Cancer,Hetero,1);     //
    pXiCN += NB2.getModel().getGenProbAtXi(Cancer,HomoMinor,1);  //

    pXiCN += NB2.getModel().getGenProbAtXi(Control,HomoMajor,1);  // Column SNP Xi = 1 / Control
    pXiCN += NB2.getModel().getGenProbAtXi(Control,Hetero,1);     //
    pXiCN += NB2.getModel().getGenProbAtXi(Control,HomoMinor,1);  //

    EXPECT_EQ( 1 , pXiCN );  // prob's = 1


}




// Create Naive Bayes - Training -> Correct Matrix Values after training
TEST(Model, TrainingTest)
    {

    Snipper S = createExample2();  // create premixed Database

    NaiveBayes NB(S, 10,false);  

    std::vector<Block*> training = {&NB.getK_Blocks()[0] , &NB.getK_Blocks()[1] , &NB.getK_Blocks()[2]};

    NB.train(S,training);

    // ## Small tables:

    double pC = NB.getModel().getPCancer();  //  pCancer      0,6
    double pN = NB.getModel().getPControl(); //  pControl     0,4

    EXPECT_EQ( 0.6 , pC );  
    EXPECT_EQ( 0.4 , pN ); 


    // ## Cancer Table

    double CXi_0_0 = NB.getModel().getGenProbAtXi(Cancer,HomoMajor ,0);
    double CXi_0_1 = NB.getModel().getGenProbAtXi(Cancer,Hetero    ,0);
    double CXi_0_2 = NB.getModel().getGenProbAtXi(Cancer,HomoMinor ,0);

    double CXi_1_0 = NB.getModel().getGenProbAtXi(Cancer,HomoMajor ,1);
    double CXi_1_1 = NB.getModel().getGenProbAtXi(Cancer,Hetero    ,1);
    double CXi_1_2 = NB.getModel().getGenProbAtXi(Cancer,HomoMinor ,1);

    double CXi_2_0 = NB.getModel().getGenProbAtXi(Cancer,HomoMajor ,2);
    double CXi_2_1 = NB.getModel().getGenProbAtXi(Cancer,Hetero    ,2);
    double CXi_2_2 = NB.getModel().getGenProbAtXi(Cancer,HomoMinor ,2);

    EXPECT_EQ( (1.0/15.0)  , CXi_0_0 );  
    EXPECT_EQ( (8.0/15.0)  , CXi_0_1 ); 
    EXPECT_EQ( 0           , CXi_0_2 ); 

    EXPECT_EQ( (8.0/15.0) , CXi_1_0 );  
    EXPECT_EQ( (1.0/15.0) , CXi_1_1 ); 
    EXPECT_EQ( 0          , CXi_1_2 ); 

    EXPECT_EQ( 0   , CXi_2_0 );  
    EXPECT_EQ( 0   , CXi_2_1 ); 
    EXPECT_EQ( 0.4 , CXi_2_2 ); 
    

    // ## Normal Table

    double NXi_0_0 = NB.getModel().getGenProbAtXi(Control,HomoMajor ,0);
    double NXi_0_1 = NB.getModel().getGenProbAtXi(Control,Hetero    ,0);
    double NXi_0_2 = NB.getModel().getGenProbAtXi(Control,HomoMinor ,0);

    double NXi_1_0 = NB.getModel().getGenProbAtXi(Control,HomoMajor ,1);
    double NXi_1_1 = NB.getModel().getGenProbAtXi(Control,Hetero    ,1);
    double NXi_1_2 = NB.getModel().getGenProbAtXi(Control,HomoMinor ,1);

    double NXi_2_0 = NB.getModel().getGenProbAtXi(Control,HomoMajor ,2);
    double NXi_2_1 = NB.getModel().getGenProbAtXi(Control,Hetero    ,2);
    double NXi_2_2 = NB.getModel().getGenProbAtXi(Control,HomoMinor ,2);

    EXPECT_EQ( 0.2 , NXi_0_0 );  
    EXPECT_EQ( 0.2 , NXi_0_1 ); 
    EXPECT_EQ( 0   , NXi_0_2 ); 

    EXPECT_EQ( 0.2 , NXi_1_0 );  
    EXPECT_EQ( 0.2 , NXi_1_1 ); 
    EXPECT_EQ( 0   , NXi_1_2 ); 

    EXPECT_EQ( 0   , NXi_2_0 );  
    EXPECT_EQ( 0   , NXi_2_1 ); 
    EXPECT_EQ( 0.4 , NXi_2_2 ); 

}

