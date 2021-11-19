/*

G-----C      N E E D L E M A N   A L I G N M E N T
G-----C
 A---T       $ ./Align [Gap-Cost] [Fasta-Filename]
  T-A
   T         
  C-G        
 A---T       
G-----C
C-----G

*/

using namespace std;

#include "console.h"
#include "sequence/DNA.h"
#include "sequence/Sequence.h"
#include "Matrix.h"

#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using Seq = Sequence<Alphabet::DNA>;
using String = std::string;
using SeqStack = std::vector<Seq>;

SeqStack loadFasta(char* inputfile);


int main(int argc, char* argv[]) {

      // Start Variables
        int gap_cost = 0;
        stringstream str_buff;
        string buffer = argv[1];
        stringstream sequence_type;
        int sequence_count = 0;

      // correct arg-count?
        if (argc < 3) { console::Help("ERROR : Not enough arguments!");return 0; }
        if (argc > 3) { console::Help("ERROR : Too many arguments!");return 0; }
        
      // Arg 1 : Is not a weird integer?
        try {gap_cost = stoi(argv[1]);} catch (invalid_argument) {
            str_buff << "ERROR : invalid integer { "<< buffer << " }";
            console::Help(str_buff.str()); return 0;}
        
      // Arg 2 : Does the program like your file?
        std::ifstream input(argv[2]);
	      if(!input) { str_buff << "ERROR : invalid file { "<< buffer << " }";
                     console::Help(str_buff.str());input.close(); return 0;}
        input.close();

      // The Program likes your Inputs: we can start!
        console::Title(argv[2],gap_cost);

      // Fasta : Load the sequences from the Fasta-File
        SeqStack sequences = loadFasta(argv[2]);
        sequence_count = sequences.size();
        if (sequence_count < 1) { console::FastaMessage(0,"missing","missing",0,0);return 0; }
        if (sequence_count < 2) { console::FastaMessage(1,"DNA","missing",sequences[0].size(),0); return 0; }
        console::FastaMessage(sequences.size(),"DNA","DNA",sequences[0].size(),sequences[1].size());

      //

        Matrix M(4, 5);
        M.print();



      // Alignment
        //Alignment<Alphabet::DNA, Distance::EditDistance<Alphabet::DNA::Characters>>

 
	return 1;
}





/**
 *  Load the Sequences from a FASTA-FILE
 *
 * */
SeqStack loadFasta(char* inputfile) {

    // insert file
    std::ifstream input(inputfile);

	// Create Sequences-Container
	std::vector<Sequence<Alphabet::DNA>> stack;

	// Loop-Variables
	std::string line;
	Sequence<Alphabet::DNA> first_seq;
	stack.push_back(first_seq);

	// First line '>'
	char first;
	// if (first != '>') {return;}
	while (getline(input, line))
	{
		line.erase(0, 1);
		stack.back().setComment(line);
		break;
	}

	// ## File-Loop ##
	while (getline(input, line))
	{
		// read first char
		first = line.front();
		// Comment-Line
		if (first == '>')
		{ // if Comment-Line => next Sequence...
			Sequence<Alphabet::DNA> next_seq;
			stack.push_back(next_seq);
			line.erase(0, 1);
			stack.back().setComment(line);
			continue; // next loop step
		}
		// No Comment-Line
		for (auto c : line)
		{
			stack.back().push_back(Alphabet::DNA::toCharacter(c));
		}
	}

    input.close();

	return stack;

}