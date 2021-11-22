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


TEST(ALIGN_MATRIX, init)
{
	std::cout << "> GTAATC";
    
}

