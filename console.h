#ifndef UB5_CONSOLE_H
#define UB5_CONSOLE_H


#include <string>
#include <iostream>

using String = typename std::string;

/*
 * Constants to colorize the console text
 * */
class C {
public:
    using String = typename std::string;
    static const char* RESET;
    static const char* BLUE;
    static const char* BBLUE;
    static const char* BWHITE;
    static const char* BGREEN;
    static const char* BRED;
    static const char* BYELLOW;
    static const char* HBLUE;
    };

const char* C::RESET   = "\033[0m";
const char* C::BLUE    = "\033[0;34m";
const char* C::BBLUE   = "\033[1;34m";
const char* C::BWHITE  = "\033[1;37m";
const char* C::BGREEN  = "\033[1;32m";
const char* C::BRED    = "\033[1;31m";
const char* C::BYELLOW = "\033[1;33m";
const char* C::HBLUE   = "\033[0;94m";




/**
 * Contains Output strings for Console
 * */
class console {
public:
 static void Title(String filename, int cost);
 static void Help(String message);
 static void FastaMessage(int count, String type1, String type2, int seq1, int seq2);
};


void console::Title(String filename, int cost) {
    std::cout << "\n";
    std::cout << C::BYELLOW <<  "     N E E D L E M A N   A L I G N M E N T \n" << C::BLUE;
    std::cout <<                "\n";
    std::cout <<                "\n";
    std::cout <<                "        > Gap Cost   : " << C::BWHITE << cost << C::BLUE <<" \n";
    std::cout <<                "        > Fasta-File : " << C::BWHITE <<  filename << C::BLUE <<" \n";
    std::cout <<                "\n";
    std::cout << C::RESET;
}

void console::FastaMessage(int count, String type1, String type2, int seq1, int seq2) {

    std::cout << C::BBLUE <<    "       => Sequences  : " << C::BWHITE << "found: " << count << C::BLUE << "\n";
    std::cout <<                "                     \n";
    std::cout <<                "       =>     Seq. A : " << C::BYELLOW << " ( length: "  << seq1 << " ) " << C::BWHITE << ": " << type1 << "\n" << C::BLUE;
    std::cout <<                "       =>     Seq. B : " << C::BYELLOW << " ( length: "  << seq2 << " ) " << C::BWHITE << ": " << type2 << "\n" << C::BLUE;
    std::cout <<                "                     \n" << C::BRED;
    if (count < 2) {std::cout<< "       =>     Not Enough sequences: you need 2 for assign\n"; }
    std::cout <<                "\n"  << C::RESET;
}

void console::Help(String message) {
    std::cout << "\n";
    std::cout << C::BYELLOW <<  "     N E E D L E M A N   A L I G N M E N T \n" << C::BLUE;
    std::cout <<                "\n";
    std::cout << C::BRED <<     "        > " << message << "\n";
    std::cout << C::BWHITE  <<  "\n Help:    " << C::BYELLOW << "$ \\.align [Sequence Type] [Gap-Cost] [Fasta-File]";
    std::cout << C::BWHITE  <<  "\n Example: " << C::BGREEN  << "$ \\.align -DNA 2 ../fragments.fasta";
    std::cout <<                "\n";
    std::cout <<                "\n";
    std::cout << C::BWHITE  <<  " Options: " << C::BGREEN <<  "[Sequence Type] := " << C::BBLUE << " -DNA -RNA -PEPTIDE\n";
    std::cout << C::BGREEN  <<  "          [Gap-Cost]      := " << C::BBLUE << " Integer in the range from 0 to whatever\n";
    std::cout << C::BGREEN  <<  "          [Fasta-File]    := " << C::BBLUE << " A valid file in FASTA-format,\n";
    std::cout << C::BGREEN  <<  "                             " << C::BBLUE << " with at least " << C::BRED << "2 Sequences\n\n";
    std::cout << C::RESET;
}

#endif //UB5_CONSOLE_H
