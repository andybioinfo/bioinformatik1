//
// Created by manjaro on 21.01.22.
//

#ifndef SNIPPER_STATES_H
#define SNIPPER_STATES_H

/*
  The Genotypes ( X-Col )
*/
enum Genotype {
    HomoMajor,  // Int = 0
    Hetero,     // Int = 1
    HomoMinor   // Int = 2
};

/*
  The Classifications ( Y-Col )
*/
enum Classification {
    Control,    // Int = 0
    Cancer      // Int = 1
};

#endif //SNIPPER_STATES_H
