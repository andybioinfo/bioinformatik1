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


#include "../Alignment.h"
#include "../Alignment.cpp"
#include "../Distance.h"
#include "../Matrix.h"

#include "../sequence/Sequence.h"
#include "../sequence/DNA.h"
#include "../sequence/Peptide.h"
#include "../sequence/RNA.h"
#include "../sequence/DNA.cpp"
#include "../sequence/Peptide.cpp"
#include "../sequence/RNA.cpp"

using namespace Alphabet;


TEST(ALIGN, DNA_Align_Test)
{
    Sequence<DNA> A = Sequence<DNA>::fromString("GGCTAAGGA");
    Sequence<DNA> B = Sequence<DNA>::fromString("GTCAATATT");
}

TEST(ALIGN, PEPTIDE_Align_Test)
{
    Sequence<Peptide> A = Sequence<Peptide>::fromString("IWANTREALLYNICETASTYSVSHI");
    Sequence<Peptide> B = Sequence<Peptide>::fromString("WALEAWANICESTSVSHITYHIHIIIHH");
}

TEST(ALIGN, RNA_Align_Test)
{
    Sequence<RNA> A = Sequence<RNA>::fromString("UAUUAGGC");
    Sequence<RNA> B = Sequence<RNA>::fromString("UAAUUGCC");

}

TEST(ALIGN, Output_Operator_Test)
{


}

TEST(ALIGN, SetGetGapCost_Test)
{


}

TEST(ALIGN, ScoreReturn_Test)
{


}


TEST(DISTANCE, Distance_Operator_Test)
{


}

TEST(DISTANCE, Minimum_Test)
{


}
