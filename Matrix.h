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

    Matrix(int cols, int rows);
    int getValue(int col, int row);
    void setValue(int col, int row, int value);
    void print();
    void printTriangle(int col, int row);

    int ROW_MAX();
    int COL_MAX();

protected:

    std::vector<std::vector<int>> values_;

};

int Matrix::ROW_MAX() { return values_.at(0).size()-1; }
int Matrix::COL_MAX() { return values_.size()-1; }

Matrix::Matrix(int cols, int rows) {

    std::vector<int> _rows(rows,3);
    std::vector<std::vector<int>> all(cols,_rows);
    values_ = all;
}

int Matrix::getValue(int col, int row) {return values_.at(col).at(row);}

void Matrix::setValue(int col, int row, int value) {values_.at(col).at(row) = value;}

void Matrix::print() {
    cout << C::BGREEN << "\n MATRIX [ " << C::BBLUE << "cols: " << (COL_MAX()+1) << " rows: " << (ROW_MAX()+1) << C::BGREEN << " ]";
    cout << "\n x " << C::BYELLOW;
    for (int i = 0 ; i <= COL_MAX() ; i++) { cout << i << " ";}

        for (int _row = 0 ; _row <= ROW_MAX() ; _row++) {

            cout << "\n " << C::BYELLOW << _row << C::BRED << " ";

            for (int _col = 0 ; _col <= ROW_MAX() ; _col++) { cout << getValue(_col,_row) << " "; }
    }
    cout << "\n " << C::RESET;

}

void Matrix::printTriangle(int col, int row) {
    int up = getValue(col-1,row);
    int left = getValue(col,row-1);
    int diag = getValue(col-1,row-1);
    cout << C::BBLUE << "[L: " << left << " D: " << diag << " U: " << up << " ]" << C::RESET;
}

#endif //MATRIX_H
