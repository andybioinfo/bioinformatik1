//
// Created by manjaro on 21.01.22.
//

#include <sstream>
#include "Format.h"

/* Convert a number in a String with
 * a constant String length (for tables ect.) Example: 0.023 -> "    0.023"
 *
 * @x      double
 * @return String of length 9
 * */
std::string Format::double2String(double x) {
    std::ostringstream out;
    out.width(9);
    out.precision(4);
    out << x;
    return out.str();
}

/* Convert a number in a String with
 * a constant String length (for tables ect.) Example: 0.023 -> "    0.023"
 *
 * @x      int
 * @return String of length 9
 * */
std::string Format::int2String(int x) {
    std::ostringstream out;
    out.width(9);
    out.precision(4);
    out << x;
    return out.str();
}

std::string Format::StringF(int length, std::string str) {
    int l = str.length();
    int puffer = length - l;

    std::stringstream s("");
    if (puffer >= 0) {std::string a(puffer,' ');
        s << str << a; return s.str(); }

    return str;
}

