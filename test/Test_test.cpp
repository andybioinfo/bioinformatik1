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
#include "../snipper/Snipper.h"
#include "../Examples.h"


/**
 *  Tests for Test, Predict and correct Stats 
 * 
 * 
 */




// only predicted on Block [3]
NaiveBayes getPredictedNaiveBayes() { 

    Snipper S = createExample2();  // create premixed Database

    NaiveBayes NB(S, 10,false);  

    std::vector<Block*> training = {&NB.getK_Blocks()[0] , &NB.getK_Blocks()[1] , &NB.getK_Blocks()[2]};

    NB.train(S,training);

    NB.getK_Blocks()[3].predict(NB.getModel(),S);

    return NB;

}





// Naive Bayes - Correct Predictions
TEST(TEST, PredictionTest)
    {

    NaiveBayes NB = getPredictedNaiveBayes();

    // ## Check predictions:

    // Cancer  = 1 
    // Control = 0 

    Classification A = NB.getK_Blocks()[3].getBlockPredictions()[0]; // Cancer   
    Classification B = NB.getK_Blocks()[3].getBlockPredictions()[1]; // Cancer  
    Classification C = NB.getK_Blocks()[3].getBlockPredictions()[2]; // Control 
    Classification D = NB.getK_Blocks()[3].getBlockPredictions()[3]; // Control 
    Classification E = NB.getK_Blocks()[3].getBlockPredictions()[4]; // Control 

    EXPECT_EQ( Cancer  , A );
    EXPECT_EQ( Cancer  , B );
    EXPECT_EQ( Cancer , C );
    EXPECT_EQ( Cancer , D );
    EXPECT_EQ( Cancer , E );


}





// Naive Bayes - correct Predict/True Statistics
TEST(TEST, Predict_Correct_Accuracy)
    {

    NaiveBayes NB = getPredictedNaiveBayes();

    NB.getK_Blocks()[3].calcStatistics(NB);

    Statistics ST = NB.getStats();

    double val = ST.get_stats_Accuracy()[0];      // [Formula]  TP + TN / TP + FN + FP + FN  => 0,8 = 80%

    EXPECT_EQ(  80  , val );

}





// Naive Bayes - correct Predict/True Statistics
TEST(TEST, Predict_Correct_Precision)
    {

    NaiveBayes NB = getPredictedNaiveBayes();

    NB.getK_Blocks()[3].calcStatistics(NB);

    Statistics ST = NB.getStats();

    double val = ST.get_stats_Precision()[0];     // [Formula]  TP / TP + FP  => 0,80 = 80%

    EXPECT_EQ(  80  , val );

}





// Naive Bayes - correct Predict/True Statistics
TEST(TEST, Predict_Correct_Sensitivity)
    {

    NaiveBayes NB = getPredictedNaiveBayes();

    NB.getK_Blocks()[3].calcStatistics(NB);

    Statistics ST = NB.getStats();

    double val = ST.get_stats_Sensitivity()[0];   // [Formula]  TP / TP + FN  => 0 = 0%

    EXPECT_EQ( 0  , val );

}





// Naive Bayes - correct Predict/True Statistics
TEST(TEST, Predict_Correct_Specifity)
    {

    NaiveBayes NB = getPredictedNaiveBayes();

    NB.getK_Blocks()[3].calcStatistics(NB);

    Statistics ST = NB.getStats();

    double val = ST.get_stats_Specificity()[0];   // [Formula]  TN / TN + FP  => 1 = 100%

    EXPECT_EQ(  100  , val );

}




