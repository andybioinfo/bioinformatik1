//
// Created by manjaro on 21.01.22.
//

#ifndef SNIPPER_CLASSIFICS_H
#define SNIPPER_CLASSIFICS_H

#include <vector>
#include "States.h"

/**  (Column Y)
 *
 *    Y X1 X2 X3
 * P1 1  1  2  0
 * P2 0  2  0  0
 * P3 1  0  2  1
 *
 * */

/**  The Y-Vector ( Classifications-Column )
 *
 * */
class Classifics {

public:

    using Y_Vector = std::vector<Classification>;

    Classifics();

    Classification operator [](int idx) const;

    double probability(Classification chosen);

    int countOf(Classification chosen);

    int count();

    // add a new classification aka row
    Classifics & operator << (Classification const &s)
    {
        _classifications.push_back(s);
        return *this;
    }

private:

    Y_Vector _classifications;

};


#endif //SNIPPER_CLASSIFICS_H
