//
// Created by manjaro on 27.01.22.
//

#ifndef BAYES_H
#define BAYES_H

#include <vector>
#include "Statistics.h"
#include "snipper/Snipper.h"


/** Bayes
 *
 *
 * */
class NaiveBayes {

public:

    NaiveBayes(Snipper XY, int k_divisions);

    void BayesTrainingsstunde();

    void outputFile(std::string output_file);

    [[nodiscard]] int get_k_SIZE() const;
    [[nodiscard]] int get_k_COUNT() const;

    Snipper getSNPs();
    Statistics& getStats();

private:

Snipper X;
Statistics stats;

int k_SIZE;
int k_TEST;
int k_COUNT;

};



#endif



