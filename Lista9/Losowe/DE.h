//
// Created by RC on 14.01.2020.
//

#ifndef LISTA9_DE_H
#define LISTA9_DE_H

#include "../MscnProblem.h"
#include "BestRandSol.h"

#define PROG_ZAMIANY 0.5;
#define ILOSC_PROB 5;

class DE {
public:
    MscnProblem* getNajlepszyProblem();
    void ustawInstancje(int iloscDostawcow, int iloscFabryk, int iloscDystrybucji, int iloscSklepow, double *zyskProduktow, double* pdSol);
    void znajdzNajlepszeRozwiazanie();
    void najlepszeRozwiazanieSrednia(int wielkoscPopulacji, int iloscWybierana);

private:
    double najlepszyWynik;
    MscnProblem* najlepszyProblem;
    BestRandSol* losowanieProblemu;
    MyRandom mojeLosowanie;

    double* pdSol;

    void wybierzNajlepsze(MscnProblem* temp1, MscnProblem* temp2, MscnProblem* temp3);
    bool czyZmieniamy();

};


#endif //LISTA9_DE_H
