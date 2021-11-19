#ifndef ALIGNMENT_H
#define ALIGNMENT_H


//#include <string>
//using String = typename std::string;

#include "sequence/Sequence.h"

/*
 * ???
 * */
class Alignment {

public:

Alignment(int gap_costs);

operator()(const Seq&a, const Seq&b)

friend operator<<();


};




#endif //ALIGNMENT_H
