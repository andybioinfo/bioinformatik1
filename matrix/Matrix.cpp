#include <iostream>
#include "Matrix.h"


/*
 * Max value x matrix-object
 * @return the maximum x value of the columns
 * */
int Matrix::X_MAX() {
    return values_.at(0).size()-1;
}


/*
 * Max value y matrix-object
 * @return the maximum y value of the rows
 * */
int Matrix::Y_MAX() {
    return values_.size()-1;
}


/*
 * Constructor for build the matrix-object
 * @y the count of the rows
 * @x the count of the columns
 * */
Matrix::Matrix(int y, int x) {
    std::vector<double> _rows(x,0);
    std::vector<std::vector<double>> all(y,_rows);
    values_ = all;
}


/*
 * Returns a value from the matrix-object
 * @return value at (X,Y)
 * */
double Matrix::getValue(int y, int x) {
    if ( x<0 || x > X_MAX() || y<0 || y > Y_MAX()){
        std::stringstream s("");
        s << "Wow your wanted Matrix-position is over all thinkable borders :D . \nMax(y,x) is := (" << Y_MAX() << " , "<< X_MAX() << ") \n Your input(y,x) := " << y << " ; " << x;
        throw std::invalid_argument( s.str() );}
    return values_.at(y).at(x);
}


/*
* Set a new value at the matrix-object
 * @y the position at the rows
 * @x the position at the columns
* */
void Matrix::setValue(int y, int x, double value) {
    if ( x<0 || x > X_MAX() || y<0 || y > Y_MAX()){
        std::stringstream s("");
        s << "Wow your Matrix-position to set your value is over all thinkable borders :D . \nMax(y,x) is := (" << Y_MAX() << " , "<< X_MAX() << ") \n Your input(y,x) = " << y << " ; " << x;
        throw std::invalid_argument( s.str() );}
    values_.at(y).at(x) = value;
}

/* Convert a number in a String with
 * a constant String length (for tables ect.) Example: 0.023 -> "    0.023"
 *
 * @x      int
 * @return String of length 9
 * */
std::string Matrix::int2String(int x) {
    std::ostringstream out;
    out.width(9);
    out.precision(4);
    out << x;
    return out.str();
}

/* Convert a number in a String with
 * a constant String length (for tables ect.) Example: 0.023 -> "    0.023"
 *
 * @x      double
 * @return String of length 9
 * */
std::string Matrix::double2String(double x) {
    std::ostringstream out;
    out.width(9);
    out.precision(4);
    out << x;
    return out.str();
}

/*
 * Prints the matrix to std::cout for see the dimensions and the
 * values
* */
void Matrix::print() {
    cout << C::BGREEN << "\n MATRIX [ " << C::BBLUE << "X_cols: " << (X_MAX()+1) << " Y_rows: " << (Y_MAX()+1) << C::BGREEN << " ]";
    cout << "\n x " << C::BYELLOW;
    for (int x = 0 ; x <= X_MAX() ; x++) { cout << int2String(x) << " ";}

    for (int _y = 0 ; _y <= Y_MAX() ; _y++) {

        cout << "\n " << C::BYELLOW << _y << C::BRED << " ";

        for (int _x = 0 ; _x <= X_MAX() ; _x++) {
            cout << double2String(getValue(_y,_x)) << " ";
        }

    }
    cout << "\n " << C::RESET;

}
