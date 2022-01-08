
/*
   V I T E R B I  A L G O R I T M  
    
Input   $ ./viterbi [begin] [change] [unfair] [sequence]
Example $ ./viterbi 0.3 0.1 0.2 0101010111

    Tail   Int = 0
    Head   Int = 1

*/

using namespace std;

#include <vector>
#include <sstream>

#include <iostream>
#include "Format.h"
#include "console.h"
#include "Coin.h"
#include "Markov.h"
#include "Viterbi.h"

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
        try {p_begin = stod(argv[1]);} catch (const std::invalid_argument&) {
            msg << "ERROR : invalid float/double { "<< arg_Begin << " }";
            console::Help(msg.str()); return 0;}

      // Arg 2 : read and check Change - Value
        try {p_change = stod(argv[2]);} catch (const std::invalid_argument&) {
            msg << "ERROR : invalid float/double { "<< arg_Change << " }";
            console::Help(msg.str()); return 0;}

      // Arg 3 : read and check Unfair - Value
        try {p_unfair = stod(argv[3]);} catch (const std::invalid_argument&) {
            msg << "ERROR : invalid float/double { "<< arg_Unfair << " }";
            console::Help(msg.str()); return 0;}

      // Arg 4 : Convert the String to a sequence
        sequence = Markov::String2Sequence(arg_Seq);
	    if(sequence.size() == 0) {
            msg << "ERROR : invalid char in sequence { only '1' or '0' is valid }";
            console::Help(msg.str()); return 0;}
        
      // all input doubles : Set the doubles in Range from 0.0 <-> 1.0
        p_begin  = Markov::Range( p_begin );
        p_change = Markov::Range( p_change );
        p_unfair = Markov::Range( p_unfair );

      // The Program likes your Inputs: we can start!
        console::ShowHeader();
        console::ShowInputs(p_begin,p_unfair,p_change ,arg_Seq);

      // Viterbi Start

      Markov _markov(p_change,0.5,(1.0-p_unfair));

      Viterbi v(_markov,p_begin,sequence);

      v.backtracking();

      console::Result(v.Sequence_toString(true));




    return 0;




}
