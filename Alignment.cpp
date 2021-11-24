
#include "Alignment.h"


/*
 * Align-Algorithm with 2 Sequences,
 * @a First Sequence
 * @b Second Sequence
 * @return the calculated score
 * */
template <typename Alpha, typename Distance>
int Alignment<Alpha,Distance>::operator()(const Seq&a, const Seq&b) {

    // ## Create Matrix

    Matrix M(a.size()+1,b.size()+1);

    // ## Start Algorithm

    // Init Zero-rows/cols

    for (int x = 0 ; x <= M.X_MAX() ; x++) {M.setValue(x,0,x);}
    for (int y = 0 ; y <= M.Y_MAX() ; y++) {M.setValue(0,y,y);}

    // LineByLine

    for (int y = 1 ; y <= M.Y_MAX() ; y++) {

        for (int x = 1 ; x <= M.X_MAX() ; x++) {
            Distance D;
            int diag_value = M.getValue(x-1,y-1) + D(a[x-1],b[y-1]);
            int up_value   = M.getValue(x,y-1)      + GAP_COST;
            int left_value = M.getValue(x-1,y)      + GAP_COST;

            if(Distance::is_A_minValue(diag_value,left_value,up_value)) { M.setValue(x,y,diag_value);continue;}
            if(Distance::is_A_minValue(left_value,diag_value,up_value)) { M.setValue(x,y,left_value);continue;}
            if(Distance::is_A_minValue(up_value,left_value,diag_value)) { M.setValue(x,y,up_value);continue;}

        }

    }


    // ## End Algorithm
    
    // ## Backtracing

    int y = M.Y_MAX();
    int x = M.X_MAX();
    int score = M.getValue(x,y);
    Distance D;

    while(true) {

        bool poss_up = false;
        bool poss_diag = false;
        bool poss_left = false;

        int diag_value = INT32_MAX;
        int up_value = INT32_MAX;
        int left_value = INT32_MAX;

        // Load the possible directions and Values from DIAG, LEFT, UP
        if (x-1 >= 0 && y-1 >= 0) {diag_value = M.getValue(x-1,y-1);poss_diag = true;}
        if (y-1 >= 0) {up_value = M.getValue(x,y-1);poss_up = true;}
        if (x-1 >= 0) {left_value = M.getValue(x-1,y);poss_left = true;}

        // No direction possible? ( = LEFT_UP Corner)
        if (!(poss_diag && poss_left && poss_up)) {
            break;}

        // Is at the current position the same char? => DIAG
        if (!D(a[x-1],b[y-1])) {    res_A.push_back(a[x-1]);
            res_B.push_back(b[y-1]);
            x--;
            y--;
            continue;
        }

        // Is LEFT the minimum?
        if(Distance::is_A_minValue(left_value,diag_value,up_value)) {
            res_A.push_back(a[x-1]);
            res_B.push_back(Alphabet::toCharacter('-'));
            x--;
            continue;


        }

        // Is UP the minimum?
        if(Distance::is_A_minValue(up_value,diag_value,left_value)) {
            res_A.push_back(Alphabet::toCharacter('-'));
            res_B.push_back(b[y-1]);
            y--;
            //cout << C::BRED << " -> UP ";
            continue;


        }
        // Is DIAG the minimum?
        if(Distance::is_A_minValue(diag_value,up_value,left_value)) {
            res_A.push_back(a[x-1]);

            res_B.push_back(b[y-1]);
            x--;
            y--;
            continue;

        }

        break;

    }


    // ## reverse the backtraced sequence

    std::reverse(res_A.begin(),res_A.end());
    std::reverse(res_B.begin(),res_B.end());

    // finish

     return score;

}


