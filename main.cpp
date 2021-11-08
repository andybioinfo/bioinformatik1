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
#include <sys/stat.h>

using SeqList = std::vector<Sequence<Alphabet::DNA>>;
using Node = Graph<Sequence<Alphabet::DNA>>::Node;
using Edge = Graph<Sequence<Alphabet::DNA>>::Edge;
using Triple = std::tuple<Node,Node,size_t>;

enum Mode {
	NONE,
	FASTA,
	SAVE
};



int main(int argc, char* argv[]) {

	/* Create Graph
	SeqList stack = SequenceCombinator(18,22,false); // The "Aufgabe 1: Greedy Ansatz" exercise sequences
	Assembler B(stack);
    cout << "unbearbeitet: \n" << B.getGraph(); //   F.D -> F.C  weight: 5


    B.joinLargestEdge();
	cout << "first step" << B.getGraph();

	B.joinLargestEdge();
	cout << B.getGraph();

	B.joinLargestEdge();
	cout << B.getGraph();

	B.joinLargestEdge();
	cout << B.getGraph();

	B.joinLargestEdge();
	cout << B.getGraph();

return 1;*/

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
	std::ifstream input(infile_arg);
	if (!input) {console::InputError("Input-File can't be read : ",infile_arg);console::Help();return -1;}

	// ## getopt [-s] : Folder Check
	stringstream _path("");
	if (outfolder_arg == NULL) {_path << "greedy_intermediates/";} else {_path << outfolder_arg;} // if no folder choosen
	char path_arr[_path.str().size()]; auto iter = _path.str().begin(); // convert string to char array
	for (int i = 0 ; i < _path.str().size() ; i++) {
		path_arr[i] = iter.operator*(); iter++;
	}
if (Modus == SAVE) {
	mkdir(path_arr, 0777); // create folder

	DIR* dir = opendir(path_arr);
if (dir)
{
    /* Directory exists. */
    closedir(dir);
}
else if (ENOENT == errno)
{
    /* Directory does not exist. */
	cout << C::BRED << "\n The folder can't created: '" << _path.str() << "'. your files will created without folder. \n\n" << C::RESET; 
	_path.str("");
}
else
{
    /* opendir() failed for some other reason. */
	cout << C::BRED << "\n The folder can't created: '" << _path.str() << "'. your files will created without folder. \n\n" << C::RESET; 
	_path.str("");
}}


	// ## Send inputs to Console
	console::InsertFilename(infile_arg);
	if (Modus == FASTA) {console::steps = "[NO]";} else {console::steps = "[YES]";save_arg = true;console::InsertFoldername(_path.str());}
	console::Title();

	// ## Import File and Folder to Assembler
	Assembler Greedy = Assembler::FastaToGreedy(infile_arg,_path.str(),save_arg);

	// ## Start assembling and return Sequence to console
	auto result_sequence = Greedy.assemble();

	console::EndMessage(Greedy.getStepCount() - 1);

	cout << C::BYELLOW << "\n > ";

	int nodecount = Greedy.getGraph().numNodes();

	if (nodecount == 1) {
		cout << C::BGREEN << result_sequence << "\n\n" << C::RESET;}
        else if (nodecount == 0) {
			cout << C::BRED << "No merging possible with " << C::BYELLOW << nodecount << C::BRED
			                    << "\n     sequences.\n\n" << C::RESET; }
			else {
				cout << C::BRED << "  Greedy-Algorithm couldn't merge all sequences." << C::BYELLOW << " => Remaining sequences: "  << nodecount << C::BRED
				     << "\n     Choose " << C::BGREEN << "save intermediate-steps" << C::BRED << " for see the remaining sequences,\n     and their overlapping-values up to the last assembled step.\n\n" << C::RESET;
			}

	return 1;
}





