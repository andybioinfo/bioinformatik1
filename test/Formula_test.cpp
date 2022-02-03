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
 *  Tests for LOR Formula
 * 
 * 
 */


// Tests the I(X,Y) Formula
TEST(LOR, LOR_FormulaTest)
{

    double pXiC  = 64.0 / 375.0; 
    double pXiN  =  2.0 / 125.0; 
    double pC    =  7.0 /  15.0;
    double pN    =  8.0 /  15.0;


    Classification result = NaiveBayes::LOR_Formula( pXiC,  pXiN,  pC,  pN);

    EXPECT_EQ( Control  , result );

}