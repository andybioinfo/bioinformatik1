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
#include "../EditDistance.h"
#include "../Distance.h"
#include "../Matrix.h"

using namespace Alphabet;


TEST(ALIGN_MATRIX, init)
{
	std::cout << "> GTAATC";
    
}

TEST(ALIGN_MATRIX, init2){
	auto ma = Matrix::Matrix(5, 7);
	EXPECT_EQ(7, ma.X_MAX);
	EXPECT_EQ(5, ma.Y_MAX);
	ma.setValue(3, 2, 5);
	EXPECT_EQ(5, ma.getValue(3, 2));

	EXPECT_THROW(ma.getValue(10, 4), std::invalid_argument( "out of bounds" ));

}
