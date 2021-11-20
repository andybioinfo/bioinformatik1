#ifndef DISTANCE_H
#define DISTANCE_H

namespace Distance {
/*
 * ???
 * */
template<typename Char>
class EditDistance {
public:
    int operator()(Char a,Char b);
    static bool is_A_minValue(int min_a, int other_b, int other_c);
};

template<typename Char>
int EditDistance<Char>::operator()(Char a,Char b) {return a != b;}



    template<typename Char>
    bool EditDistance<Char>::is_A_minValue(int min_A, int other_B, int other_C) {
    if (min_A <= other_B && min_A <= other_C) {return true;}
    return false;
}

}

#endif //DISTANCE_H
