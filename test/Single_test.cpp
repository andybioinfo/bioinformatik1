//
// Created by manjaro on 21.01.22.
//

#include "../Snipper.h"

TEST(SingleSNP, ProbabilityTest)
{
Snipper S; 

S.getClassifics() << Cancer << Control << Cancer << Cancer << Control << Cancer;

SingleSNP x1(S.getClassifics()); 
SingleSNP x2(S.getClassifics()); 
SingleSNP x3(S.getClassifics()); 
SingleSNP x4(S.getClassifics()); 

x1 << Hetero << HomoMinor << HomoMajor << HomoMajor << HomoMinor << Hetero;

x2 << Hetero << Hetero << Hetero << Hetero << Hetero << Hetero;
x3 << HomoMinor << HomoMinor << HomoMinor << HomoMinor << HomoMinor << HomoMinor;
x4 << HomoMajor << HomoMajor << HomoMajor << HomoMajor << HomoMajor << HomoMajor;

S << x1 << x2 << x3 << x4;

double x0a = S[0].probability(Hetero);
double x0b = S[0].probability(HomoMinor);
double x0c = S[0].probability(HomoMajor);
double x0d = S[0].probability(Cancer,Hetero);
double x1a = S[1].probability(Hetero);
double x1b = S[1].probability(HomoMajor);
double x2  = S[2].probability(Hetero);


EXPECT_EQ( 0  , x0a  );
EXPECT_EQ( 0  , x0b  );
EXPECT_EQ( 0  , x0c  );
EXPECT_EQ( 0  , x0d  );
EXPECT_EQ( 0  , x1a  );
EXPECT_EQ( 0  , x1b  );
EXPECT_EQ( 0  , x2   );

}



TEST(SingleSNP, IndexOperatorTest)
{

Snipper S; 

S.getClassifics() << Cancer << Control << Cancer << Cancer << Control << Cancer;

SingleSNP x1(S.getClassifics()); 

x1 << Hetero << HomoMinor << HomoMajor << HomoMajor << HomoMinor << Hetero;

S << x1;
auto xx1 = S[0][2];
auto xx2 = S[0][3];
auto xx3 = S[0][4];

EXPECT_EQ( HomoMajor  , xx1   );
EXPECT_EQ( HomoMajor  , xx2   );
EXPECT_EQ( HomoMinor  , xx3   );

}





TEST(SingleSNP, PushBackOperatorTest)
{

Snipper S; 

S.getClassifics() << Cancer << Control << Cancer << Cancer << Control << Cancer;

SingleSNP x1(S.getClassifics()); 

x1 << Hetero << HomoMinor;

S << x1;

EXPECT_EQ( 2  , S[0].getSize() );

S[0] << Hetero << HomoMajor;;

EXPECT_EQ( 4  , S[0].getSize() );

auto a = S[0][2];
auto b = S[0][3];

EXPECT_EQ( Hetero     , a );
EXPECT_EQ( HomoMajor  , b );

}




TEST(Classifics, PushBackOperatorTest)
{

Snipper S; 

S.getClassifics() << Cancer ;

EXPECT_EQ( 2  , S.getClassifics().count() );

S.getClassifics() << Cancer << Cancer << Cancer << Control ;

EXPECT_EQ( 5  , S.getClassifics().count() );

auto a = S.getClassifics()[3];

EXPECT_EQ( Cancer , a );

}

TEST(Classifics, ProbabilityTest)
{

Snipper S; 

S.getClassifics() << Cancer << Cancer << Cancer << Control ;



EXPECT_EQ( 5  , S.getClassifics().count() );

double a = S.getClassifics().probability(Cancer);
double b = S.getClassifics().probability(Control);

EXPECT_EQ( 0.75 , a );
EXPECT_EQ( 0.25 , b );

}


TEST(Classifics, ShuffleTest) 
{

Snipper S; 

S.getClassifics() << Control << Cancer << Control << Control << Control << Cancer ;

bool shuffled = false;

for (int i = 0 ; i < 5 ; i++) { 

S.getClassifics().shuffle();
if ( S.getClassifics()[1] == Control ) { shuffled = true; }

 }

EXPECT_EQ( shuffled , true );


}


// 
TEST(Classifics, CountTest)
    {

        Snipper S; 

        S.getClassifics() << Control << Cancer << Control << Control << Control << Cancer ;

        EXPECT_EQ( 2 , S.getClassifics().countOf(Cancer));
        EXPECT_EQ( 4 , S.getClassifics().countOf(Control));
        EXPECT_EQ( 6 , S.getClassifics().count());

    }
 