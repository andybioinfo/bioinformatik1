//
// Created by manjaro on 27.01.22.
//

#ifndef BAYES_H
#define BAYES_H

#include <vector>
#include "States.h"
#include "Classifics.h"



/** Bayes
 *
 *
 * */
class NaiveBayes {

public:

    NaiveBayes();

    void train(const Snipper& X, const Classifics& Y);

    Classifics predict(const Snipper& X) const;

    void BayesTrainingsstunde();

    void outputFile(std::string output_file);

    int get_k_SIZE();
    int get_k_COUNT();
    Snipper getSNPs();
    Statistics getStats();

private:

Snipper X;
Statistics stats;

int k_SIZE;
int k_TEST;
int k_COUNT;

}







