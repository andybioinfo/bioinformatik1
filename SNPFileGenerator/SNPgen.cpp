//
// Created by manjaro on 01.02.22.
//

#include <fstream>
#include <random>
#include <iostream>
#include "SNPgen.h"

/** Create a random SNP Database-File
 *
 * @output      Your SNP-Database
 * @snps        Count of snps per patient
 * @patients    count of patients of your database (rows)
 * */
void SNPgenerator(std::string outputfile, int snps, int patients) {

    int lines = 1;
    int cols = 1;



    snps < 1 ? cols = 1 : cols = snps;
    patients < 1 ? lines = 1 : lines = patients;

    std::ofstream output(outputfile);

    std::cout << "\n create SNP - FiLe := " << lines << " patients " << cols << "SNP's\n";

    for (int pat = 0; pat < lines ; pat++) {

        // random class
        int random_classif = std::rand() % 2;
        output << random_classif << " ";

        // snps
        for (int snp = 0 ; snp < cols ; snp++) {
            int random_genotype = std::rand() % 3;
            output << random_genotype;
            if (snp != cols - 1 ) {output << " ";}
        }

        std::cout << " line " << pat << "/" << lines;

        if (pat != lines - 1 ) {output <<"\n";}


    }
    std::cout << "\n - finish\n";

}
