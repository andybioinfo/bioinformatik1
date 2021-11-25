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


TEST(ALIGN_MATRIX, CreateMatrix_test)
{
	auto ma = Matrix(3, 3);
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
		EXPECT_EQ(0, ma.getValue(i, j));
		}
	}
    
}

TEST(ALIGN_MATRIX, GetSetValue_test)
{
	auto ma = Matrix(5, 7);
	ma.setValue(3, 2, 5);
	EXPECT_EQ(5, ma.getValue(3, 2));
	EXPECT_THROW(ma.getValue(10, 4),std::invalid_argument);
	EXPECT_THROW(ma.setValue(-1, 4, 2),std::invalid_argument);
}

TEST(ALIGN_MATRIX, YX_MAX_test)
{
	auto ma = Matrix(5, 7);
	EXPECT_EQ(6, ma.X_MAX());
	EXPECT_EQ(4, ma.Y_MAX());
}
