#ifndef UB10_CONSOLE_H
#define UB10_CONSOLE_H

#include <string>
#include <iostream>

/*
 * Constants to colorize the console text
 * */
class C {
public:

    static const char* RESET;
    static const char* BLUE;
    static const char* BBLUE;
    static const char* BWHITE;
    static const char* BGREEN;
    static const char* GREEN;
    static const char* BRED;
    static const char* RED;
    static const char* BYELLOW;
    static const char* YELLOW;
    static const char* HBLUE;
    };

const char* C::RESET   = "\033[0m";
const char* C::BLUE    = "\033[0;34m";
const char* C::BBLUE   = "\033[1;34m";
const char* C::BWHITE  = "\033[1;37m";
const char* C::BGREEN  = "\033[1;32m";
const char* C::GREEN  = "\033[0;32m";
const char* C::BRED    = "\033[1;31m";
const char* C::RED    = "\033[0;31m";
const char* C::BYELLOW = "\033[1;33m";
const char* C::YELLOW  = "\033[0;33m";
const char* C::HBLUE   = "\033[0;94m";

/**
 * Contains Output strings for Console
 * */
class console {
public:
 static void ShowHeader();
 static void Help(std::string message);
 static void ShowInputs(double begin, double unfair, double change , std::string sequence) ;
 static void Result(std::string res);
};

/*
* sends a big-font Ascii-Art-Header to std::cout
* */
void console::ShowHeader() {
    std::cout << "\n" << C::BGREEN ;
    std::cout << " ____   ____ __  __              ___     __          " << "\n";
    std::cout << " \\   \\ /   /|__|/  |_  __________\\_ |__ |__|         " << "\n";
    std::cout << "  \\   Y   / |  \\   __\\/ __ \\_  __ \\ __ \\|  |         " << "\n";
    std::cout << "   \\     /  |  ||  | \\  ___/|  | \\/ \\_\\ \\  |         " << "\n";
    std::cout << "    \\___/   |__||__|  \\___  >__|  |___  /__|         " << "\n";
    std::cout << "          __              \\/        __\\/__           " << "\n";
    std::cout << "  _____  |  |    ____   ___________|__|/  |_  _____  " << "\n";
    std::cout << "  \\__  \\ |  |   / ___\\ /  _ \\_  __ \\  \\   __\\/     \\ " << "\n";
    std::cout << "   / __ \\|  |__/ /_/  >  <_> >  | \\/  ||  | |  Y Y  \\" << "\n";
    std::cout << "  (____  /____/\\___  / \\____/|__|  |__||__| |__|_|  /" << "\n";
    std::cout << "       \\/     /_____/                             \\/ " << "\n";
    std::cout << C::RESET;
}


/*
* send result infos to std::cout
* */
void console::ShowInputs(double begin, double unfair, double change , std::string sequence) {

    std::cout << C::BWHITE  <<  "\n       INPUTS   \n";
    std::cout << C::BYELLOW  <<  "        > p unfair begin  : " << C::BGREEN <<  begin   << "      "  << C::BLUE <<" \n";
    std::cout << C::BYELLOW  <<  "        > p change type   : " << C::BGREEN <<  change  << "      "  << C::BLUE <<" \n";
    std::cout << C::BYELLOW  <<  "        > p throw unfair  : " << C::BGREEN <<  unfair    << "      "  << C::BLUE <<" \n";
    std::cout << C::BYELLOW  <<  "        > throw sequence  : " << C::BGREEN <<  "(coin flips: " << sequence.length() << ") = " << sequence << C::BLUE <<" \n\n";
    std::cout << C::RESET;
}



/*
 *
* send the help-message to std::cout
* */
void console::Help(std::string message) {
    std::cout << C::BWHITE  <<  " \n ";
    std::cout << C::BGREEN  <<  "   [HMM] " << C::BYELLOW  <<  "  V I T E R B I  A L G O R I T M  \n" ;
    std::cout << C::BWHITE  <<  "\n This algorithm calculates with the hidden MM the process of a coin-flip-game";
    std::cout << C::BWHITE  <<  "\n for uncover coin-flip-cheaters. { 1 = Head ; 0 = Tail }";
    std::cout << C::BWHITE  <<  "\n";
    std::cout << C::BWHITE  <<  "\n";
    std::cout << C::BRED    <<  "        > " << message << "\n";
    std::cout << C::BWHITE  <<  "\n";
    std::cout << C::BWHITE  <<  "\n   Help:    " << C::BYELLOW << "$ ./viterbi [begin] [change] [unfair] [sequence]";
    std::cout << C::BWHITE  <<  "\n   Example: " << C::BGREEN  << "$ ./viterbi -f adjacency_matrix.csv 0101010111";
    std::cout << C::BWHITE  <<  "\n";
    std::cout << C::BWHITE  <<  "\n";
    std::cout << C::BGREEN  <<  "   [float] begin     " << C::BWHITE << "| " << C::BYELLOW << " the probability of start with a unfair coin [0.0 - 1.0]\n";
    std::cout << C::BGREEN  <<  "   [float] change    " << C::BWHITE << "| " << C::BYELLOW << " the prob. of replace un/fair coin [0.0 - 1.0]\n";
    std::cout << C::BGREEN  <<  "   [float] unfair    " << C::BWHITE << "| " << C::BYELLOW << " the prob. of throw Tail with the unfair coin [0.0 - 1.0]\n";
    std::cout << C::BGREEN  <<  "   [String] sequence " << C::BWHITE << "| " << C::BYELLOW << " the coin-throw sequence {0 or 1}\n";
    std::cout << C::BGREEN  <<  "\n\n";
    std::cout << C::RESET ;
}

/*
 *
 * send the result to std::cout
 * */
void console::Result(std::string res) {
    std::cout << C::BWHITE  <<  "       RESULT   \n";
    std::cout << C::BYELLOW <<  "        > Result-Sequence : " << C::GREEN << "(GREEN = fair throw) " << C::RED << "(RED = unfair throw) \n\n";
    std::cout << C::BWHITE  <<  "  :=  " << res << "\n";
    std::cout << C::RESET ;
}


#endif //UB10_CONSOLE_H
