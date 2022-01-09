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
#include "../Viterbi.h"
#include "../Markov.h"




// Are all values successfully loaded per constructor in his fields?
TEST(VITERBI, InitTest)
{
    std::vector<Flip> seq;
    seq.push_back(Head);seq.push_back(Tail);seq.push_back(Head);seq.push_back(Head);
    Markov m(0.2,0.5,0.4);
    Viterbi v(m,0.3,seq);
    EXPECT_EQ(4   , v.get_Sequence().size());
    EXPECT_EQ(0   , v.get_Result().size());
    EXPECT_EQ(0.3, v.get_p_begin());
    EXPECT_EQ(0.2, v.get_markov_matrices().changeProbability(Fair,Unfair));
    EXPECT_EQ(0.4, v.get_markov_matrices().prodProbability(Unfair,Tail));
}

// Exception-Test if sequence empty or/and the begin-value out of range
TEST(VITERBI, InitExceptionTest)
{
    std::vector<Flip> seqEmpty;
    std::vector<Flip> seqOne;
    seqOne.push_back(Head);
    Markov m(0.2,0.5,0.4);
    Viterbi empty(m,0.35,seqEmpty);
    EXPECT_EQ(0.10, 9.0);

    Viterbi invalidA(m,2.0e+99,seqEmpty);
    Viterbi invalidB(m,-9000.0,seqEmpty);
    EXPECT_EQ(0.10, 9.0);
}

// Is the Result-sequence-Length the same as the Input-sequence-length
TEST(VITERBI, BacktrackingLength)
{
    std::vector<Flip> seq;
    seq.push_back(Head);seq.push_back(Tail);seq.push_back(Head);seq.push_back(Head);
    Markov m(0.2,0.5,0.3);
    Viterbi v(m,0.35,seq);
    v.backtracking();
    EXPECT_EQ(v.get_Result().size() , v.get_Sequence().size());
}

// No coin change, begin with 100% Fair -> begin with Fair ==> all Coin-throws are fair
TEST(VITERBI, OnlyFairCoinTest)
{
    std::vector<Flip> seq;
    seq.push_back(Head);seq.push_back(Tail);seq.push_back(Head);seq.push_back(Head);seq.push_back(Tail);seq.push_back(Head);
    Markov m(0,0.5,0.8);
    Viterbi v(m,1,seq);
    v.backtracking();
    for (Coin c : v.get_Result()) {
        EXPECT_EQ(Fair, c);
    }
}

// No coin change, begin with 0% Fair -> begin with Unfair ==> all Coin-throws are unfair
TEST(VITERBI, OnlyUnfairCoinTest)
{
    std::vector<Flip> seq;
    seq.push_back(Head);seq.push_back(Tail);seq.push_back(Head);seq.push_back(Head);seq.push_back(Tail);seq.push_back(Head);
    Markov m(0,0.5,0.8);
    Viterbi v(m,0,seq);
    v.backtracking();
    for (Coin c : v.get_Result()) {
        EXPECT_EQ(Fair, c);
    }
}





// Correct HMM-Throw-Result for a given Input-Sequence?
TEST(VITERBI, BacktrackingResult)
{


}


// Correct Matrix-Size after Creating with Constructor?
TEST(VITERBI, HMM_MatrixSize_Test)
{
    std::vector<Flip> seq;
    seq.push_back(Head);seq.push_back(Tail);seq.push_back(Head);seq.push_back(Head);seq.push_back(Tail);seq.push_back(Head);
    Markov m(0,0.5,0.8);
    Viterbi v(m,0,seq);
    auto M = v.getMatrix();
    
    EXPECT_EQ(1, M.Y_MAX());
    EXPECT_EQ(5, M.X_MAX());

}


// Correct Matrix-Values after Creating/Algorithm with Constructor?
TEST(VITERBI, HMM_MatrixValues_Test)
{
    std::vector<Flip> seq;
    seq.push_back(Head);seq.push_back(Tail);
    Markov m(0.1,0.5,0.75);
    Viterbi v(m,0.9,seq);
    auto M = v.getMatrix();
    
    EXPECT_EQ(0.45, M.getValue(0,0));
    

}

// Matrix calculation formula Test
TEST(VITERBI, MatrixFormulaTest)
{
    /*
double res = Viterbi::formula(double p_w_at_coin,double max_a1,double max_a2,double max_b1,double max_b2);
EXPECT_EQ(res, c);

)
*/
}


// Sequence_toString-Test
TEST(VITERBI, Result_toString_Test)
{
  


}
