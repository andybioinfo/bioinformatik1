
#include <sstream>
#include <iostream>
#include <vector>
#include "Style.h"

// returns a color-code
std::string S::getStyle(Color background, Font style, Color text) {

    std::stringstream s("");

    switch (background) {
        case None    : break;
        case Black   : s << "\033[40m"; break;
        case Red     : s << "\033[41m"; break;
        case Green   : s << "\033[42m"; break;
        case Yellow  : s << "\033[43m"; break;
        case Blue    : s << "\033[44m"; break;
        case Magenta : s << "\033[45m"; break;
        case Cyan    : s << "\033[46m"; break;
        case White   : s << "\033[47m"; break;
    }

    switch (style) {
        case None               : break;
        case Bold               : s << "\033[1m"; break;
        case Italic             : s << "\033[3m"; break;
        case Underlined         : s << "\033[4m"; break;
        case doubleUnderlined   : s << "\033[21m"; break;
        case Blink              : s << "\033[5m"; break;
        case Inverse            : s << "\033[7m"; break;
        case Crossed            : s << "\033[9m"; break;
        case Overlined          : s << "\033[53m"; break;
        case Boxed              : s << "\033[51m"; break;

    }

    switch (text) {
        case None    : break;
        case Black   : s << "\033[30m"; break;
        case Red     : s << "\033[31m"; break;
        case Green   : s << "\033[32m"; break;
        case Yellow  : s << "\033[33m"; break;
        case Blue    : s << "\033[34m"; break;
        case Magenta : s << "\033[35m"; break;
        case Cyan    : s << "\033[36m"; break;
        case White   : s << "\033[37m"; break;

    }

    return s.str();
}

std::string S::RESET = "\033[0m";

// Styles a string and reset after the String
std::string S::setStyle(Color background, Font style, Color text, std::string text_to_style) {
    std::stringstream bb("3");
    bb << getStyle(background,style,text);
    bb << text_to_style;
    bb << RESET;
    return bb.str();
}

// move the Cursor in console s characters in the given direction. ( for overwrite console text )
void S::move(dir direction,int s) {

    if (direction == left)  { for (int i = 0 ; i <= s ; i++) { std::cout << "\033[1D"; } return; }
    if (direction == right) { for (int i = 0 ; i <= s ; i++) { std::cout << "\033[1C"; } return; }
    if (direction == up)    { for (int i = 0 ; i <= s ; i++) { std::cout << "\033[1A"; } return; }
    if (direction == down)  { for (int i = 0 ; i <= s ; i++) { std::cout << "\033[1B"; } return; }
    return;

}

