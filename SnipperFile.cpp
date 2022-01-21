//
// Created by manjaro on 21.01.22.
//

/*

method readData from Exercise a) merged with Constructor.

Exercise 3a): Explanation for chosen especially this data structure for this project?

Answer:

 This cat (and many bugs) like this data-structure:

                 (meow!)
         /\_/\   )/
   ((   (=^.^=)
   ))    )   (
    (( /      \    ' '
     (   ) || ||     ' '
     '----''-''-'  >+++°>

*/

#include <fstream>
#include <sstream>
#include <iostream>
#include "Snipper.h"

Snipper::Snipper() {

}

Snipper::Snipper(std::string filename) {


    // ## Variables

    std::ifstream input(filename);
    char c;
    int first_line_items = 0;
    int col = 0;


    std::stringstream buffer("");
    bool first_line = true;
    bool is_in_row = false;
    bool is_new_line = true;


    // read all chars:
    while(input.get(c)) {


        // are we in a new line?
        if (is_new_line) {

            // ignore the following whitespace chars:
            if (c == '\r' || c == '\t' || c == '\v' || c == '\f' || c == ' ' || c == '\n' ) {continue;}

            if (c == '0') {     _class << Control;
                is_new_line = false;
                is_in_row = true;
                continue;
            }
            if (c == '1') {     _class << Cancer;
                is_new_line = false;
                is_in_row = true;
                continue;
            }

            // other char? -> Abort
            std::cout << "wrong char ( " << c << " )";

        }

        // loop if in row:

        // end of line?
        if (c == '\n' ) {   is_new_line = true;
            col = 0;
            if (first_line) {first_line = false;}
            continue;
        }


        // first line?
        if (first_line) {   if (c == '0' || c == '1' || c == '2') { // valid char -> add new Xi
                SingleSNP Xi(_class);
                _snpstack.push_back(Xi);
                first_line_items++;
            }
        }

        // check in Range?

        //


        // if a valid char
        if (c == '0') {  _snpstack[col] << HomoMajor;
            col ++;
            continue;
        }

        if (c == '1') {  _snpstack[col] << Hetero;
            col ++;
            continue;
        }

        if (c == '2') {  _snpstack[col] << HomoMinor;
            col ++;
            continue;
        }

        // ignore the following whitespace chars:
        if (c == '\r' || c == '\t' || c == '\v' || c == '\f' || c == ' ' || c == '\n' ) {continue;}

        std::cout << "wrong char ( " << c << " )";


    }







}





