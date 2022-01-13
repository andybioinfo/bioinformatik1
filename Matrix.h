#ifndef MATRIX_H
#define MATRIX_H

/*
 
  ####  M A T R I X - C L A S S

 Example:

 Matrix (4,4) creates a 4 column x 4 rows matrix
 with zeros as default values.


   a b c d
 a 0 0 0 0
 b 0 0 0 0
 c 0 0 0 0
 d 0 0 0 0

  */

#include <vector>
#include <sstream>
#include "console.h"
#include "Color.h"


using namespace std;

class Matrix {
public:

    Matrix(int y, int x);

    double getValue(int y, int x);

    void setValue(int y, int x, double value);

    void print();

    int Y_MAX();

    int X_MAX();

    static std::string int2String(int x) ;
    static std::string double2String(double x);

protected:

    std::vector<std::vector<double>> values_;

};




#endif //MATRIX_H
