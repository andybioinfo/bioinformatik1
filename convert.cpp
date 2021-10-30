#include "Sequence.h"
#include "DNA.h"
#include "2Bit.h"
#include "Fasta.h"

#include "InvalidCharacter.h"
#include "ParsingException.h"

#include <iostream>
#include <fstream>

bool has_suffix(const std::string& str, const std::string& suffix)
{
	return str.size() >= suffix.size() &&
	       str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

bool convertFiles(const char* infile, std::istream& input, std::ostream& output)
{
	Sequence<Alphabet::DNA> seq;

	if(has_suffix(infile, ".fa")) {
		input >> fromFasta(seq);
		output << to2Bit(seq);
	} else if(has_suffix(infile, ".2bit")) {
		input >> from2Bit(seq);
		output << toFasta(seq);
	} else {
		return false;
	}

	return true;
}

int main(int argc, char* argv[])
{
	if(argc < 3) {
		std::cerr << "Not enough arguments!\nUsage:\n\t" << argv[0]
		          << " chr1.fa chr1.fa.2bit\nor\n\t" << argv[0]
		          << " chr1.fa.2bit chr1.fa\n";

		return -1;
	}

	std::ifstream input(argv[1]);
	std::ofstream output(argv[2]);

	if(!input) {
		std::cerr << "Could not open file " << argv[1] << " for reading!\n";
		return -2;
	}

	if(!output) {
		std::cerr << "Could not open file " << argv[2] << " for writing!\n";
		return -3;
	}

	try {
		if(!convertFiles(argv[1], input, output)) {
			std::cerr << "Could not determine input file type. Make sure your "
			             "input file has the ending '.fa' or '.2bit'.\n";
			return -4;
		}
	} catch(const InvalidCharacter& exn) {
		std::cerr << "Error in input sequence: " << exn.what() << "\n";
		return -5;
	} catch(const ParsingException& exn) {
		std::cerr << "Error in input sequence: " << exn.what() << "\n";
		return -5;
	}

	return 0;
}

