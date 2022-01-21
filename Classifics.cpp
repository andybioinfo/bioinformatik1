//
// Created by manjaro on 21.01.22.
//

#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <random>
#include "Classifics.h"

Classifics::Classifics() {

}


/** Returns a classification on a position of this Y-Vector
 *
 * @return     classification on this position
 * */
Classification Classifics::operator [](int idx) const
{
    return _classifications[idx];
}



/** Returns the count of all classifications in this Y-Vector
 *
 * @return     count of all classification
 * */
int Classifics::count()
{
    return _classifications.size();
}


/** Returns the count of a classification in this Y-Vector
 *
 * @class      Your chosen classification
 * @return     count of this classification
 * */
int Classifics::countOf(Classification clss) {

    int cancer_count    = 0;
    int control_count   = 0;

    for (Classification c : _classifications) {
        if (c == Control) {control_count++;}
        if (c == Cancer)  {cancer_count++;}
    }

    if (clss == Cancer)  { return cancer_count; }
    if (clss == Control) { return control_count; }

    return -1;

}


/** Returns the probability of a classification in this Y-Vector
 *
 * @class      Your chosen classification
 * @return     probability of this classification
 * */
double Classifics::probability(Classification clss) {
    if (_classifications.empty())   {throw std::invalid_argument("your count of classifications is zero!"); }

    int complete_count  = _classifications.size();
    int cancer_count    = 0;
    int control_count   = 0;

    for (Classification c : _classifications) {
        if (c == Control) {control_count++;}
        if (c == Cancer)  {cancer_count++;}
    }

    if (clss == Cancer)  { return (double)cancer_count  / (double)complete_count; }
    if (clss == Control) { return (double)control_count / (double)complete_count; }

    return -1;

}

void Classifics::shuffle() {
    auto rd = std::random_device();
    auto rng = std::default_random_engine(rd());
    std::shuffle(std::begin(_classifications),std::end(_classifications),rng);
}

std::string Classifics::to2String() {
std::stringstream res("");
    res <<"Y(size:"<< _classifications.size() << ") { ";
for (Classification c : _classifications) {
    res << c;
}
res << " }";
return res.str();
}

