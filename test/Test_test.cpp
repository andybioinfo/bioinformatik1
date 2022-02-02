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

    Classification A = NB.getK_Blocks()[3].getBlockPredictions()[0]; // Control  = 1 
    Classification B = NB.getK_Blocks()[3].getBlockPredictions()[1]; // Control  = 1
    Classification C = NB.getK_Blocks()[3].getBlockPredictions()[2]; // Cancer   = 0
    Classification D = NB.getK_Blocks()[3].getBlockPredictions()[3]; // Cancer   = 0
    Classification E = NB.getK_Blocks()[3].getBlockPredictions()[4]; // Cancer   = 0

    EXPECT_EQ( Control  , A );
    EXPECT_EQ( Control  , B );
    EXPECT_EQ( Cancer   , C );
    EXPECT_EQ( Cancer   , D );
    EXPECT_EQ( Cancer   , E );


}





// Naive Bayes - correct Predict/True Statistics
TEST(TEST, Predict_Correct_Accuracy)
    {

    NaiveBayes NB = getPredictedNaiveBayes();

    NB.getK_Blocks()[3].calcStatistics(NB);

    Statistics ST = NB.getStats();

    /**  Block[3]  // Cancer  = 1   // Control = 0 
     *   
     *   true 1 -> pre 0      
     *   true 0 -> pre 0
     *   true 1 -> pre 1
     *   true 1 -> pre 1
     *   true 1 -> pre 1
     *   
     *   TP = 3 ; TN = 1 ; FP = 1 ; FN = 0 
     * 
     */  
    
    double val = ST.get_stats_Accuracy()[0];      // [Formula]  TP + TN / TP + FN + FP + FN  => 0,8 = 80%

    EXPECT_EQ(  80  , val );

}





// Naive Bayes - correct Predict/True Statistics
TEST(TEST, Predict_Correct_Precision)
    {

    NaiveBayes NB = getPredictedNaiveBayes();

    NB.getK_Blocks()[3].calcStatistics(NB);

    Statistics ST = NB.getStats();

    /**  Block[3]  // Cancer  = 1   // Control = 0 
     *   
     *   true 1 -> pre 0      
     *   true 0 -> pre 0
     *   true 1 -> pre 1
     *   true 1 -> pre 1
     *   true 1 -> pre 1
     *   
     *   TP = 3 ; TN = 1 ; FP = 1 ; FN = 0 
     * 
     */  
    
    double val = ST.get_stats_Precision()[0];     // [Formula]  TP / TP + FP  => 0,75 = 75%

    EXPECT_EQ(  75  , val );

}





// Naive Bayes - correct Predict/True Statistics
TEST(TEST, Predict_Correct_Sensitivity)
    {

    NaiveBayes NB = getPredictedNaiveBayes();

    NB.getK_Blocks()[3].calcStatistics(NB);

    Statistics ST = NB.getStats();

    /**  Block[3]  // Cancer  = 1   // Control = 0 
     *   
     *   true 1 -> pre 0      
     *   true 0 -> pre 0
     *   true 1 -> pre 1
     *   true 1 -> pre 1
     *   true 1 -> pre 1
     *   
     *   TP = 3 ; TN = 1 ; FP = 1 ; FN = 0 
     * 
     */  
    
    double val = ST.get_stats_Sensitivity()[0];   // [Formula]  TP / TP + FN  => 1,0 = 100%

    EXPECT_EQ( 100  , val );

}





// Naive Bayes - correct Predict/True Statistics
TEST(TEST, Predict_Correct_Specifity)
    {

    NaiveBayes NB = getPredictedNaiveBayes();

    NB.getK_Blocks()[3].calcStatistics(NB);

    Statistics ST = NB.getStats();

    /**  Block[3]  // Cancer  = 1   // Control = 0 
     *   
     *   true 1 -> pre 0      
     *   true 0 -> pre 0
     *   true 1 -> pre 1
     *   true 1 -> pre 1
     *   true 1 -> pre 1
     *   
     *   TP = 3 ; TN = 1 ; FP = 1 ; FN = 0 
     * 
     */  
    
    double val = ST.get_stats_Specificity()[0];   // [Formula]  TN / TN + FP  => 0,5 = 50%

    EXPECT_EQ(  75  , val );

}





// Naive Bayes - correct Predict/True Statistics
TEST(TEST, Predict_Correct_F1Score)
    {

    NaiveBayes NB = getPredictedNaiveBayes();

    NB.getK_Blocks()[3].calcStatistics(NB);

    Statistics ST = NB.getStats();

    /**  Block[3]  // Cancer  = 1   // Control = 0 
     *   
     *   true 1 -> pre 0      
     *   true 0 -> pre 0
     *   true 1 -> pre 1
     *   true 1 -> pre 1
     *   true 1 -> pre 1
     *   
     *   TP = 3 ; TN = 1 ; FP = 1 ; FN = 0 
     * 
     */  
    
    double val = ST.get_stats_F1Score()[0];       // [Formula]  2 * pre * sens / pre + sens  => 85,714285

    EXPECT_EQ(  85.714285  , val );

}

