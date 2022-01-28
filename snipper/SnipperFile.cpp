//
// Created by manjaro on 21.01.22.
//

/*


1. Explanation for this Data-Structure is in exercise-solution-pdf-file of this exercise-sheet.


2. The method readData from Exercise a) is merged with Constructor.
   -> Snipper::Snipper(std::string filename)
   

3. This cat (and many bugs) like this data-structure:

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
#include "../console/Format.h"



Snipper::Snipper() { // Default Constructor

}


/** read a file with a SNP matrix
 *
 * @filename     SNP-File
 * */
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



/** write the results of the SNP-Algorithm in a file
 *
 * @output_file     File
 * */
void Snipper::outputSNP(std::string output_file) {

    std::ofstream output(output_file);
    output << "SNP Output: (SNP's <= 0.05)\n";
    output << "\n";
    output << "F = Fraction of Information \nP = P-Value\n";
    output << "\n";
    output << "Result significance :=   " << _resultA_SNP_id.size() << " / "<< _snpstack.size() << " SNP's \n";
    output << "\n";
    output << "______SNP_|___P-Value_|____Ref F_\n";
    int idx = 0;
    while (idx < (int)_resultA_SNP_id.size()) {
        output << Format::int2String(_resultA_SNP_id[idx])     << " | ";
        output << Format::double2String(_resultA_p_value[idx]) << " | ";
        output << Format::double2String(_resultA_ref_F[idx])   << "\n";
        idx++;
    }

    output << "\n\n";
    output << "Result Adjustment   :=  " << _resultB_SNP_id.size() << " / "<< _snpstack.size() << " SNP's \n";
    output << "\n";
    output << "______SNP_|___P-Value_|____Ref F_\n";
    idx = 0;
    while (idx < (int)_resultB_SNP_id.size()) {
        output << Format::int2String(_resultB_SNP_id[idx])     << " | ";
        output << Format::double2String(_resultB_p_value[idx]) << " | ";
        output << Format::double2String(_resultB_ref_F[idx])   << "\n";
        idx++;
    }
output.close();
}
