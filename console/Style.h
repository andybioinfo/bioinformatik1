
#ifndef STYLE_H
#define STYLE_H

#include <string>

enum Color {
    None, // Neutral
    Black,  Red,      Green,  Yellow,
    Blue,   Magenta,  Cyan,   White

};

enum Font {
    Non, // Neutral
    Bold,   Italic,   Underlined,  doubleUnderlined,
    Blink,  Inverse,  Crossed,     Overlined,         Boxed

};

enum dir {
    Up, Down, Left, Right
};

class S {
public:
    static std::string getStyle(Color background, Font style, Color text);
    static std::string setStyle(Color background, Font style, Color text, std::string text_to_style);
    static void move(dir direction, int s);
    static std::string RESET;
};


#endif //STYLE_H
