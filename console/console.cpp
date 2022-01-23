#include <sstream>
#include <iomanip>
#include "console.h"
#include "Color.h"
#include "Style.h"
#include "../Snipper.h"
#include "Format.h"


/*
* sends a big-font Ascii-Art-Header to std::cout
* */
void console::ShowHeader() {
    std::cout << "\n";
    std::cout << C::BYELLOW <<  "\n    )\\.--.   )\\  )\\ " << C::BRED << " .'(  " << C::BYELLOW << "   /`-.  " << C::BRED << "   /`-.   )\\.---.     /`-.  ";
    std::cout << C::BYELLOW <<  "\n   (   ._.' (  \\, / " << C::BRED << " \\  ) " << C::BYELLOW << " ,' _  \\ " << C::BRED << " ,' _  \\ (   ,-._(  ,' _  \\ ";
    std::cout << C::BYELLOW <<  "\n    `-.`.    ) \\ (  " << C::BRED << " ) (  " << C::BYELLOW << "(  '-' ( " << C::BRED << "(  '-' (  \\  '-,   (  '-' ( ";
    std::cout << C::BYELLOW <<  "\n   ,_ (  \\  ( ( \\ \\ " << C::BRED << " \\  ) " << C::BYELLOW << " ) ,._.' " << C::BRED << " ) ,._.'   ) ,-`    ) ,_ .' ";
    std::cout << C::BYELLOW <<  "\n  (  '.)  )  `.)/  )" << C::BRED << "  ) \\ " << C::BYELLOW << "(  '     " << C::BRED << "(  '      (  ``-.  (  ' ) \\ ";
    std::cout << C::BYELLOW <<  "\n   '._,_.'      '.( " << C::BRED << "   )/ " << C::BYELLOW << " )/      " << C::BRED << " )/        )..-.(   )/   )/ ";
    std::cout << "\n";
    std::cout << "\n " << C::BYELLOW << " SN" << C::BRED << "I" << C::BYELLOW << "P" << C::BRED << "PER  ---- " << C::BYELLOW << "  \n";
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

    std::cout << "\n\n"<<BG1<<"       " << T_input << "INPUT" <<"        " << T_in << T_UL<< "file in" << R << BG1 << " : " <<T1 << R ;
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
    std::cout << BG2 << C::BWHITE  <<            "\n  |                   "<<                            " |   Homoz-Minor  : "<< C::BCYAN  <<homicnt<<" (over all SNP's)  " << R << "\n\n";

    std::cout << C::BWHITE  <<  "       > " << C::BBLUE << "computing ... " << C::RESET << "\n" ;
}




/*
 *
* send the help-message to std::cout
* */
void console::Help(std::string message) {
    console::ShowHeader();
    std::cout << C::BWHITE  <<  "" ;
    std::cout << C::BWHITE  <<  "";
    std::cout << C::BWHITE  <<  "  Help:    " << C::BYELLOW << " $ ./snipper [input] [output] \n" ;
    std::cout << C::BWHITE  <<  "  Example: " << C::BGREEN  << " $ ./snipper ../snp.txt ../out.snp            \n" ;
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
void console::Result(std::string res,std::string timeA,std::string timeB,std::string timeC) {

    S::move(up,1);
    S::move(left,28);
    std::cout << C::BWHITE  <<  "\n       > " << C::BBLUE << "Finished. " << C::RESET ;
    std::cout << C::BWHITE  <<  "\n         Run Time  (m:s,ms)  :" << C::BYELLOW << " total     -> " << C::BBLUE << timeA;
    std::cout << C::BWHITE  <<  "\n                             :" << C::BYELLOW << " file      -> " << C::BBLUE << timeB;
    std::cout << C::BWHITE  <<  "\n                             :" << C::BYELLOW << " computing -> " << C::BBLUE << timeC;
    std::cout << C::BWHITE  <<  "\n\n" ;

    std::cout << C::RESET ;
}


/*
 * Create a Timer with timestamp
 * 
 * */
Timer::Timer() {
    timestamp = clock();
}

/*
 * Load the timedifference between now and the timestamp
 * 
 * */
double Timer::getMilliSecs() {
    double tstart = timestamp;
    double time1 = clock() - tstart;
    double time = time1 / 1000.0;
    return time;
}

/*
 * Convert Milliseconds in a string in format m:s.ms
 * 
 * */
std::string Timer::getFormatted(double ms) {
    int min  = ms / 60000;
    int sec  = (ms - (min * 60000)) / 1000;
    int msec = ms - (min * 60000) - (sec * 1000);

    std::stringstream ms1("");
    std::stringstream ms2("");
    ms1 << msec;
    if (ms1.str().size() == 1) {ms2 << "00" << msec;} else
    if (ms1.str().size() == 2) {ms2 << "0" << msec;} else
    if (ms1.str().size() >= 3) {ms2 << msec;}

    std::stringstream s1("");
    std::stringstream s2("");
    s1 << sec;
    if (s1.str().size() == 1) {s2 << "0" << sec;} else {s2 << sec;}
    std::stringstream s("");
    s << min << ":" << s2.str() << "." << ms2.str() ;
    std::stringstream res("");
    res << std::setfill(' ') << std::setw(10) << s.str();

    return res.str();
}
