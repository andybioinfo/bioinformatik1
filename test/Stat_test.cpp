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
#include "../Examples.h"
#include "../snipper/Snipper.h"

/**
 *  Tests for Statistic Formulas
 * 
 * 
 */




// 
TEST(Statistics, Accuracy)
    {

    double TP = 0;    double TN = 0;    double FP = 0;    double FN = 0;

    double val = Statistics::Accuracy( TP,  TN,  FP,  FN);
    std::cout << "Test(Accuracy) { TP: "<< TP <<" TN: "<< TN <<" FP: "<< FP <<" FN: "<< FN <<" } = " << val << "\n";
    EXPECT_EQ( 0  , val );

    TP = 8;    TN = 0;    FP = 2;    FN = 0;

    val = Statistics::Accuracy( TP,  TN,  FP,  FN);
    std::cout << "Test(Accuracy) { TP: "<< TP <<" TN: "<< TN <<" FP: "<< FP <<" FN: "<< FN <<" } = " << val << "\n";
    EXPECT_EQ( 80  , val );

    TP = 5;    TN = 9;    FP = 3;    FN = 1;

    val = Statistics::Accuracy( TP,  TN,  FP,  FN);
    std::cout << "Test(Accuracy) { TP: "<< TP <<" TN: "<< TN <<" FP: "<< FP <<" FN: "<< FN <<" } = " << val << "\n";
    EXPECT_TRUE( Snipper::doubleCompare(77.7778,val) );

    }



// 
TEST(Statistics, Sensitivity)
    {
    double TN = 0;    double FP = 0;
    double val = Statistics::Sensitivity( TN,  FP);
    std::cout << "Test(Sensitivity) { TN: "<< TN <<" FP: "<< FP <<" } = " << val << "\n";
    EXPECT_EQ( 0  , val );

    TN = 5;     FP = 0;
    val = Statistics::Sensitivity( TN,  FP);
    std::cout << "Test(Sensitivity) { TN: "<< TN <<" FP: "<< FP <<" } = " << val << "\n";
    EXPECT_EQ( 100  , val );

    TN = 5;     FP = 2;
    val = Statistics::Sensitivity( TN,  FP);
    std::cout << "Test(Sensitivity) { TN: "<< TN <<" FP: "<< FP <<" } = " << val << "\n";
    EXPECT_TRUE( Snipper::doubleCompare(26.7897,val) );

    }





// 
TEST(Statistics, Specificity)
    {
    double TP = 0;    double FN = 0; 
    double val = Statistics::Specificity( TP,  FN);
    std::cout << "Test(Specificity) { TP: "<< TP <<" FN: "<< FN <<" } = " << val << "\n";
    EXPECT_EQ( 0  , val );

    TP = 6;     FN = 0; 
    val = Statistics::Specificity( TP,  FN);
    std::cout << "Test(Specificity) { TP: "<< TP <<" FN: "<< FN <<" } = " << val << "\n";
    EXPECT_EQ( 100  , val );

    TP = 8;     FN = 2; 
    val = Statistics::Specificity( TP,  FN);
    std::cout << "Test(Specificity) { TP: "<< TP <<" FN: "<< FN <<" } = " << val << "\n";
    EXPECT_EQ( 80  , val );

    }






// 
TEST(Statistics, Precision)
    {
    double TP = 0;    double FP = 0; 
    double val = Statistics::Precision( TP,  FP);
    std::cout << "Test(Precision) { TP: "<< TP <<" FP: "<< FP <<" } = " << val << "\n";
    EXPECT_EQ( 0  , val );

    TP = 7;     FP = 0; 
    val = Statistics::Precision( TP,  FP);
    std::cout << "Test(Precision) { TP: "<< TP <<" FP: "<< FP <<" } = " << val << "\n";
    EXPECT_EQ( 100  , val );

    TP = 8;     FP = 2; 
    val = Statistics::Precision( TP,  FP);
    std::cout << "Test(Precision) { TP: "<< TP <<" FP: "<< FP <<" } = " << val << "\n";
    EXPECT_EQ( 80  , val );

    }



// 
TEST(Statistics, F1Score)
    {
    double PR = 20;    double SE = 80; 
    double val = Statistics::F1Score( PR,  SE);
    std::cout << "Test(F1Score) { prec: "<< PR <<" sens: "<< SE <<" } = " << val << "\n";
    EXPECT_EQ( 32  , val );

    PR = 100;     SE = 0; 
    val = Statistics::F1Score( PR,  SE);
    std::cout << "Test(F1Score) { prec: "<< PR <<" sens: "<< SE <<" } = " << val << "\n";
    EXPECT_EQ( 0  , val );

    PR = 50;     SE = 50; 
    val = Statistics::F1Score( PR,  SE);
    std::cout << "Test(F1Score) { prec: "<< PR <<" sens: "<< SE <<" } = " << val << "\n";
    EXPECT_EQ( 50  , val );

    }


// 
TEST(Statistics, Average)
    {
    std::vector<double> AV = {20.0 , 80.0 , 30.0};
    double val = Statistics::Average(AV);
    std::cout << "Test(Average) { val1: 20.0 val2: 80.0 val3: 30.0 } = " << val << "\n";
    EXPECT_TRUE( Snipper::doubleCompare(43.3333,val) );

    AV = { 0.0 , 0.0 , 0.0};
    val = Statistics::Average(AV);
    std::cout << "Test(Average) { val1: 0.0 val2: 0.0 val3: 0.0 } = " << val << "\n";
    EXPECT_EQ( 0  , val );

    AV = {100.0 , 50.0 , 100.0};
    val = Statistics::Average(AV);
    std::cout << "Test(Average) { val1: 100.0 val2: 50.0 val3: 100.0 } = " << val << "\n";
    EXPECT_TRUE( Snipper::doubleCompare(83.3333,val) );
    }



// 
TEST(Statistics, Standard_deviation)
    {

    std::vector<double> Xi = { 7 , 24 , 33 , 55 , 84 , 100 };

    std::vector<double> pXi = { 33.333 , 22.222 , 16.666 , 16.666 , 5.555 , 5.555 };

    double val = Statistics::Standard_deviation( Xi, pXi );
    std::cout << "Test(Standard_deviation) { X0: 7 X1: 42  X2: 33 X3: 55 X4: 84 X5: 100 | "
        << "pX0: 6/18 pX1: 4/18 pX2: 3/18 pX3: 3/18 pX4: 1/18 pX5: 1/18 } = " << val << "\n";

    EXPECT_TRUE( Snipper::doubleCompare(26.7897,val) );
    

    }


