
/*
   V I T E R B I  A L G O R I T M  
    
Input   $ ./viterbi [begin] [change] [unfair] [sequence]
Example $ ./viterbi 0.3 0.1 0.2 0101010111

    Tail   Int = 0
    Head   Int = 1

*/

using namespace std;

#include "console.h"
#include "Coin.h"
#include "Viterbi.h"
#include <vector>
#include <sstream>



#include <iostream>





/*


*/
double Range(double val) {
    if (val > 1.0) { return 1.0; }
    if (val < 0.0) { return 0.0; }
    return val;
 }

/*

*/
std::vector<Flip> String2Sequence(string str) {
    std::vector<Flip> seq;
    for ( char& c : str) {
        // 0 is Tail
        if (c == '0') { seq.push_back(Tail); continue; }
        // 1 is Head
        if (c == '1') { seq.push_back(Head); continue; }
        // other char = return empty List
        seq.clear();
        break;
    }
    return seq;
}




int main(int argc , char* argv[]) {

     // correct arg-count?
        if (argc < 5) { console::Help("ERROR : Not enough arguments!");return 0; }
        if (argc > 5) { console::Help("ERROR : Too many arguments!");return 0; }

      // Argument Variables
        string arg_Begin  = argv[1];
        string arg_Change = argv[2];
        string arg_Unfair = argv[3];
        string arg_Seq    = argv[4];
        stringstream msg;

      // Program Variables
        double p_begin  = 0.0;
        double p_change = 0.0;
        double p_unfair = 0.0;
        std::vector<Flip> sequence;

      // Arg 1 : read and check Begin - Value
        try {p_begin = stod(argv[1]);} catch (invalid_argument) {
            msg << "ERROR : invalid float/double { "<< arg_Begin << " }";
            console::Help(msg.str()); return 0;}

      // Arg 2 : read and check Change - Value
        try {p_change = stod(argv[2]);} catch (invalid_argument) {
            msg << "ERROR : invalid float/double { "<< arg_Change << " }";
            console::Help(msg.str()); return 0;}

      // Arg 3 : read and check Unfair - Value
        try {p_unfair = stod(argv[3]);} catch (invalid_argument) {
            msg << "ERROR : invalid float/double { "<< arg_Unfair << " }";
            console::Help(msg.str()); return 0;}

      // Arg 4 : Convert the String to a sequence
        sequence = String2Sequence(arg_Seq);     
	    if(sequence.size() == 0) {
            msg << "ERROR : invalid char in sequence { only '1' or '0' is valid }";
            console::Help(msg.str()); return 0;}
        
      // all input doubles : Set the doubles in Range from 0.0 <-> 1.0
        p_begin  = Range( p_begin );
        p_change = Range( p_change );
        p_unfair = Range( p_unfair );

      // The Program likes your Inputs: we can start!
        console::ShowHeader();
        console::ShowInputs(p_begin,p_unfair,p_change ,arg_Seq);

      // Viterbi Start

      Viterbi v(p_begin,p_unfair,p_change,sequence);

      v.backtracking();

      console::Result(v.Sequence_toString(true));




    return 0;




}
