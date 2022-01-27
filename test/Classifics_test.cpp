//
// Created by manjaro on 24.01.22.
//

#include <gtest/gtest.h>
#include "../Snipper.h"

/*

Tests:

 - Contructor
 - shuffle()
 - probability(Classification)
 - custom operator []           
 - custom operator <<           
 - countOf(Classification)      
 - count()                      

*/


// Tests if a new Class empty
TEST(Classifics, InitTest)
    {

        Snipper S; 

        EXPECT_EQ( 0  , S.getClassifics().count() );

    }



// Tests if the Y-Vector shuffled with shuffle()
TEST(Classifics, ShuffleTest) 
    {

        Snipper S; 

        S.getClassifics() << Control << Cancer << Control << Control << Control << Cancer ;
 
        bool shuffled = false;
 
        while(true) {
       
            S.getClassifics().shuffle();
            if ( S.getClassifics()[1] == Control ) { 
                                                      // if Cancer changed to Control then shuffled
                                                      shuffled = true;
                                                      break; 
                                                   }
       
         }

        EXPECT_EQ( shuffled , true );

    }



// Tests if the probability of all items correct
TEST(Classifics, ProbabilityTest)
    {

        Snipper S1; 
        Snipper S2;

        S1.getClassifics() << Cancer << Cancer << Cancer << Control ;
        S2.getClassifics() << Control << Control ;

        EXPECT_EQ( 4  , S1.getClassifics().count() );
        EXPECT_EQ( 2  , S2.getClassifics().count() );

        EXPECT_EQ( 0.75 , S1.getClassifics().probability(Cancer) );
        EXPECT_EQ( 0.25 , S1.getClassifics().probability(Control) );
        EXPECT_EQ( 0 , S2.getClassifics().probability(Cancer) );
        EXPECT_EQ( 1 , S2.getClassifics().probability(Control) );

    }



// Tests if the operator [] returns the correct item
TEST(Classifics, GetIndexOperatorTest)
    {

        Snipper S; 

        S.getClassifics() << Cancer << Cancer << Cancer << Control ;

        EXPECT_EQ( 4      , S.getClassifics().count() );
        EXPECT_EQ( Cancer , S.getClassifics()[0] );
        EXPECT_EQ( Cancer , S.getClassifics()[1] );
        EXPECT_EQ( Cancer , S.getClassifics()[2] );
        EXPECT_EQ( Control , S.getClassifics()[3] );

    }



// Tests if the operator << add correctly all items
TEST(Classifics, PushBackOperatorTest)
    {

        Snipper S; 
        S.getClassifics() << Cancer ;
        EXPECT_EQ( 1 , S.getClassifics().count() );

        S.getClassifics() << Cancer << Cancer << Cancer << Control ;
        EXPECT_EQ( 5  , S.getClassifics().count() );

        Classification cls = S.getClassifics()[3];

        EXPECT_EQ( Cancer , cls );

    }



// Tests if the count of All and Cancer / Control correct
TEST(Classifics, ToStringTest)
    {

        Snipper S0;
        Snipper S1; S1.getClassifics() << Control << Cancer << Control << Control << Control << Cancer ;
        Snipper S2; S2.getClassifics() << Control << Cancer << Control << Control << Control << Cancer << Control << Control << Cancer << Cancer ;

        EXPECT_EQ( "Y(size:0) {  }" , S0.getClassifics().to2String());              // Size 0 : Values: 
        EXPECT_EQ( "Y(size:6) { 010001 }" , S1.getClassifics().to2String());        // Size 6 : Values: 010011
        EXPECT_EQ( "Y(size:10) { 0100010011 }" , S2.getClassifics().to2String());   // Size 10 : Values: 0100010011

    }



// Tests if the count of All and Cancer / Control correct
TEST(Classifics, CountTest)
    {

        Snipper S; 

        S.getClassifics() << Control << Cancer << Control << Control << Control << Cancer ;

        EXPECT_EQ( 2 , S.getClassifics().countOf(Cancer));   // 2
        EXPECT_EQ( 4 , S.getClassifics().countOf(Control));  // 4 
        EXPECT_EQ( 6 , S.getClassifics().count());           // 2 + 4 = 6

    }
