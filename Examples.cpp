//
// Created by manjaro on 29.01.22.
//


#include "Examples.h"
#include "Block.h"


/** Example Database with premixed Patients
 *
 * 50 Patients
 *  3 SNPs
 *
 * @return     SNP-Database
 * */
Snipper  createExample2() {

        Snipper S;
        S.getClassifics()
            << Cancer << Control << Cancer  << Cancer  << Cancer 
            << Cancer << Cancer  << Control << Control << Cancer
            << Cancer << Control << Control << Control << Cancer
            << Cancer << Control << Cancer  << Cancer  << Cancer
            << Cancer << Control << Control << Control << Cancer
            << Cancer << Control << Cancer  << Cancer  << Cancer
            << Cancer << Control << Control << Control << Cancer
            << Cancer << Control << Cancer  << Cancer  << Cancer
            << Cancer << Control << Control << Control << Cancer
            << Cancer << Control << Cancer  << Cancer  << Cancer;

    SingleSNP x1(S.getClassifics());
    SingleSNP x2(S.getClassifics());
    SingleSNP x3(S.getClassifics());

   x1
        << SingleSNP::int2gen(1) << SingleSNP::int2gen(1) << SingleSNP::int2gen(1) << SingleSNP::int2gen(0) << SingleSNP::int2gen(1)
        << SingleSNP::int2gen(1) << SingleSNP::int2gen(1) << SingleSNP::int2gen(1) << SingleSNP::int2gen(1) << SingleSNP::int2gen(1)
        << SingleSNP::int2gen(1) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(1)
        << SingleSNP::int2gen(1) << SingleSNP::int2gen(1) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0)
        << SingleSNP::int2gen(1) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(1)
        << SingleSNP::int2gen(1) << SingleSNP::int2gen(1) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0)
        << SingleSNP::int2gen(1) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(1)
        << SingleSNP::int2gen(1) << SingleSNP::int2gen(1) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0);

   x2
        << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(1) << SingleSNP::int2gen(0)
        << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0)
        << SingleSNP::int2gen(0) << SingleSNP::int2gen(1) << SingleSNP::int2gen(1) << SingleSNP::int2gen(1) << SingleSNP::int2gen(0)
        << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(1) << SingleSNP::int2gen(1) << SingleSNP::int2gen(1)
        << SingleSNP::int2gen(1) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(1)
        << SingleSNP::int2gen(1) << SingleSNP::int2gen(1) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0)
        << SingleSNP::int2gen(1) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(1)
        << SingleSNP::int2gen(1) << SingleSNP::int2gen(1) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0);

   x3
        << SingleSNP::int2gen(2) << SingleSNP::int2gen(2) << SingleSNP::int2gen(2) << SingleSNP::int2gen(2) << SingleSNP::int2gen(2)
        << SingleSNP::int2gen(2) << SingleSNP::int2gen(2) << SingleSNP::int2gen(2) << SingleSNP::int2gen(2) << SingleSNP::int2gen(2)
        << SingleSNP::int2gen(2) << SingleSNP::int2gen(2) << SingleSNP::int2gen(2) << SingleSNP::int2gen(2) << SingleSNP::int2gen(2)
        << SingleSNP::int2gen(2) << SingleSNP::int2gen(2) << SingleSNP::int2gen(2) << SingleSNP::int2gen(2) << SingleSNP::int2gen(2)
        << SingleSNP::int2gen(1) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(1)
        << SingleSNP::int2gen(1) << SingleSNP::int2gen(1) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0)
        << SingleSNP::int2gen(1) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(1)
        << SingleSNP::int2gen(1) << SingleSNP::int2gen(1) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0) << SingleSNP::int2gen(0);

    S << x1 << x2 << x3;

    return S;
    
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

