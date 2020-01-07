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
    this->znajdzNajlepsze();

    return this->pdSol;
}

void BestRandSol::ustawInstancje(int iloscDostawcow, int iloscFabryk, int iloscDystrybucji, int iloscSklepow, double *zyskProduktow) {
    this->pdSol->setIloscDostawcow(iloscDostawcow);
    this->pdSol->setIloscFabryk(iloscFabryk);
    this->pdSol->setIloscDystrybucji(iloscDystrybucji);
    this->pdSol->setIloscSklepow(iloscSklepow);

    this->pdSol->utworzTabliceIMacierze();
    this->pdSol->pdSolutionDoMacierzy(this->rozwiazanie);

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
    double najlepszeRozWynik = INT16_MIN;

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
    double min = MIN
    double max = MAX
    double maxKoszt = MAX_KOSZT

    for (int i = 0; i < this->pdSol->getIloscDostawcow(); i++) {
        double ileMuszeMinDostraczyc = 0;
        for (int j = 0; j < this->pdSol->getIloscFabryk(); j++) {
            ileMuszeMinDostraczyc += this->pdSol->getDostraczenieDostawcaFabryka(i, j);
        }
        double wylosowanaWartosc = this->myRandom.getDouble(ileMuszeMinDostraczyc, max);
        this->pdSol->setWydajnoscDostawcow(wylosowanaWartosc, i);
    }

    for (int i = 0; i < this->pdSol->getIloscFabryk(); i++) {
        double ileMusiMinWyprodukowacFabryka = 0;
        for (int j = 0; j < this->pdSol->getIloscDystrybucji(); j++) {
            ileMusiMinWyprodukowacFabryka += this->pdSol->getDostarczenieFabrykaMagazyn(i, j);
        }
        double wylosowanaWartosc = this->myRandom.getDouble(ileMusiMinWyprodukowacFabryka, max);
        this->pdSol->setWydajnoscFabryk(wylosowanaWartosc, i);
    }

    for (int i = 0; i < this->pdSol->getIloscDystrybucji(); i++) {
        double ileMusiMinWydajnosciMagazyn = 0;
        for (int j = 0; j < this->pdSol->getIloscSklepow(); j++) {
            ileMusiMinWydajnosciMagazyn += this->pdSol->getDostarczenieMagazynSklep(i, j);
        }
        double wylosowanaWartosc = this->myRandom.getDouble(ileMusiMinWydajnosciMagazyn, max);
        this->pdSol->setWydajnoscCentrowDys(wylosowanaWartosc, i);
    }

    for (int i = 0; i < this->pdSol->getIloscSklepow(); i++) {
        double minSuma = 0;
        for (int j = 0; j < this->pdSol->getIloscDystrybucji(); j++) {
            minSuma += this->pdSol->getDostarczenieMagazynSklep(j, i);
        }
        double wylosowanaWartosc = this->myRandom.getDouble(minSuma, max);
        this->pdSol->setPotrzebySklepow(wylosowanaWartosc, i);
    }

    for (int i = 0; i < this->pdSol->getIloscFabryk(); i++) {
        this->pdSol->setKosztKorzystaniaFabryki(this->myRandom.getDouble(0, maxKoszt), i);
    }

    for (int i = 0; i < this->pdSol->getIloscDostawcow(); i++) {
        this->pdSol->setKosztUslugDostawcy(this->myRandom.getDouble(0, maxKoszt), i);
    }

    for (int i = 0; i < this->pdSol->getIloscDystrybucji(); i++) {
        this->pdSol->setKosztKorzystaniaCentra(this->myRandom.getDouble(0, maxKoszt), i);
    }

    maxKoszt = MAX_KOSZT_DOSTAWCA_FABRYKA
    for (int i = 0; i < this->pdSol->getIloscDostawcow(); i++) {
        for (int j = 0; j < this->pdSol->getIloscFabryk(); j++) {
            this->pdSol->setDostawcaFabryka(this->myRandom.getDouble(0, maxKoszt), i, j);
        }
    }

    maxKoszt = MAX_KOSZT_FABRYKA_MAGAZYN
    for (int i = 0; i < this->pdSol->getIloscFabryk(); i++) {
        for (int j = 0; j < this->pdSol->getIloscDystrybucji(); j++) {
            this->pdSol->setFabrykaMagazyn(this->myRandom.getDouble(0, maxKoszt), i, j);
        }
    }

    maxKoszt = MAX_KOSZT_MAGAZYN_SKLEP
    for (int i = 0; i < this->pdSol->getIloscDystrybucji(); i++) {
        for (int j = 0; j < this->pdSol->getIloscSklepow(); j++) {
            this->pdSol->setMagazynSklep(this->myRandom.getDouble(0, maxKoszt), i, j);
        }
    }

}
