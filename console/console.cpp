#include <sstream>
#include "console.h"
#include "Color.h"
#include "Style.h"
#include "../Snipper.h"
#include "Format.h"


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
void console::ShowInputs(std::string filein, std::string fileout, Snipper &begin) {

    std::string BG1      =  S::getStyle(Red,Non,None);
    std::string BG2      =  S::getStyle(Blue,Non,None);
    std::string R        =  S::RESET;
    std::string T_UL     =  S::getStyle(Red,doubleUnderlined,None);
    std::string T_input  =  S::getStyle(None,Bold,White);
    std::string T_in     =  S::getStyle(None,Bold,Yellow);
    std::string T_C      =  S::getStyle(None,Bold,Yellow);
    std::string T1  =    S::setStyle(Red,Bold,Green,Format::StringF(40,filein));
    std::string T2  =    S::setStyle(Red,Bold,Green,Format::StringF(40,fileout));

    // File

    std::cout << "\n"<<BG1<<"       " << T_input << "INPUT" <<"        " << T_in << T_UL<< "file in" << R << BG1 << " : " <<T1 << R ;
    std::cout << "\n"<<BG1<<"                   " << T_in << T_UL << T_C << "file out" << R << BG1 << " : " << T2;
    std::cout << R <<"\n" << R;

    // Table

    std::string chkcnt = Format::int2String(begin.getClassifics().count());
    std::string ctlcnt = Format::int2String(begin.getClassifics().countOf(Control));
    std::string ccrcnt = Format::int2String(begin.getClassifics().countOf(Cancer));

    std::string snpcnt = Format::int2String(begin.getSNPcount());
    std::string homacnt = Format::int2String(begin.getGenCount(HomoMajor));
    std::string hetecnt = Format::int2String(begin.getGenCount(Hetero));
    std::string homicnt = Format::int2String(begin.getGenCount(HomoMinor));

    std::string T3  =    S::setStyle(Blue,doubleUnderlined,White,"Checked persons");
    std::string T4  =    S::setStyle(Blue,doubleUnderlined,White,"SNP's");

    std::cout << BG2 << C::BWHITE <<    "\n  | "<< T3 << BG2 << ":  "<< C::BWHITE  <<" |   " << T4 << BG2 <<":         "<< C::BCYAN  <<"                            " << R;
    std::cout << BG2 << C::BWHITE  <<            "\n  | count:   "<< C::BCYAN  << chkcnt << C::BWHITE  <<" |   count        : "<< C::BCYAN  <<snpcnt<<"                   " << R;
    std::cout << BG2 << C::BWHITE  <<            "\n  | Cancer:  "<< C::BCYAN  << ctlcnt << C::BWHITE  <<" |   Homoz-Major  : "<< C::BCYAN  <<homacnt<<" (over all SNP's)  " << R;
    std::cout << BG2 << C::BWHITE  <<            "\n  | Control: "<< C::BCYAN  << ccrcnt << C::BWHITE  <<" |   Heterozygous : "<< C::BCYAN  <<hetecnt<<" (over all SNP's)  " << R;
    std::cout << BG2 << C::BWHITE  <<            "\n  |                   "<<                            " |   Homoz-Minor  : "<< C::BCYAN  <<homicnt<<" (over all SNP's)  " << R << "\n";

}


/*
 *
* send the help-message to std::cout
* */
void console::Help(std::string message) {
    std::cout << C::BWHITE  <<  "\n" ;/*
    std::cout << C::BWHITE  <<  "    .______.    S N P  A L G O R I T M \n" ;
    std::cout << C::BWHITE  <<  "   /\\       \\      \n" ;
    std::cout << C::BWHITE  <<  "  /()\\   ()  \\ " << C::BLUE << "   This algorithm calculates for a sequence\n" ;
    std::cout << C::BWHITE  <<  " /    \\.______\\" << C::BLUE << "    of Coin-Flips " << C::BMAGENTA << "{ 0 = Tail , 1 = Head } \n" ;
    std::cout << C::BWHITE  <<  " \\    /()     /" << C::BLUE << "   with 2 different coins " << C::BCYAN << "{ Fair , Unfair }\n" ;
    std::cout << C::BWHITE  <<  "  \\()/   ()  / " << C::BLUE << "  with the parameters the resulting \n" ;
    std::cout << C::BWHITE  <<  "   \\/_____()/  " << C::BLUE << " sequence of " << C::BLUE << "fair/unfair Coin-Flips\n" ;
    std::cout << C::BWHITE  <<  "               " << C::BLUE << "to uncover coin-flip-cheaters.\n" ;*/
    std::cout << C::BWHITE  <<  "\n";
    std::cout << C::BWHITE  <<  "   Help:    " << C::BYELLOW << " $ ./snipper [input] [output] \n" ;
    std::cout << C::BWHITE  <<  "   Example: " << C::BGREEN  << " $ ./snipper ../snp.txt ../out.snp            \n" ;
    std::cout << C::BWHITE  <<  "\n" ;
    std::cout << C::BGREEN  <<  " [FILE]  input    " << C::BWHITE << "| " << C::BYELLOW << " a SNP matrix file\n" ;
    std::cout << C::BGREEN  <<  " [FILE]  output   " << C::BWHITE << "| " << C::BYELLOW << " ? surprise ?\n" ;
    std::cout << C::BWHITE  <<  "\n" ;
    std::cout << C::BWHITE  <<  "      " << S::setStyle(Red,Bold,Yellow," ERROR := ") << C::BRED << " : " << S::getStyle(Black,Blink,Red) << C::BRED << message << C::RESET << "\n\n" ;
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


