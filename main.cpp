/*

G-----C      N E E D L E M A N   A L I G N M E N T
G-----C
 A---T       $ ./align [Sequence-Type] [Gap-Cost] [Fasta-Filename]
  T-A
   T         [Sequence-Type]     -RNA -DNA -PEPTIDE
  C-G        
 A---T       [Gap-Cost]          Integer
G-----C
C-----G      [Fasta-Filename]    Path to a valid Fasta-File (at least 2 Sequences)

*/

using namespace std;

#include "console.h"
#include "sequence/DNA.h"
#include "sequence/Sequence.h"
#include "Matrix.h"
#include "Alignment.h"
#include "Distance.h"
#include "sequence/RNA.h"
#include "sequence/Peptide.h"
#include "sequence/Fasta.h"

#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using DNAs =  Sequence<Alphabet::DNA>;
using PEPTIDEs =  Sequence<Alphabet::Peptide>;
using RNAs =  Sequence<Alphabet::RNA>;







enum SeqType { ERROR , DNA, RNA, PEPTIDE };







int main(int argc, char* argv[]) { 

      // correct arg-count?
        if (argc < 4) { console::Help("ERROR : Not enough arguments!");return 0; }
        if (argc > 4) { console::Help("ERROR : Too many arguments!");return 0; }

      // Argument Variables
        string arg_Seq  = argv[1];
        string arg_Gap  = argv[2];
        string arg_File = argv[3];
        stringstream msg;

      // Program Variables
        int gap_cost = 0;
        int sequence_count = 0;
        SeqType choosenSeqType = ERROR;
        std::vector<DNAs>     stack_DNA;
        std::vector<PEPTIDEs> stack_PEPTIDE;
        std::vector<RNAs>     stack_RNA;


      // Arg 1 : Does the choosen Sequence-Type exists in us world?
        if(arg_Seq == "DNA"     || arg_Seq == "-DNA"     ) {choosenSeqType = DNA;}
        if(arg_Seq == "RNA"     || arg_Seq == "-RNA"     ) {choosenSeqType = RNA;}
        if(arg_Seq == "PEPTIDE" || arg_Seq == "-PEPTIDE" ) {choosenSeqType = PEPTIDE;}
        if(choosenSeqType == ERROR) {msg << "ERROR : invalid Sequence Type { " << arg_Seq << " }";
                                             console::Help(msg.str()); return 0;}


      // Arg 2 : Isn't a weird integer for the Gap-Cost?
        try {gap_cost = stoi(argv[2]);} catch (invalid_argument) {
            msg << "ERROR : invalid integer { "<< arg_Gap << " }";
            console::Help(msg.str()); return 0;}


      // Arg 3 : Does the program like your file?
        std::ifstream input(argv[3]);
	      if(!input) { msg << "ERROR : invalid file { "<< arg_File << " }";
                     console::Help(msg.str());input.close(); return 0;}
        

      // The Program likes your Inputs: we can start!
        console::Title(argv[3],gap_cost);


      // Fasta : Type DNA
        if (choosenSeqType == DNA) {
        DNAs line1;
        DNAs line2;
        input >> fromFasta(line1);
        input >> fromFasta(line2);
        stack_DNA.push_back(line1);
        stack_DNA.push_back(line2);
        sequence_count = stack_DNA.size();
        console::FastaMessage(sequence_count,"DNA","DNA",stack_DNA[0].size(),stack_DNA[1].size());
        if (sequence_count < 2) {return 0;}
        Alignment<Alphabet::DNA,Distance::EditDistance<Alphabet::DNA::Characters>> alinab(gap_cost);
        cout << "\n align: " << alinab(stack_DNA[0],stack_DNA[1]);

        }

    // Fasta : Type RNA
    if (choosenSeqType == RNA) {
        RNAs line1;
        RNAs line2;
        input >> fromFasta(line1);
        input >> fromFasta(line2);
        stack_RNA.push_back(line1);
        stack_RNA.push_back(line2);
        sequence_count = stack_RNA.size();
        console::FastaMessage(sequence_count,"RNA","RNA",stack_RNA[0].size(),stack_RNA[1].size());
        if (sequence_count < 2) {return 0;}
        Alignment<Alphabet::RNA,Distance::EditDistance<Alphabet::RNA::Characters>> alinab(gap_cost);
        cout << "\n align: " << alinab(stack_RNA[0],stack_RNA[1]);

    }

    // Fasta : Type PEPTIDE
    if (choosenSeqType == PEPTIDE) {
        PEPTIDEs line1;
        PEPTIDEs line2;
        input >> fromFasta(line1);
        input >> fromFasta(line2);
        stack_PEPTIDE.push_back(line1);
        stack_PEPTIDE.push_back(line2);
        sequence_count = stack_PEPTIDE.size();
        console::FastaMessage(sequence_count,"PEPTIDE","PEPTIDE",stack_PEPTIDE[0].size(),stack_PEPTIDE[1].size());
        if (sequence_count < 2) {return 0;}
        Alignment<Alphabet::Peptide,Distance::EditDistance<Alphabet::Peptide::Characters>> alinab(gap_cost);
        cout << "\n align: " << alinab(stack_PEPTIDE[0],stack_PEPTIDE[1]);
    }

	return 1;
}


