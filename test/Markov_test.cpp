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
EXPECT_EQ(1.0, large);
EXPECT_EQ(0.0, negative);
EXPECT_EQ(1.0, one);
EXPECT_EQ(0.0, zero);
EXPECT_EQ(0.51, between);

}





// String to Flip-Sequence Test
TEST(MARKOV, String2Flip_Sequence)
{
// String to Flip-Sequence
auto a = Markov::String2Sequence("1");
auto b = Markov::String2Sequence("0");
auto c = Markov::String2Sequence("101011");
auto d = Markov::String2Sequence("1010112");
auto e = Markov::String2Sequence("");
auto f = Markov::String2Sequence("pizzafleischkääsweck");

std::vector<Flip> seqA;
seqA.push_back(Head);

std::vector<Flip> seqB;
seqB.push_back(Tail);

std::vector<Flip> seqC;
seqC.push_back(Head);seqC.push_back(Tail);seqC.push_back(Head);seqC.push_back(Tail);
seqC.push_back(Head);seqC.push_back(Head);

std::vector<Flip> seqEmpty;


EXPECT_EQ(a, seqA);
EXPECT_EQ(b, seqB);
EXPECT_EQ(c, seqC);
EXPECT_EQ(d, seqEmpty);
EXPECT_EQ(e, seqEmpty);
EXPECT_EQ(f, seqEmpty);
}


// Create markov and check his matrices
TEST(MARKOV, Create_Markov_Test)
{
    Markov m(0.1,0.5,0.75);
    auto change = m.getChangeMatrix();
    auto product = m.getProductMatrix();

    EXPECT_EQ(0.9, change.getValue(0,0));
    EXPECT_EQ(0.9, change.getValue(1,1));
    EXPECT_EQ(0.1, change.getValue(1,0));
    EXPECT_EQ(0.1, change.getValue(0,1));

    EXPECT_EQ(0.5, product.getValue(1,0));
    EXPECT_EQ(0.5, product.getValue(1,1));
    EXPECT_EQ(0.75, product.getValue(0,1));
    EXPECT_EQ(0.25, product.getValue(0,0));

}


// Create markov and check if the given values back in range in his matrices
TEST(MARKOV, Create_Markov_OutRangeValues)
{
    Markov m(-1.0,2.0,-1.1);
    auto change = m.getChangeMatrix();
    auto product = m.getProductMatrix();

    EXPECT_EQ(1.0, change.getValue(0,0));
    EXPECT_EQ(1.0, change.getValue(1,1));
    EXPECT_EQ(0.0, change.getValue(1,0));
    EXPECT_EQ(0.0, change.getValue(0,1));

    EXPECT_EQ(0.0, product.getValue(1,0));
    EXPECT_EQ(1.0, product.getValue(1,1));
    EXPECT_EQ(0.0, product.getValue(0,1));
    EXPECT_EQ(1.0, product.getValue(0,0));


}


// Matrix value test for production probabilities
TEST(MARKOV, Matrix_Chance_Test)
{
    Markov m(0.1,0.5,0.75);

    EXPECT_EQ(0.9, m.changeProbability(Unfair,Unfair));
    EXPECT_EQ(0.9, m.changeProbability(Fair,Fair));
    EXPECT_EQ(0.1, m.changeProbability(Fair,Unfair));
    EXPECT_EQ(0.1,m.changeProbability(Unfair,Fair));

}

// Matrix value test for production probabilities
TEST(MARKOV, Matrix_Prod_Test)
{
    Markov m(0.1,0.4,0.75);

    EXPECT_EQ(0.4, m.prodProbability(Fair,Head));
    EXPECT_EQ(0.6, m.prodProbability(Fair,Tail));
    EXPECT_EQ(0.25, m.prodProbability(Unfair,Tail));
    EXPECT_EQ(0.75, m.prodProbability(Unfair,Head));


}



