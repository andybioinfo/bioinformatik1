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

// Are all values successfully loaded per constructor in his fields?
TEST(VITERBI, InitTest)
{
    std::vector<Flip> seq;
    seq.push_back(Head);seq.push_back(Tail);seq.push_back(Head);seq.push_back(Head);
    Viterbi v(0.25,0.35,0.10,seq);
    EXPECT_EQ(4   , v.get_Sequence().size());
    EXPECT_EQ(0   , v.get_Result().size());
    EXPECT_EQ(0.25, v.get_p_begin());
    EXPECT_EQ(0.35, v.get_p_unfair());
    EXPECT_EQ(0.10, v.get_p_change());
}

// Exception-Test if sequence empty or/and the values out of range
TEST(VITERBI, InitExceptionTest)
{
    std::vector<Flip> seqEmpty;
    std::vector<Flip> seqOne;
    seqOne.push_back(Head);

    Viterbi empty(0.25,0.35,0.40,seqEmpty);
    EXPECT_EQ(0.10, 9.0);

    Viterbi invalidA(0.25,-9000.0,2.0e+99,seqOne);
    Viterbi invalidB(0.25,-9000.0,1.0,seqOne);
    Viterbi invalidC(100.0,0.0,1.0,seqOne);
    EXPECT_EQ(0.10, 9.0);
}

// Is the Result-sequence-Length the same as the Input-sequence-length
TEST(VITERBI, BacktrackingLength)
{
    std::vector<Flip> seq;
    seq.push_back(Head);seq.push_back(Tail);seq.push_back(Head);seq.push_back(Head);
    Viterbi v(0.25,0.35,0.10,seq);
    v.backtracking();
    EXPECT_EQ(v.get_Result().size() , v.get_Sequence().size());
}

// No coin change, begin with 1ẞ0% Fair -> begin with Fair ==> all Coin-throws are fair
TEST(VITERBI, OnlyFairCoinTest)
{
    std::vector<Flip> seq;
    seq.push_back(Head);seq.push_back(Tail);seq.push_back(Head);seq.push_back(Head);seq.push_back(Tail);seq.push_back(Head);
    Viterbi v(1.0,0.0,0.0,seq);
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
    Viterbi v(0.0,1.0,0.0,seq);
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


}


// Correct Matrix-Values after Creating/Algorithm with Constructor?
TEST(VITERBI, HMM_MatrixValues_Test)
{


}




// Sequence_toString-Test
TEST(VITERBI, Result_toString_Test)
{


}
