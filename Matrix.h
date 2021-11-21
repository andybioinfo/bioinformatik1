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
#include "console.h"
#include "sequence/Sequence.h"
#include "Distance.h"
using namespace std;

class Matrix {
public:

    Matrix(int y, int x);
    int getValue(int y, int x);
    void setValue(int y, int x, int value);
    void print();
    void printTriangle(int col, int row);

    int Y_MAX();
    int X_MAX();

protected:

    std::vector<std::vector<int>> values_;

};

int Matrix::Y_MAX() { return values_.at(0).size()-1; }
int Matrix::X_MAX() { return values_.size()-1; }

Matrix::Matrix(int y, int x) {

    std::vector<int> _rows(x,0);
    std::vector<std::vector<int>> all(y,_rows);
    values_ = all;
}

int Matrix::getValue(int y, int x) {return values_.at(y).at(x);}

void Matrix::setValue(int y, int x, int value) {values_.at(y).at(x) = value;}

void Matrix::print() {
    cout << C::BGREEN << "\n MATRIX [ " << C::BBLUE << "X_cols: " << (X_MAX()+1) << " Y_rows: " << (Y_MAX()+1) << C::BGREEN << " ]";
    cout << "\n x " << C::BYELLOW;
    for (int x = 0 ; x <= X_MAX() ; x++) { cout << x << " ";}

    for (int _y = 0 ; _y <= Y_MAX() ; _y++) {

        cout << "\n " << C::BYELLOW << _y << C::BRED << " ";

        for (int _x = 0 ; _x <= X_MAX() ; _x++) {
            cout << getValue(_y,_x) << " ";
        }

    }
    cout << "\n " << C::RESET;

}

void Matrix::printTriangle(int col, int row) {
    int up = getValue(col,row-1);
    int left = getValue(col-1,row);
    int diag = getValue(col-1,row-1);
    cout << C::BBLUE << "[L: " << left << " D: " << diag << " U: " << up << " ]" << C::RESET;
}

#endif //MATRIX_H
