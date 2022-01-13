#include <sstream>
#include "console.h"
#include "Color.h"


/* Convert a number in a String with
 * a constant String length (for tables ect.) Example: 0.023 -> "    0.023"
 *
 * @x      double
 * @return String of length 9
 * */
std::string console::double2String(double x) {
    std::ostringstream out;
    out.width(9);
    out.precision(4);
    out << x;
    return out.str();
}



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
* send input infos to std::cout
* */
void console::ShowInputs(double begin, double unfair, double change, std::string sequence) {

    std::string fair_begin = double2String(begin);
    std::string unfair_begin =double2String(1.0 - begin);
    std::string _change = double2String(change);
    std::string no_change = double2String(1.0 - change);
    std::string unfair_head = double2String(1.0 - unfair);
    std::string unfair_tail = double2String(unfair);

    std::cout << C::BWHITE  <<   "\n     INPUTS";
    std::cout << C::BYELLOW  <<  "\n      > p(begin)  : " << C::BMAGENTA << "Fair -> " << C::BBLUE << fair_begin  << " "<< C::BCYAN << "|" << C::BMAGENTA << " Unfair -> " << C::BBLUE << unfair_begin;
    std::cout << C::BYELLOW  <<  "\n      > p(change) : " << C::BMAGENTA << "Yes  -> " << C::BBLUE << _change     << " "<< C::BCYAN << "|" << C::BMAGENTA << " No     -> " << C::BBLUE << no_change;
    std::cout << C::BYELLOW  <<  "\n      > p(unfair) : " << C::BMAGENTA << "Head -> " << C::BBLUE << unfair_head << " "<< C::BCYAN << "|" << C::BMAGENTA << " Tail   -> " << C::BBLUE << unfair_tail;
    std::cout << C::BYELLOW  <<  "\n      > Sequence  : " << C::BLUE <<  "(coin flips: " << sequence.length() << ") = " << C::BBLUE << sequence <<" \n\n";
    std::cout << C::RESET;
}


/*
 *
* send the help-message to std::cout
* */
void console::Help(std::string message) {
    std::cout << C::BWHITE  <<  "\n" ;
    std::cout << C::BWHITE  <<  "    .______.    V I T E R B I  A L G O R I T M \n" ;
    std::cout << C::BWHITE  <<  "   /\\       \\      \n" ;
    std::cout << C::BWHITE  <<  "  /()\\   ()  \\ " << C::BLUE << "   This algorithm calculates for a sequence\n" ;
    std::cout << C::BWHITE  <<  " /    \\.______\\" << C::BLUE << "    of Coin-Flips " << C::BMAGENTA << "{ 0 = Tail , 1 = Head } \n" ;
    std::cout << C::BWHITE  <<  " \\    /()     /" << C::BLUE << "   with 2 different coins " << C::BCYAN << "{ Fair , Unfair }\n" ;
    std::cout << C::BWHITE  <<  "  \\()/   ()  / " << C::BLUE << "  with the parameters the resulting \n" ;
    std::cout << C::BWHITE  <<  "   \\/_____()/  " << C::BLUE << " sequence of " << C::BLUE << "fair/unfair Coin-Flips\n" ;
    std::cout << C::BWHITE  <<  "               " << C::BLUE << "to uncover coin-flip-cheaters.\n" ;
    std::cout << C::BWHITE  <<  "\n";
    std::cout << C::BWHITE  <<  "   Help:    " << C::BYELLOW << " $ ./viterbi [begin] [change] [unfair] [sequence]\n" ;
    std::cout << C::BWHITE  <<  "   Example: " << C::BGREEN  << " $ ./viterbi 0.4 0.05 0.1 0101010111             \n" ;
    std::cout << C::BWHITE  <<  "\n" ;
    std::cout << C::BGREEN  <<  " [float]  begin    " << C::BWHITE << "| " << C::BYELLOW << " the probability of start with a fair coin [0.0 - 1.0]\n" ;
    std::cout << C::BGREEN  <<  " [float]  change   " << C::BWHITE << "| " << C::BYELLOW << " the prob. of replace un/fair coin [0.0 - 1.0]\n" ;
    std::cout << C::BGREEN  <<  " [float]  unfair   " << C::BWHITE << "| " << C::BYELLOW << " the prob. of throw Tail with the unfair coin [0.0 - 1.0];\n" ;
    std::cout << C::BGREEN  <<  " [String] sequence " << C::BWHITE << "| " << C::BYELLOW << " the coin-throw sequence {'0' or '1'}\n" ;
    std::cout << C::BWHITE  <<  "\n" ;
    std::cout << C::BWHITE  <<  "             > "<< C::BRED << message << C::RESET << "\n\n" ;
}

/*
 *
 * send the result to std::cout
 * */
void console::Result(std::string res) {
    std::cout << C::BWHITE  <<  "     RESULT   \n";
    std::cout << C::BYELLOW <<  "      > Result-Sequence : " << C::GREEN << "(GREEN = fair throw) " << C::RED << "(RED = unfair throw) \n\n";
    std::cout << C::BWHITE  <<  "   :=  " << res << "\n\n";
    std::cout << C::RESET ;
}
