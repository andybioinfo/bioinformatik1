#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include "sequence/Sequence.h"
#include "console.h"
#include "Matrix.h"
#include "Distance.h"
using namespace std;

/*
 * Class for calculate the Alignment between 2 Sequences with the
 * Needleman Algorithm
 * */
template <typename Alpha, typename Distance>
class Alignment {

public:

    using Alphabet = Alpha;

    using Characters = typename Alphabet::Characters;

    Alignment(int gap_costs);

    typedef Sequence<Alphabet> Seq;

    int operator()(const Seq&a, const Seq&b);

    template <typename A, typename D>
    friend std::ostream& operator<<(std::ostream &out, const Alignment<A, D> alignment) ;

    int get_GAP_COST();

private:

    int GAP_COST;
    Seq res_A;
    Seq res_B;

};

/*
 *
 * Alignment-Object
 * @gap_costs Set the Gap-Costs for this Alignment-Object
 * */
template <typename Alpha, typename Distance>
    Alignment<Alpha,Distance>::Alignment(int gap_costs) {
        GAP_COST = gap_costs;
    }


/*
 * Gap-Costs
 * @return the Gap-Costs of this alignment-instance
 * */
template <typename Alpha, typename Distance>
    int Alignment<Alpha,Distance>::get_GAP_COST() {
        return GAP_COST;
    }

/*
 * Operator for outstream
 * @return the aligned sequences together
 * */
template <typename Alpha, typename Distance>
    std::ostream& operator<<(std::ostream &out, const Alignment<Alpha, Distance> alignment) {
        /*
         * Operator out: Aligment with Line Break after 45 Characters for both
         * lines. Example:
         *
         * A | TGGAT TGGAT NNNAT CCGNN NNNAT CCGNN NNNAT CCGNN NNNAT
         * B | TGGAT TGGAT NNNAT CCGNN NNNAT NNNAT TGGAT NNNAT CCGNN
         *
         * A | CCGNN TG
         * B | CCGCC NN
         *
         * */

     auto iter_A = alignment.res_A.begin();
     auto iter_B = alignment.res_B.begin();
     int counter5 = 1;
     int counter45 = 1;


     while (iter_A != alignment.res_A.end()) {

         counter5 = 1;
         counter45 = 1;
         out << "\n A | ";

         while (iter_A != alignment.res_A.end()) {
            out << Alpha::toChar(iter_A.operator*());iter_A++;
            if (counter5 < 5)   {counter5++;}  else {counter5 = 1;out << " ";}
            if (counter45 < 45) {counter45++;} else {counter45 = 1;break;    }
         }

         counter5 = 1;
         counter45 = 1;
         out << "\n B | ";

         while (iter_B != alignment.res_B.end()) {
             out << Alpha::toChar(iter_B.operator*());iter_B++;
             if (counter5 < 5)   {counter5++;}  else {counter5 = 1;out << " ";}
             if (counter45 < 45) {counter45++;} else {counter45 = 1;break;    }
         }

         out << "\n";

     }

    return out;
}


#endif //ALIGNMENT_H
