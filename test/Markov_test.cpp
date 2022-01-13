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
#include "../Markov.h"


// SetValueInRangeTest
TEST(MARKOV, SetValueInRangeTest)
{
// too big
double large = Markov::Range(1.0125e+99);
// negative
double negative = Markov::Range(-199.0);
// correct
double one = Markov::Range(1.0);
double between = Markov::Range(0.51);
double zero = Markov::Range(0.0);
EXPECT_EQ(1.0, 0.0);
}





// String to Flip-Sequence Test
TEST(MARKOV, String2Flip_Sequence)
{
// String to Flip-Sequence
auto a = Markov::String2Sequence("1");
auto b = Markov::String2Sequence("0");
auto c = Markov::String2Sequence("101011");
auto c2 = Markov::String2Sequence("1010112");
auto d = Markov::String2Sequence("");
auto e = Markov::String2Sequence("pizzafleischkääsweck");
EXPECT_EQ(1.0, 0.0);
}


// Create markov and check his matrices
TEST(MARKOV, Create_Markov_Test)
{
    Markov m(0.1,0.5,0.75);
    auto change = m.getChangeMatrix();
    auto product = m.getProductMatrix();

    EXPECT_EQ(0.1, change.getValue(0,0));
    EXPECT_EQ(0.1, change.getValue(1,1));
    EXPECT_EQ(0.9, change.getValue(1,0));
    EXPECT_EQ(0.9, change.getValue(0,1));

    EXPECT_EQ(0.5, product.getValue(1,0));
    EXPECT_EQ(0.5, product.getValue(1,1));
    EXPECT_EQ(0.75, product.getValue(1,0));
    EXPECT_EQ(0.25, product.getValue(0,0));

}


// Create markov and check if the given values back in range in his matrices
TEST(MARKOV, Create_Markov_OutRangeValues)
{



}


// Matrix value test for production probabilities
TEST(MARKOV, Matrix_Chance_Test)
{



}

// Matrix value test for production probabilities
TEST(MARKOV, Matrix_Prod_Test)
{



}



