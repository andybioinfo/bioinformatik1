#ifndef UB7_CONSOLE_H
#define UB7_CONSOLE_H


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
    static const char* BRED;
    static const char* BYELLOW;
    static const char* YELLOW;
    static const char* HBLUE;
    };

const char* C::RESET   = "\033[0m";
const char* C::BLUE    = "\033[0;34m";
const char* C::BBLUE   = "\033[1;34m";
const char* C::BWHITE  = "\033[1;37m";
const char* C::BGREEN  = "\033[1;32m";
const char* C::BRED    = "\033[1;31m";
const char* C::BYELLOW = "\033[1;33m";
const char* C::YELLOW  = "\033[0;33m";
const char* C::HBLUE   = "\033[0;94m";




/**
 * Contains Output strings for Console
 * */
class console {
public:
 static void Title(std::string filename,std::string root,std::string target);
 static void Help(std::string message);
 static void Matrix(int nc,int ec,std::string message,bool okay);
 static void Result(int weight_value,int length,std::string root,std::string target,std::string path_output) ;
};


/*
* send the title to std::cout
* */
void console::Title(std::string filename,std::string root,std::string target) {
    std::cout << "\n";
    std::cout << C::BGREEN  <<  "   [ILP] " << C::BYELLOW  <<  "  S H O R T E S T  P A T H  \n ";
    std::cout <<                "\n";
    std::cout <<                "\n";
    std::cout << C::BYELLOW  <<  "        > Adjacency-File   : " << C::BWHITE <<  filename << C::BLUE <<" \n";
    std::cout << C::BYELLOW  <<  "        > Source node      : " << C::BWHITE <<  root << C::BLUE <<" \n";
    std::cout << C::BYELLOW  <<  "        > Target node      : " << C::BWHITE <<  target << C::BLUE <<" \n";
    std::cout << C::RESET;
}



/*
* send matrix infos to std::cout
* */
void console::Matrix(int nc,int ec,std::string message,bool okay) {


    std::cout << C::BYELLOW  <<  "        > Matrix   : ";

    if (okay) {
        std::cout << C::BRED <<  message;
    } else {
        std::cout << C::BRED <<  message;
    }


    std::cout << C::BGREEN  <<  " {  " << C::BWHITE << "Graph: " << C::BRED << nc <<  " nodes " << ec << " edges";
    std::cout << C::BGREEN  <<  " }\n";
    std::cout << C::RESET;
}




/*
* send result infos to std::cout
* */
void console::Result(int weight_value,int length,std::string root,std::string target,std::string path_output) {

    std::cout << C::BYELLOW  <<  " Shortest path from      " << C::BGREEN << "{" <<  root  << "} --> {" << target  << "}" << C::BLUE <<" \n";
    std::cout << C::BYELLOW  <<  "        > path-weight  : " << C::BGREEN <<  weight_value << "      "  << C::BLUE <<" \n";
    std::cout << C::BYELLOW  <<  "        > path-length  : " << C::BGREEN <<  length       << "      "  << C::BLUE <<" \n";
    std::cout << C::BYELLOW  <<  "\n";
    std::cout << C::BBLUE    <<  path_output;
    std::cout << C::RESET;
}





/*
 *
* send the help-message to std::cout
* */
void console::Help(std::string message) {
    std::cout << C::BWHITE  <<  " \n ";
    std::cout << C::BGREEN  <<  "   [ILP] " << C::BYELLOW  <<  "  S H O R T E S T  P A T H  \n" ;
    std::cout << C::BWHITE  <<  "\n";
    std::cout << C::BRED    <<  "        > " << message << "\n";
    std::cout << C::BWHITE  <<  "\n";
    std::cout << C::BWHITE  <<  "\n   Help:    " << C::BYELLOW << "$ ./shortestPath [-h] [-f] [File] [-r] [root] [-t] [target]";
    std::cout << C::BWHITE  <<  "\n   Example: " << C::BGREEN  << "$ ./shortestPath -f adjacency_matrix.txt -r A -t E";
    std::cout << C::BWHITE  <<  "\n";
    std::cout << C::BWHITE  <<  "\n";
    std::cout << C::BGREEN  <<  "  -h / --help              " << C::BWHITE << "| " << C::BYELLOW << " Show this help.\n";
    std::cout << C::BGREEN  <<  "  -f / --file    [FILE]    " << C::BWHITE << "| " << C::BYELLOW << " An adjacency-matrix file\n";
    std::cout << C::BGREEN  <<  "  -r / --root    [String]  " << C::BWHITE << "| " << C::BYELLOW << " your start node\n";
    std::cout << C::BGREEN  <<  "  -t / --target  [String]  " << C::BWHITE << "| " << C::BYELLOW << " your final node\n";
    std::cout << C::BGREEN  <<  "\n\n";
    std::cout << C::RESET ;
}












#endif //UB7_CONSOLE_H
