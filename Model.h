//
// Created by manjaro on 01.02.22.
//

#ifndef BAYES_MODEL_H
#define BAYES_MODEL_H


#include <iostream>
#include "matrix/Matrix.h"
#include "snipper/States.h"

/** The Table Model for Naive Bayes
 *
 *
 * */
class Model {

public:

    // ## Constructor

    Model() = default;

    Model(int snpCount){
        this->M_Cancer  = Matrix(3,snpCount); // y = rows (Genotypes) ; x = Xi's
        this->M_Control = Matrix(3,snpCount); // y = rows (Genotypes) ; x = Xi's
        this->SNP_COUNT = snpCount;
    };

    // ## Setter/Getter small matrices

    void setPCancer(double pCancer)     {M_p_Cancer.setValue(0,0,pCancer);  };
    void setPControl(double pControl)   {M_p_Control.setValue(0,0,pControl);};
    double getPCancer()                 {return M_p_Cancer.getValue(0,0);   };
    double getPControl()                {return M_p_Control.getValue(0,0);  };
    [[nodiscard]] int getSNPcount() const             {return SNP_COUNT;};

    // ## Setter big matrices

    void setGenProbAtXi(Classification matrix, Genotype gen, int Xi,double probability)     {
        if (Xi<0 || Xi >= SNP_COUNT){
            std::stringstream s("");
            s << "Wow your Probability-Matrix-position to set this is over all thinkable borders :D .\n"
              << "Size is := '" << SNP_COUNT << "' Your input := '" << Xi << "'";
            throw std::invalid_argument( s.str() );}
        switch (matrix) {
            case Cancer  : switch (gen)
                {
                    case HomoMajor : M_Cancer.setValue(0,Xi,probability); break;
                    case Hetero    : M_Cancer.setValue(1,Xi,probability); break;
                    case HomoMinor : M_Cancer.setValue(2,Xi,probability); break;
                    default:  break;
                } break;
            case Control : switch (gen)
                {
                    case HomoMajor : M_Control.setValue(0,Xi,probability); break;
                    case Hetero    : M_Control.setValue(1,Xi,probability); break;
                    case HomoMinor : M_Control.setValue(2,Xi,probability); break;
                    default:  break;
                } break;
            default: break;
        }
    }

    // ## Getter big matrices

    double getGenProbAtXi(Classification matrix, Genotype gen, int Xi)     {
        if (Xi<0 || Xi >= SNP_COUNT){
            std::stringstream s("");
            s << "Wow your get Probabilty-Matrix-position is over all thinkable borders :D .\n"
              << "Size is := '" << SNP_COUNT << "' Your input := '" << Xi << "'";
            throw std::invalid_argument( s.str() );}
        switch (matrix) {
            case Cancer  : switch (gen)
                {
                    case HomoMajor : M_Cancer.getValue(0,Xi); break;
                    case Hetero    : M_Cancer.getValue(1,Xi); break;
                    case HomoMinor : M_Cancer.getValue(2,Xi); break;
                    default:  break;
                } break;
            case Control : switch (gen)
                {
                    case HomoMajor : M_Control.getValue(0,Xi); break;
                    case Hetero    : M_Control.getValue(1,Xi); break;
                    case HomoMinor : M_Control.getValue(2,Xi); break;
                    default:  break;
                } break;
            default: break;
        }
    }

    // ## print this model to console

    void print() {
        std::cout << C::BWHITE << "\nModel( size: " << C::BBLUE << SNP_COUNT << C::BWHITE  << " )"
                  << " p(Cancer) := " << C::BBLUE << getPCancer() << C::BWHITE
                  << " p(Control) := "<< C::BBLUE << getPControl() << C::RESET << "\n";
        std::cout << "Matrix Cancer ";
        M_Cancer.print();
        std::cout << "Matrix Control";
        M_Control.print();
    }

    // ## Fields


private:

    // Tables:
    Matrix M_Control    = Matrix(1,1); // y = rows (Genotypes ; x = Xi's
    Matrix M_Cancer     = Matrix(1,1); // y = rows (Genotypes ; x = Xi's
    Matrix M_p_Control  = Matrix(1,1);
    Matrix M_p_Cancer   = Matrix(1,1);
    int SNP_COUNT = 0;

};


#endif //BAYES_MODEL_H
