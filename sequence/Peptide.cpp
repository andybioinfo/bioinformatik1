#include "Peptide.h"

#include "InvalidCharacter.h"

#include <cassert>

namespace Alphabet
{
Peptide::Characters Peptide::toCharacter(char c)
{
	switch (c) {
		case 'A':
		case 'a':
			return Characters::Ala;
		case 'R':
		case 'r':
			return Characters::Arg;
		case 'N':
		case 'n':
			return Characters::Asn;
		case 'D':
		case 'd':
			return Characters::Asp;
		case 'C':
		case 'c':
			return Characters::Cys;
		case 'Q':
		case 'q':
			return Characters::Gln;
		case 'E':
		case 'e':
			return Characters::Glu;
		case 'G':
		case 'g':
			return Characters::Gly;
		case 'H':
		case 'h':
			return Characters::His;
		case 'I':
		case 'i':
			return Characters::Ile;
		case 'L':
		case 'l':
			return Characters::Leu;
		case 'K':
		case 'k':
			return Characters::Lys;
		case 'M':
		case 'm':
			return Characters::Met;
		case 'F':
		case 'f':
			return Characters::Phe;
		case 'P':
		case 'p':
			return Characters::Pro;
		case 'S':
		case 's':
			return Characters::Ser;
		case 'T':
		case 't':
			return Characters::Thr;
		case 'W':
		case 'w':
			return Characters::Trp;
		case 'Y':
		case 'y':
			return Characters::Tyr;
		case 'V':
		case 'v':
			return Characters::Val;
		default:
			throw InvalidCharacter(c);
	}
}

char Peptide::toChar(Peptide::Characters c)
{
	switch (c) {
		case Characters::Ala:
			return 'A';
		case Characters::Arg:
			return 'R';
		case Characters::Asn:
			return 'N';
		case Characters::Asp:
			return 'D';
		case Characters::Cys:
			return 'C';
		case Characters::Gln:
			return 'Q';
		case Characters::Glu:
			return 'E';
		case Characters::Gly:
			return 'G';
		case Characters::His:
			return 'H';
		case Characters::Ile:
			return 'I';
		case Characters::Leu:
			return 'L';
		case Characters::Lys:
			return 'K';
		case Characters::Met:
			return 'M';
		case Characters::Phe:
			return 'F';
		case Characters::Pro:
			return 'P';
		case Characters::Ser:
			return 'S';
		case Characters::Thr:
			return 'T';
		case Characters::Trp:
			return 'W';
		case Characters::Tyr:
			return 'Y';
		case Characters::Val:
			return 'V';
	}

	assert("Unhandled character in Peptide::toCharacter" && false);
}
}
