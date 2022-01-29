#include <sstream>
#include <iomanip>
#include "console.h"
#include "Color.h"
#include "Style.h"
#include "../snipper/Snipper.h"
#include "Format.h"


/*
* sends a big-font Ascii-Art-Header to std::cout
* */
void console::ShowHeader() {
    std::cout << "\n";
    std::string r  = C::RED;
    std::string R  = C::BRED;
    std::string Y  = C::BYELLOW;
    std::string G  = C::BGREEN;

    std::cout << r << "\n      )                                                                 ";
    std::cout << R << "\n   ( /(  " << r << "   (                             (                             ";
    std::cout << R << "\n   )\\())    )\\      (      )       (    ( )\\      )   (        (        ";
    std::cout << R << "\n  ((_)\\  ((((_)(    )\\    /((     ))\\   )((_)  ( /(   )\\ )    ))\\   (   ";
    std::cout << Y << "\n   _((_) " << R << " )\\ _ )\\  ((_)  (_))\\   /((_) " << Y << "  ((_)_ " << R << "  )(_)) (()/(   /((_)  )\\  ";
    std::cout << G << "\n  | \\| | " << Y << " (_)_\\(_)  (_)  _)((_) (_))  " << G << "  | _ )" << Y << " ((_)_   )(_)) (_))   ((_) ";
    std::cout << G << "\n  | .` |   / _ \\    | |  \\ V /  / -_)   | _ \\ / _` | | || | / -_)  (_-< ";
    std::cout << G << "\n  |_|\\_|  /_/ \\_\\   |_|   \\_/   \\___|   |___/ \\__,_|  \\_, | \\___|  /__/ ";
    std::cout << G << "\n                                                      |__/              ";


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
    std::cout << C::BWHITE  <<  "  Help:    " << C::BYELLOW << " $ ./bayes [input] [output] \n" ;
    std::cout << C::BWHITE  <<  "  Example: " << C::BGREEN  << " $ ./bayes ../snp.txt ../out.txt            \n" ;
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
void console::Result(NaiveBayes& NB, std::string res,std::string timeA,std::string timeB,std::string timeC) {

/*
 *     S::move(Up,1);
    S::move(Left,28);
    std::cout << C::BWHITE  <<  "\n       > " << C::BBLUE << "Finished. " << C::RESET ;
    std::cout << C::BWHITE  <<  "\n         Run Time  (m:s,ms)  :" << C::BYELLOW << " total     -> " << C::BBLUE << timeA;
    std::cout << C::BWHITE  <<  "\n                             :" << C::BYELLOW << " file      -> " << C::BBLUE << timeB;
    std::cout << C::BWHITE  <<  "\n                             :" << C::BYELLOW << " computing -> " << C::BBLUE << timeC;
    std::cout << C::BWHITE  <<  "\n\n" ;

    std::cout << C::RESET ;*/

    Statistics ST = NB.getStats();
    int snps = NB.getSNPs().getSNPcount();
    int pats = NB.getSNPs()[0].getSize();

std::vector<std::string> a1 = Statistics::barGraph( 0.0,ST.get_stats_Specificity(), Green);
std::vector<std::string> a2 = Statistics::barGraph( 0.0,ST.get_stats_Sensitivity(), Yellow);
std::vector<std::string> a3 = Statistics::barGraph( 0.0,ST.get_stats_Precision(), Red);
std::vector<std::string> a4 = Statistics::barGraph( 0.0,ST.get_stats_Accuracy(), Cyan);
std::vector<std::string> a5 = Statistics::barGraph( 0.0,ST.get_stats_F1Score(), Blue);
std::vector<std::string> a6 = Statistics::barGraph( 0.0,ST.get_stats_Average(), Magenta);
std::vector<std::string> a7 = Statistics::barGraph( 0.0,ST.get_stats_Standard_deviation(), Red);


    double mi4 =  Statistics::getfromList( MIN , ST.get_stats_Accuracy() );
    double mi2 =  Statistics::getfromList( MIN , ST.get_stats_Sensitivity() );
    double mi1 =  Statistics::getfromList( MIN , ST.get_stats_Specificity() );
    double mi3 =  Statistics::getfromList( MIN , ST.get_stats_Precision() );
    double mi5 =  Statistics::getfromList( MIN , ST.get_stats_F1Score() );
    double mi6 =  Statistics::getfromList( MIN , ST.get_stats_Average() );
    double mi7 =  Statistics::getfromList( MIN , ST.get_stats_Standard_deviation() );

    double av4 =  Statistics::getfromList( AVERAGE , ST.get_stats_Accuracy() );
    double av2 =  Statistics::getfromList( AVERAGE , ST.get_stats_Sensitivity() );
    double av1 =  Statistics::getfromList( AVERAGE , ST.get_stats_Specificity());
    double av3 =  Statistics::getfromList( AVERAGE , ST.get_stats_Precision());
    double av5 =  Statistics::getfromList( AVERAGE , ST.get_stats_F1Score());
    double av6 =  Statistics::getfromList( AVERAGE , ST.get_stats_Average());
    double av7 =  Statistics::getfromList( AVERAGE , ST.get_stats_Standard_deviation());

    double ma4 = Statistics::getfromList( MAX , ST.get_stats_Accuracy() );
    double ma2 = Statistics::getfromList( MAX , ST.get_stats_Sensitivity() );
    double ma1 = Statistics::getfromList( MAX , ST.get_stats_Specificity());
    double ma3 = Statistics::getfromList( MAX , ST.get_stats_Precision());
    double ma5 = Statistics::getfromList( MAX , ST.get_stats_F1Score() );
    double ma6 = Statistics::getfromList( MAX , ST.get_stats_Average() );
    double ma7 = Statistics::getfromList( MAX , ST.get_stats_Standard_deviation());


std::cout << C::BWHITE  <<  "\n  max    __ __ __ __ __ __ __    / (min%|avr%|max%) of all k's";
std::cout << C::BWHITE  <<  "\n 100%    "<<a1[10]<<" "<<a2[10]<<" "<<a3[10]<<" "<<a4[10]<<" "<<a5[10]<<" "<<a6[10]<<" "<<a7[10]<<"   | Sp = Specificity  ( " << mi1 << " | " << av1 << " | " << ma1 << " )";
std::cout << C::BWHITE  <<  "\n  90%    "<<a1[ 9]<<" "<<a2[ 9]<<" "<<a3[ 9]<<" "<<a4[ 9]<<" "<<a5[ 9]<<" "<<a6[ 9]<<" "<<a7[ 9]<<"   | Se = Sensitivity  ( " << mi2 << " | " << av2 << " | " << ma2 << " )";
std::cout << C::BWHITE  <<  "\n  80%    "<<a1[ 8]<<" "<<a2[ 8]<<" "<<a3[ 8]<<" "<<a4[ 8]<<" "<<a5[ 8]<<" "<<a6[ 8]<<" "<<a7[ 8]<<"   | Pr = Precision    ( " << mi3 << " | " << av3 << " | " << ma3 << " )";
std::cout << C::BWHITE  <<  "\n  70%    "<<a1[ 7]<<" "<<a2[ 7]<<" "<<a3[ 7]<<" "<<a4[ 7]<<" "<<a5[ 7]<<" "<<a6[ 7]<<" "<<a7[ 7]<<"   | Ac = Accuracy     ( " << mi4 << " | " << av4 << " | " << ma4 << " )";
std::cout << C::BWHITE  <<  "\n  60%    "<<a1[ 6]<<" "<<a2[ 6]<<" "<<a3[ 6]<<" "<<a4[ 6]<<" "<<a5[ 6]<<" "<<a6[ 6]<<" "<<a7[ 6]<<"   | F1 = F1Score      ( " << mi5 << " | " << av5 << " | " << ma5 << " )";
std::cout << C::BWHITE  <<  "\n  50%    "<<a1[ 5]<<" "<<a2[ 5]<<" "<<a3[ 5]<<" "<<a4[ 5]<<" "<<a5[ 5]<<" "<<a6[ 5]<<" "<<a7[ 5]<<"   | Av = Average      ( " << mi6 << " | " << av6 << " | " << ma6 << " )";
std::cout << C::BWHITE  <<  "\n  40%    "<<a1[ 4]<<" "<<a2[ 4]<<" "<<a3[ 4]<<" "<<a4[ 4]<<" "<<a5[ 4]<<" "<<a6[ 4]<<" "<<a7[ 4]<<"   | Dv = Deviation    ( " << mi7 << " | " << av7 << " | " << ma7 << " )";
std::cout << C::BWHITE  <<  "\n  30%    "<<a1[ 3]<<" "<<a2[ 3]<<" "<<a3[ 3]<<" "<<a4[ 3]<<" "<<a5[ 3]<<" "<<a6[ 3]<<" "<<a7[ 3]<<"";
std::cout << C::BWHITE  <<  "\n  20%    "<<a1[ 2]<<" "<<a2[ 2]<<" "<<a3[ 2]<<" "<<a4[ 2]<<" "<<a5[ 2]<<" "<<a6[ 2]<<" "<<a7[ 2]<<"";
std::cout << C::BWHITE  <<  "\n  10%    "<<a1[ 1]<<" "<<a2[ 1]<<" "<<a3[ 1]<<" "<<a4[ 1]<<" "<<a5[ 1]<<" "<<a6[ 1]<<" "<<a7[ 1]<<"";
std::cout << C::BWHITE  <<  "\n   5%    "<<a1[ 0]<<" "<<a2[ 0]<<" "<<a3[ 0]<<" "<<a4[ 0]<<" "<<a5[ 0]<<" "<<a6[ 0]<<" "<<a7[ 0]<<"";
std::cout << C::BWHITE  <<  "\n   0%    Sp Se Pr Ac F1 Av Dv \n\n";

    std::cout << C::BLUE  << " > complete statistic table is written in file: " << C::BBLUE  << res << "\n\n";
}

void console::InputLine(int snp, int pat, int k, int ksize) {

    std::cout << "\n" << C::RESET;

    stringstream snp_buf("");
    stringstream pat_buf("");
    stringstream kfold_buf("");

    snp_buf << "| " << snp << " |";
    pat_buf << "| " << pat << " |";
    kfold_buf << "| " << k << " * " << ksize << " |";

    std::string T1  =    S::setStyle(Black,Bold,White,"                      ::   :: Naive Bayes ::   ::                     ");
    std::string T2  =    S::setStyle(None,doubleUnderlined,Blue,"Patients:");
    std::string T3  =    S::setStyle(None,doubleUnderlined,Cyan,"SNPs:");
    std::string T4  =    S::setStyle(None,doubleUnderlined,Red,"k-Fold:");
    std::string T5  =    S::setStyle(None,Italic,Red," ! All inputs Okay ! ");

    std::string V1  =    S::setStyle(None,Bold,Magenta,snp_buf.str());
    std::string V2  =    S::setStyle(None,Bold,Magenta,pat_buf.str());
    std::string V3  =    S::setStyle(None,Bold,Yellow,kfold_buf.str());

    std::cout << "  " << T1 <<
              "\n"  <<"  " << T2 << "  " << V1 << "  " << T3 << "  " << V2<< "  " << T4 << "  " << V3 << "  " << T5 << " " << S::RESET;

    std::cout << "\n" << C::RESET;
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
