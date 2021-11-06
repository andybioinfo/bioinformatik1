#ifndef UB2_CONSOLE_H
#define UB2_CONSOLE_H


#include <string>
using String = typename std::string;

/*
 * Constants to colorize the console text
 * */
class C {
public:
    using String = typename std::string;
    static const String RESET;
    static const String BLUE;
    static const String BBLUE;
    static const String BWHITE;
    static const String BGREEN;
    static const String BRED;
    static const String BYELLOW;
    static const String HBLUE;
    };

const String C::RESET   = "\e[0m";
const String C::BLUE    = "\e[0;34m";
const String C::BBLUE   = "\e[1;34m";
const String C::BWHITE  = "\e[1;37m";
const String C::BGREEN  = "\e[1;32m";
const String C::BRED    = "\e[1;31m";
const String C::BYELLOW = "\e[1;33m";
const String C::HBLUE   = "\e[0;94m";

/**
 * Contains Output strings for Console
 * */
class console {
public:
 static void Title();
 static void Help();
 static void EndMessage(int stp);
 static void InputError(String message);
 static void InputError(String message,char* message2);
 static void InsertFilename(char* file);
 static void InsertFoldername(char* foldername);
 static String filename;
 static String folder;
 static String steps;
 static String message;
};

String console::filename   = "";
String console::folder     = "[no file output]";
String console::steps      = "";
String console::message    = "";

void console::Title() {
    std::cout << "\n";
    std::cout << C::BLUE << " G-----C "<<C::BYELLOW<<"     S E Q U E N C E   A S S E M B L E R \n" << C::BLUE;
    std::cout << " G-----C \n";
    std::cout << "  A---T  \n";
    std::cout << "   T-A        > Input  : '" << filename << C::BLUE <<" \n";
    std::cout << "    T         > Output : '" << folder << C::BLUE <<" \n";
    std::cout << "   C-G        > Save intermediate steps   : " << steps << C::BLUE <<" \n";
    std::cout << "  A---T  \n" << C::RESET;
}

void console::EndMessage(int stp) {
    std::cout << C::BLUE  << " G-----C " << C::BYELLOW << "     => Assembled Sequence: " << C::BLUE << " (intermediate steps: " << stp << ")" << " \n";
    std::cout << C::BLUE  << " C-----G \n"  << C::RESET;

}

void console::Help() {
    std::cout <<  C::BYELLOW <<"               S E Q U E N C E   A S S E M B L E R \n" << C::RESET;
    std::cout << "\n";
    std::cout << "   -h Help         | show this help \n";
    std::cout << "   -f Fasta-File   | the File to be assembled.      Example: --f \"../fragments.fasta\" \n";
    std::cout << "   -s Save         | saves all intermediate steps.  Example: --s \"out/\" \n";
}

void console::InputError(String message) {
    std::cout << "\n" << C::BRED << message << C::RESET;
    std::cout << "\n";
}

void console::InputError(String message,char* message2) {
    std::cout << "\n" << C::BRED << message << message2 << C::RESET;
    std::cout << "\n";
}

void console::InsertFoldername(char *foldername) {
    String S(foldername);
    folder = S;
}

void console::InsertFilename(char *file) {
    String S(file);
    filename = S;
}

#endif //UB2_CONSOLE_H
