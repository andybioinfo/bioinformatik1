//
// Created by manjaro on 29.01.22.
//


#include "Examples.h"
#include "Block.h"


/** Example k-FOld with premixed Patients
 *
 * 20 Patients
 *  3 SNPs
 *
 * @return     kFold Object
 * */
std::vector<Block>  createKFold() {




}







/** Example SNP Database for Testing
 *
 * 40 Patients
 *  8 SNPs
 *
 * @return     Snipper Object
 * */
Snipper createSNPs() {


    Snipper S;
    S.getClassifics()
            << Cancer << Control << Cancer << Cancer << Control << Cancer << Control << Cancer << Control << Cancer
            << Cancer << Control << Cancer << Cancer << Control << Cancer << Control << Cancer << Control << Cancer
            << Cancer << Control << Cancer << Cancer << Control << Cancer << Control << Cancer << Control << Cancer
            << Cancer << Control << Cancer << Cancer << Control << Cancer << Control << Cancer << Control << Cancer
            << Cancer << Control << Cancer << Cancer << Control << Cancer << Control << Cancer << Control << Cancer;

    SingleSNP x1(S.getClassifics());
    SingleSNP x2(S.getClassifics());
    SingleSNP x3(S.getClassifics());
    SingleSNP x4(S.getClassifics());
    SingleSNP x5(S.getClassifics());
    SingleSNP x6(S.getClassifics());
    SingleSNP x7(S.getClassifics());
    SingleSNP x8(S.getClassifics());

    x1
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1);

    x2
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1);

    x3
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1);

    x4
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)
            << SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1);

    x5
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2);

    x6
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1);

    x7
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1);

    x8
            << SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(1)<< SingleSNP::int2gen(1)
            << SingleSNP::int2gen(1)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)
            << SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(0)
            << SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(2)<< SingleSNP::int2gen(1);

    S << x1 << x2 << x3 << x4 << x5 << x6 << x7 << x8;

    return S;
}

