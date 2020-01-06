//
// Created by RC on 05.01.2020.
//

#include "BestRandSol.h"

BestRandSol::BestRandSol(int iloscProb, double *rozwiazanie) {
    this->iloscProb = iloscProb;
    this->pdSol = new MscnProblem();
    this->rozwiazanie = rozwiazanie;
    this->myRandom = MyRandom();
}

BestRandSol::BestRandSol( double *rozwiazanie) {
    this->iloscProb = DEF_ILOSC_PROB
    this->pdSol = new MscnProblem();
    this->rozwiazanie = rozwiazanie;
    this->myRandom = MyRandom();
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

    double min = MIN
    double max = MAX
    std::pair<double, double> paraMinMax = std::pair<double, double>(min, max);

    for (int i = 0; i < this->pdSol->getIloscDystrybucji(); i++)
        for (int j = 0; j < this->pdSol->getIloscSklepow(); j++)
            this->pdSol->setZakresMagazynSklep(paraMinMax, i, j);

    for (int i = 0; i < this->pdSol->getIloscFabryk(); i++)
        for (int j = 0; j < this->pdSol->getIloscDystrybucji(); j++)
            this->pdSol->setZakresFabrykaMagazyn(paraMinMax, i, j);

    for (int i = 0; i < this->pdSol->getIloscDostawcow(); i++)
        for (int j = 0; j < this->pdSol->getIloscFabryk(); j++)
            this->pdSol->setZakresDostawcaFabryka(paraMinMax, i, j);

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
                if (najlepszeRoz != nullptr)
                    delete(najlepszeRoz);

                najlepszeRoz = this->pdSol;
            }
        }
    }

    this->pdSol = najlepszeRoz;
}

void BestRandSol::losujProblem() {

    double sumaWydajnosciDostawcow = 0;
    double sumaWydajnosciFabryk = 0;
    double sumaWydajnosciMagazynow = 0;
    double sumaPotrzebSklepow = 0;

    double min = MIN
    double max = MAX

    for (int i = 0; i < this->pdSol->getIloscDostawcow(); i++) {
        double wylosowanaWartosc = this->myRandom.getDouble(min, max);
        this->pdSol->setWydajnoscDostawcow(wylosowanaWartosc, i);
        sumaWydajnosciDostawcow += wylosowanaWartosc;
    }

    for (int i = 0; i < this->pdSol->getIloscFabryk(); i++) {
        double wylosowanaWartosc = this->myRandom.getDouble(min, max * 0.9);
        this->pdSol->setWydajnoscFabryk(wylosowanaWartosc, i);
        sumaWydajnosciFabryk += sumaWydajnosciFabryk;
    }

    for (int i = 0; i < this->pdSol->getIloscDystrybucji(); i++) {
        double wylosowanaWartosc = this->myRandom.getDouble(min, max * 0.8);
        this->pdSol->setWydajnoscCentrowDys(wylosowanaWartosc, i);
        sumaWydajnosciMagazynow += wylosowanaWartosc;
    }

    for (int i = 0; i < this->pdSol->getIloscSklepow(); i++) {
        double wylosowanaWartosc = this->myRandom.getDouble(min, max);
        this->pdSol->setPotrzebySklepow(wylosowanaWartosc, i);
        sumaPotrzebSklepow += wylosowanaWartosc;
    }

}
