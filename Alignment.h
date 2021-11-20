#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include "sequence/Sequence.h"

/*
 * ???
 * */
template <typename Alpha, typename Distance>
class Alignment {

public:
using Alphabet = Alpha;
using Characters = typename Alphabet::Characters;
Alignment(int gap_costs);
typedef Sequence<Alphabet> Seq;
int operator()(const Seq&a, const Seq&b);
//friend operator<<();
int get_GAP_COST();
private:
int GAP_COST;
Seq res_A;
Seq res_B;
};

template <typename Alpha, typename Distance>
Alignment<Alpha,Distance>::Alignment(int gap_costs) {GAP_COST = gap_costs;}

template <typename Alpha, typename Distance>
int Alignment<Alpha,Distance>::get_GAP_COST() {return GAP_COST;}


template <typename Alpha, typename Distance>
int Alignment<Alpha,Distance>::operator()(const Seq&a, const Seq&b) {

    // Create Matrix

    Matrix M(a.size()+1,b.size()+1);
    cout << C::BBLUE << "\n\n A: " << a;
    cout << "\n B: " << b << "\n";

    // Start Algorithm

    // Provisorisch Matrix mit Ergebnis füllen um Backtracer zu testen: (Matrix vom Übungsblatt)
    M.setValue(0,0,0);M.setValue(1,0,1);M.setValue(2,0,2);M.setValue(3,0,3);M.setValue(4,0,4);M.setValue(5,0,5);M.setValue(6,0,6);
    M.setValue(0,1,1);M.setValue(1,1,0);M.setValue(2,1,1);M.setValue(3,1,2);M.setValue(4,1,3);M.setValue(5,1,4);M.setValue(6,1,5);
    M.setValue(0,2,2);M.setValue(1,2,1);M.setValue(2,2,0);M.setValue(3,2,1);M.setValue(4,2,2);M.setValue(5,2,3);M.setValue(6,2,4);
    M.setValue(0,3,3);M.setValue(1,3,2);M.setValue(2,3,1);M.setValue(3,3,1);M.setValue(4,3,2);M.setValue(5,3,2);M.setValue(6,3,3);
    M.setValue(0,4,4);M.setValue(1,4,3);M.setValue(2,4,2);M.setValue(3,4,1);M.setValue(4,4,2);M.setValue(5,4,3);M.setValue(6,4,3);
    M.setValue(0,5,5);M.setValue(1,5,4);M.setValue(2,5,3);M.setValue(3,5,2);M.setValue(4,5,2);M.setValue(5,5,3);M.setValue(6,5,4);
    M.setValue(0,6,6);M.setValue(1,6,5);M.setValue(2,6,4);M.setValue(3,6,3);M.setValue(4,6,3);M.setValue(5,6,3);M.setValue(6,6,3);


    // Print Result-Matrix

    M.print();

    // Backtracing

    int x = M.ROW_MAX();
    int y = M.COL_MAX();
    Distance D;

    cout << C::BRED << "\n Backtracing {corner x:" << x << " y: "<< y <<" val: " << M.getValue(x,y) << " }  ";


    while(true) {

        //M.printTriangle(x,y);

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
        if (!(poss_diag && poss_left && poss_up)) {cout << "\n";break;}

        // Is at the current position the same char? => DIAG
        if (D(a[x],b[y])) {    res_A.push_back(a[x]);
                               res_B.push_back(b[y]);
                               x--;
                               y--;
                               cout << C::BRED << " -> DIAG ";
                               continue;
        }

        // Is LEFT the minimum?
        if(Distance::is_A_minValue(left_value,diag_value,up_value)) {
            res_A.push_back(a[x]);
            res_B.push_back(Alphabet::toCharacter('N'));
            x--;
            cout << C::BRED <<" -> LEFT ";
            continue;


        }

        // Is UP the minimum?
        if(Distance::is_A_minValue(up_value,diag_value,left_value)) {
            res_A.push_back(Alphabet::toCharacter('N'));
            res_B.push_back(b[y]);
            y--;
            cout << C::BRED << " -> UP ";
            continue;


        }
        // Is DIAG the minimum?
        if(Distance::is_A_minValue(diag_value,up_value,left_value)) {
            res_A.push_back(a[x]);

            res_B.push_back(b[y]);
            x--;
            y--;
            cout << C::BRED << " -> DIAG? ";
            continue;

        }

        // DIAG ??

        cout << C::BRED << " [ERROR]\n";
        break;

    }

    cout << C::BBLUE << "\n";

    //std::reverse(res_A.begin(),res_A.end());
    //std::reverse(res_B.begin(),res_B.end());

    cout << "\n result A: " << res_A;
    cout << "\n result B: " << res_B;

    // Was für ein Integer soll align returnen?
    cout << C::RESET << "\n\n";
    return 99;

}


#endif //ALIGNMENT_H
