#ifndef UB12_CONSOLE_H
#define UB12_CONSOLE_H

#include <string>
#include <iostream>
#include "../snipper/Snipper.h"
#include "../NaiveBayes.h"

/**
 * Contains Output strings for Console
 * */
class console {
public:

 console(int remainsteps);

 static void ShowHeader();

 static void Help(std::string message);

 static void ShowInputs(std::string filein, std::string fileout, Snipper &begin) ;

 static void InputLine(int snps, int pats, int folds, int ksize,std::string filename,std::string totaltime, std::string filetime, std::string computetime);

 static void Result(NaiveBayes& NB, std::string res,std::string timeA,std::string timeB,std::string timeC);

 static std::string double2String(double x);

 void stepcounter();
 void startcounter();

private:
int remainsteps;
int totalsteps;
int stringlength;

};

/**
 * Store a Timestamp for calc runtime
 * */
class Timer {
public:
    Timer();
    double getMilliSecs();
    static std::string getFormatted(double ms);
private:
    double timestamp;
};

#endif //UB12_CONSOLE_H
