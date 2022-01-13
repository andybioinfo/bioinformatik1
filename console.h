#ifndef UB10_CONSOLE_H
#define UB10_CONSOLE_H

#include <string>
#include <iostream>

/**
 * Contains Output strings for Console
 * */
class console {
public:

 static void ShowHeader();

 static void Help(std::string message);

 static void ShowInputs(double begin, double unfair, double change , std::string sequence) ;

 static void Result(std::string res);

 static std::string double2String(double x);

};

#endif //UB10_CONSOLE_H
