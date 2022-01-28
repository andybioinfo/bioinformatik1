//
// Created by manjaro on 28.01.22.
//

#ifndef BAYES_BLOCK_H
#define BAYES_BLOCK_H

#include <vector>

class Block {

public:

    std::vector<int> interval; // List of Patient-IDs
    bool trained = false;      // is this block already trained ?
    bool tested  = false;      // is this block already tested  ?
    int size() const {return (int)interval.size();} // count of patients in this list

};

#endif //BAYES_BLOCK_H
