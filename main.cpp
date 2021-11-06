/*

G-----C      S E Q U E N C E   A S S E M B L E R
G-----C
 A---T       $ ./Assembler -h -f [Fasta-Filename] -s [optional Output-Directory for intermediate steps]
  T-A
   T         -h  => Show help
  C-G        -f  => Name of your Fasta-File
 A---T       -s  => Intermediate steps will be saved in
G-----C
C-----G

*/

using namespace std;

#include "Assembler.cpp"
#include "Assembler.h"
#include "DNA.cpp"
#include "DNA.h"
#include "Fasta.h"
#include "Graph.h"
#include "InvalidCharacter.cpp"
#include "InvalidCharacter.h"
#include "Peptide.h"
#include "RNA.h"
#include "Sequence.h"
#include "SequenceCombinator.h"
#include "console.h"
#include <dirent.h>
#include <getopt.h>
#include <iostream>
#include <ostream>
#include <string>

using SeqList = std::vector<Sequence<Alphabet::DNA>>;
using Node = Graph<Sequence<Alphabet::DNA>>::Node;
using Edge = Graph<Sequence<Alphabet::DNA>>::Edge;

enum Mode {
	NONE,
	FASTA,
	SAVE
};



int main(int argc, char* argv[]) {

//	SeqList stack = SequenceCombinator(18,22,false); // The fragments.fasta sequences
//	Assembler B(stack);
//cout << B.getGraph();
//auto A = Sequence<Alphabet::DNA>::fromString("CCACATGA");
//auto B = Sequence<Alphabet::DNA>::fromString("TTCCCACA"); //ATGAGGTAGA

//cout << "\n Merge " << A << " + " << B << " -> " << merge(A,B);







//	return 1;



	// ## getopt : Create getopt variables
	Mode Modus = NONE;
	int opt = 1;
	bool wrong_input = false;
	bool help_arg = false;
	bool file_arg = false;
	bool save_arg = false;
	char *infile_arg = NULL;
	char *outfolder_arg = NULL;

	// ## getopt : Look for input via getopt
	// TODO: wie regeln das getopt neben -f -s auch --fasta --save annimmt, falls relevant??
	while ((opt = getopt(argc,argv, "hf:s:")) != -1) {
		switch (opt) {
			case 'h' : help_arg = true;break;
			case 'f' : file_arg = true;infile_arg = optarg;break;
			case 's' : save_arg = true;outfolder_arg = optarg;break;
			default  : if (optopt == 'f')      {file_arg = true;wrong_input = true;}
				else if (optopt == 's') {save_arg = true;}
				else                    {wrong_input = true;}
				break;
		}
	}
	// ## getopt : choose Mode
	if (save_arg) {Modus = SAVE;} else {Modus = FASTA;}

	// ## getopt : Enough Arguments and valid arguments?
	if (argc < 2) {console::InputError("Not enough arguments!");console::Help();return -1;}
	if (wrong_input) {console::InputError("Wrong input!");console::Help();return -1;}
	if (help_arg) {console::Help();return 0;}

	// ## getopt [-f] : Check and store inputfile-name
	if (!file_arg) {console::InputError("Missing -f Argument for load the Input-File! please use -f [Filename]");console::Help();return -1;}
	if (infile_arg == NULL) {console::InputError("No Input-File choosen! please use -f [Filename]");console::Help();return -1;}
	std::ifstream input(infile_arg); /*the input stream*/
	if (!input) {console::InputError("Input-File can't be read : ",infile_arg);console::Help();return -1;}

	// ## getopt [-s] : Folder Check
	char folder[] = "greedy_intermediates\"";
	//if (outfolder_arg == NULL) {folder = "greedy_intermediates";} else {folder = outfolder_arg;} // if no folder choosen
	//DIR* dir = opendir(folder);
	//if (dir) {cout << "\n exist: Testing \n";} else {cout << "\n NOT exist: Testing \n";} // folder already exist?
	// TODO: Wie erstellt man einen Ordner? kein Include der bekannten Bibliotheken möglich. Dateien werden provisorisch in Quellordner geschrieben.
	//std::ofstream outputter("Tester/asd.t"); if (!outputter) {cout << "error\n";}

	// ## Send inputs to Console
	console::InsertFilename(infile_arg);
	if (Modus == FASTA) {console::steps = "[NO]";} else {console::steps = "[YES]";console::InsertFoldername(folder);}
	console::Title();

	// ## Import File and Folder to Assembler
	Assembler Greedy = Assembler::FastaToGreedy(infile_arg,folder,save_arg);

	// ## Start assembling and return Sequence tp console
	console::EndMessage(Greedy.getStepCount());
	cout << C::BYELLOW << "\n > ";
	cout << C::BGREEN << Greedy.assemble() << "\n\n";

	return 1;
}



