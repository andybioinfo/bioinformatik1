#include "DNA.h"

#include "InvalidCharacter.h"

#include <cassert>
//#include <std>
#include <iostream>

namespace Alphabet
{
DNA::Characters DNA::toCharacter(char c)
{ std::cout << "read { " << (int)c << " }";
	switch (c) {
		case 'A':
			return Characters::A;
		case 'a':
			return Characters::a;
		case 'T':
			return Characters::T;
		case 't':
			return Characters::t;
		case 'G':
			return Characters::G;
		case 'g':
			return Characters::g;
		case 'C':
			return Characters::C;
		case 'c':
			return Characters::c;
		case 'N':
		case 'n':
			return Characters::N;
        case '-':
            return Characters::GAP;
		default:
			return Characters::N;
	}
}

char DNA::toChar(Characters c)
{
	switch (c) {
		case Characters::A:
			return 'A';
		case Characters::a:
			return 'a';
		case Characters::T:
			return 'T';
		case Characters::t:
			return 't';
		case Characters::G:
			return 'G';
		case Characters::g:
			return 'g';
		case Characters::C:
			return 'C';
		case Characters::c:
			return 'c';
		case Characters::N:
			return 'N';
        case Characters::GAP:
            return '-';
        default: return '_';
	}

	assert("Unhandled character in DNA::toChar" && false);
}

DNA::Characters DNA::canonicalize(Characters c)
{
	switch(c) {
		case Characters::a:
			return Characters::A;
		case Characters::t:
			return Characters::T;
		case Characters::g:
			return Characters::G;
		case Characters::c:
			return Characters::C;
		default:
			return c;
	}
}

}
