#ifndef UB12_CONSOLE_H
#define UB12_CONSOLE_H

#include <string>
#include <iostream>
#include "../Snipper.h"

/**
 * Contains Output strings for Console
 * */
class console {
public:

 static void ShowHeader();

 static void Help(std::string message);

 static void ShowInputs(std::string filein, std::string fileout, Snipper &begin) ;

 static void Result(std::string res);

 static std::string double2String(double x);

};

#endif //UB12_CONSOLE_H
