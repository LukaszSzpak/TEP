//
// Created by RC on 05.01.2020.
//

#include "BestRandSol.h"

BestRandSol::BestRandSol(int iloscProb, double *rozwiazanie) {
    this->iloscProb = iloscProb;
    this->pdSol = new MscnProblem();
    this->rozwiazanie = rozwiazanie;
}

BestRandSol::BestRandSol( double *rozwiazanie) {
    this->iloscProb = DEF_ILOSC_PROB
    this->pdSol = new MscnProblem();
    this->rozwiazanie = rozwiazanie;
}

MscnProblem *BestRandSol::getBestSolution() {
    return this->pdSol;
}

void BestRandSol::ustawInstancje(int iloscDostawcow, int iloscFabryk, int iloscDystrybucji, int iloscSklepow, double *zyskProduktow) {
    this->pdSol->setIloscDostawcow(iloscDostawcow);
    this->pdSol->setIloscFabryk(iloscFabryk);
    this->pdSol->setIloscDystrybucji(iloscDystrybucji);
    this->pdSol->setIloscSklepow(iloscSklepow);

    this->pdSol->utworzTabliceIMacierze();

    for (int i = 0; i < iloscSklepow; i++)
        this->pdSol->setZyskSprzedazyProduktu(zyskProduktow[i], i);
}

void BestRandSol::znajdzNajlepsze() {
    MscnProblem *najlepszeRoz = nullptr;
    double najlepszeRozWynik = 0.0;

    for (int i = 0; i < this->iloscProb; i++) {
        this->losujProblem();
        if (this->pdSol->bConstraintsSatisfied(this->rozwiazanie, new int)) {
            double tempWynik = this->pdSol->dGetQuality(rozwiazanie, new int);

            if (tempWynik > najlepszeRozWynik) {
                najlepszeRozWynik = tempWynik;
                najlepszeRoz = this->pdSol;
            }
        }
    }

    this->pdSol = najlepszeRoz;
}

void BestRandSol::losujProblem() {

}
