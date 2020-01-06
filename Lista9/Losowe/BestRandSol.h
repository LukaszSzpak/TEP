//
// Created by RC on 05.01.2020.
//

#ifndef LISTA9_BESTRANDSOL_H
#define LISTA9_BESTRANDSOL_H


#include "../MscnProblem.h"
#include "MyRandom.h"

#define DEF_ILOSC_PROB 50;
#define MIN 0;
#define MAX 100;

class BestRandSol {
public:
    BestRandSol(int iloscProb, double *rozwiazanie);
    BestRandSol(double *rozwiazanie);

    MscnProblem *getBestSolution();
    void ustawInstancje(int iloscDostawcow, int iloscFabryk, int iloscDystrybucji, int iloscSklepow, double *zyskProduktow);

private:
    int iloscProb;
    MscnProblem *pdSol;
    double *rozwiazanie;
    MyRandom myRandom;

    void znajdzNajlepsze();
    void losujProblem();

};


#endif //LISTA9_BESTRANDSOL_H
