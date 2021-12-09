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

    Alignment<Alphabet::DNA,Distance::EditDistance<Alphabet::DNA::Characters>> alinab(2);
    EXPECT_EQ(6, alinab(A,B));
}

TEST(ALIGN, PEPTIDE_Align_Test)
{
    Sequence<Peptide> A = Sequence<Peptide>::fromString("IWANT");
    Sequence<Peptide> B = Sequence<Peptide>::fromString("W");
    
    Alignment<Alphabet::Peptide,Distance::EditDistance<Alphabet::Peptide::Characters>> alinab(2);
    EXPECT_EQ(5, alinab(A,B));
}

TEST(ALIGN, RNA_Align_Test)
{
    Sequence<RNA> A = Sequence<RNA>::fromString("UAUUAGGC");
    Sequence<RNA> B = Sequence<RNA>::fromString("UAAUUGCC");

    Alignment<Alphabet::RNA,Distance::EditDistance<Alphabet::RNA::Characters>> alinab(2);
    EXPECT_EQ(3, alinab(A,B));

}

TEST(ALIGN, Output_Operator_Test)
{
    Sequence<DNA> A = Sequence<DNA>::fromString("TGATCG");
    Sequence<DNA> B = Sequence<DNA>::fromString("TGCATG");

    Alignment<Alphabet::DNA,Distance::EditDistance<Alphabet::DNA::Characters>> alinab(2);
    EXPECT_EQ(3, alinab(A,B));


    std::string compstr =  "\n A | TG-AT CG\n B | TGCAT -G\n";

    std::stringstream comp_a("");
    std::stringstream comp_b("");
    comp_a << compstr;
    comp_b << alinab;

    ASSERT_TRUE(comp_a.str() == comp_b.str());

}

TEST(ALIGN, SetGetGapCost_Test)
{
	Alignment<Alphabet::DNA,Distance::EditDistance<Alphabet::DNA::Characters>> alinab(5);
	EXPECT_EQ(5, alinab.get_GAP_COST());

}

TEST(ALIGN, ScoreReturn_Test)
{
    Sequence<DNA> A = Sequence<DNA>::fromString("GGCTAAGGA");
    Sequence<DNA> B = Sequence<DNA>::fromString("GTCAATATT");

    Alignment<Alphabet::DNA,Distance::EditDistance<Alphabet::DNA::Characters>> alinab(2);
    EXPECT_EQ(6, alinab(A,B));
}


TEST(DISTANCE, Distance_Operator_Test)
{
    Distance::EditDistance<Alphabet::DNA::Characters> D;

    EXPECT_EQ(0, D.operator()(Alphabet::DNA::Characters::A,Alphabet::DNA::Characters::A));
    EXPECT_EQ(1, D.operator()(Alphabet::DNA::Characters::C,Alphabet::DNA::Characters::A));

}

TEST(DISTANCE, Minimum_Test)
{
    Distance::EditDistance<Alphabet::DNA::Characters> D;

    ASSERT_TRUE(D.is_A_minValue(1,2,3));
    ASSERT_TRUE(D.is_A_minValue(2,2,3));
    ASSERT_FALSE(D.is_A_minValue(2,3,1));
    ASSERT_FALSE(D.is_A_minValue(2,1,1));
    ASSERT_TRUE(D.is_A_minValue(2,2,3));
}
