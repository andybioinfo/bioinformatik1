
#include <string>
#include <sstream>

class Format {

    public:
        string Format(int x);
        string Format(double x);

}


/* Convert a number in a String with
 * a constant String length (for tables ect.) Example: 0.023 -> "    0.023"
 *
 * @x      int or double
 * @return String of length 9
 * */
std::string Format::Format(int x) {
    std::ostringstream out;
    out.width(9);
    out.precision(4);
    out << x;
    return out.str();
}

std::string Format::Format(double x) {
    std::ostringstream out;
    out.width(9);
    out.precision(4);
    out << x;
    return out.str();
}