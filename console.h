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
 static void Title();
 static void Help();
 static void EndMessage(int stp);
 static void InputError(String message);
 static void InputError(String message,char* message2);
 static void InsertFilename(char* file);
 static void InsertFoldername(std::string foldername);
 static String filename;
 static String folder;
 static String steps;
 static String message;
};

String console::filename   = "";
String console::folder     = "[no folder output]";
String console::steps      = "";
String console::message    = "";

void console::Title() {
    std::cout << "\n";
    std::cout << C::BLUE << " G-----C "<<C::BYELLOW<<"     S E Q U E N C E   A S S E M B L E R \n" << C::BLUE;
    std::cout << " G-----C \n";
    std::cout << "  A---T  \n";
    std::cout << "   T-A        > Input  : " << filename << C::BLUE <<" \n";
    std::cout << "    T         > Output : " << folder << C::BLUE <<" \n";
    std::cout << "   C-G        > Save intermediate steps   : " << steps << C::BLUE <<" \n";
    std::cout << "  A---T  \n" << C::RESET;
}

void console::EndMessage(int stp) {
    std::cout << C::BLUE  << " G-----C " << C::BYELLOW << "     => Assembled Sequence: " << C::BLUE << " (intermediate steps: " << stp << ")" << " \n";
    std::cout << C::BLUE  << " C-----G \n"  << C::RESET;

}

void console::Help() {
    std::cout << "\n" << C::BYELLOW <<"               S E Q U E N C E   A S S E M B L E R \n" << C::RESET;
    std::cout << "\n";
    std::cout << "   -h Help         | show this help \n";
    std::cout << "   -f Fasta-File   | the File to be assembled.      Example: -f \"../fragments.fasta\" \n";
    std::cout << "   -s Save         | saves all intermediate steps.  Example: -s \"out/\" \n";
}

void console::InputError(String message) {
    std::cout << "\n" << C::BRED << message << C::RESET;
    std::cout << "\n";
}

void console::InputError(String message,char* message2) {
    std::cout << "\n" << C::BRED << message << message2 << C::RESET;
    std::cout << "\n";
}

void console::InsertFoldername(std::string foldername) {
    folder = foldername;
}

void console::InsertFilename(char *file) {
    String S(file);
    filename = S;
}

#endif //UB2_CONSOLE_H
