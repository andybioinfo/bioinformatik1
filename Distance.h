#ifndef DISTANCE_H
#define DISTANCE_H

namespace Distance {

/*
 * Distance class for alignment-algorithm
 * */
template<typename Char>
class EditDistance {

public:

    int operator()(Char a,Char b);

    static bool is_A_minValue(int min_a, int other_b, int other_c);

};

/*
 * Returns the Edit-Distance from a and b
 * @a first character
 * @b second character
 * @return distance
 * */
template<typename Char>
    int EditDistance<Char>::operator()(Char a,Char b) {
        return a != b;
    }


/*
 * Compare the value A with B and C
 * @min_A the main value
 * @min_B the other value
 * @min_C the other value
 * @return true, if A smaller/equal as B and C
 * */
template<typename Char>
    bool EditDistance<Char>::is_A_minValue(int min_A, int other_B, int other_C) {
        if (min_A <= other_B && min_A <= other_C) {return true;}
    return false;
}

}

#endif //DISTANCE_H
