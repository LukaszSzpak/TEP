//
// Created by RC on 14.01.2020.
//

#include "DE.h"

MscnProblem *DE::getNajlepszyProblem() {
    return this->najlepszyProblem;
}

void
DE::ustawInstancje(int iloscDostawcow, int iloscFabryk, int iloscDystrybucji, int iloscSklepow, double *zyskProduktow,
                   double *pdSol) {
    this->pdSol = pdSol;
    this->losowanieProblemu = new BestRandSol(pdSol);
    this->losowanieProblemu->ustawInstancje(iloscDostawcow, iloscFabryk, iloscDystrybucji, iloscSklepow, zyskProduktow);

}

void DE::znajdzNajlepszeRozwiazanie() {
    int ilePozostalo = ILOSC_PROB
    this->najlepszyWynik = INT16_MIN;

    while (ilePozostalo > 0) {
        this->losowanieProblemu->losujProblem();
        MscnProblem* tempProblem1 = this->losowanieProblemu->getBestSolution();

        this->losowanieProblemu->losujProblem();
        MscnProblem* tempProblem2 = this->losowanieProblemu->getBestSolution();

        this->losowanieProblemu->losujProblem();
        MscnProblem* tempProblem3 = this->losowanieProblemu->getBestSolution();

        this->wybierzNajlepsze(tempProblem1, tempProblem2, tempProblem3);

        ilePozostalo--;
    }
}

void DE::wybierzNajlepsze(MscnProblem *temp1, MscnProblem *temp2, MscnProblem *temp3) {
    this->losowanieProblemu->losujProblem();
    MscnProblem* problemWynikowy = this->losowanieProblemu->getBestSolution();
    int *kodBledy = new int;

    MscnProblem **tabProblemow = new MscnProblem*[4];

    tabProblemow[0] = temp1;
    tabProblemow[1] = temp2;
    tabProblemow[2] = temp3;
    tabProblemow[3] = problemWynikowy;

    int iterTab = 0;
    for (int i = 0; i < problemWynikowy->getIloscDostawcow(); i++) {
        iterTab = 0;
        if(this->czyZmieniamy())
            do {
                problemWynikowy->setWydajnoscDostawcow(tabProblemow[iterTab]->getWydajnoscDostawcow(i), i);
                iterTab++;
            } while (!problemWynikowy->bConstraintsSatisfied(this->pdSol, kodBledy));
    }

    for (int i = 0; i < problemWynikowy->getIloscFabryk(); i++) {
        iterTab = 0;
        if (this->czyZmieniamy())
            do {
                problemWynikowy->setWydajnoscFabryk(tabProblemow[iterTab]->getWydajnoscFabryk(i), i);
                iterTab++;
            } while (!problemWynikowy->bConstraintsSatisfied(this->pdSol, kodBledy));
    }

    for (int i = 0; i < problemWynikowy->getIloscDystrybucji(); i++) {
        iterTab = 0;
        if (this->czyZmieniamy())
            do {
                problemWynikowy->setWydajnoscCentrowDys(tabProblemow[iterTab]->getWydajnoscCentrowDys(i), i);
                iterTab++;
            } while (!problemWynikowy->bConstraintsSatisfied(this->pdSol, kodBledy));
    }

    for (int i = 0; i < problemWynikowy->getIloscSklepow(); i++) {
        iterTab = 0;
        if (this->czyZmieniamy())
            do {
                problemWynikowy->setPotrzebySklepow(tabProblemow[iterTab]->getPotrzebySklepow(i), i);
                iterTab++;
            } while (!problemWynikowy->bConstraintsSatisfied(this->pdSol, kodBledy));
    }

    for (int i = 0; i < problemWynikowy->getIloscDostawcow(); i++) {
        if (this->czyZmieniamy()) {
            double suma = 0;
            suma += temp1->getKosztUslugDostawcy(i);
            suma += temp2->getKosztUslugDostawcy(i);
            suma += temp3->getKosztUslugDostawcy(i);
            problemWynikowy->setKosztUslugDostawcy(suma/3, i);
        }
    }

    for (int i = 0; i < problemWynikowy->getIloscFabryk(); i++) {
        if (this->czyZmieniamy()) {
            double suma = 0;
            suma += temp1->getKosztKorzystaniaFabryki(i);
            suma += temp2->getKosztKorzystaniaFabryki(i);
            suma += temp3->getKosztKorzystaniaFabryki(i);
            problemWynikowy->setKosztKorzystaniaFabryki(suma/3, i);
        }
    }

    for (int i = 0; i < problemWynikowy->getIloscDystrybucji(); i++) {
        if (this->czyZmieniamy()) {
            double suma = 0;
            suma += temp1->getKosztKorzystaniaCentra(i);
            suma += temp2->getKosztKorzystaniaCentra(i);
            suma += temp3->getKosztKorzystaniaCentra(i);
            problemWynikowy->setKosztKorzystaniaCentra(suma/3, i);
        }
    }

    for (int i = 0; i < problemWynikowy->getIloscDostawcow(); i++) {
        for (int j = 0; j < problemWynikowy->getIloscFabryk(); j++) {
            iterTab = 0;
            if (this->czyZmieniamy()) {
                do {
                    problemWynikowy->setDostawcaFabryka(tabProblemow[iterTab]->getDostawcaFabryka(i, j), i, j);
                    iterTab++;
                } while (!problemWynikowy->bConstraintsSatisfied(this->pdSol, kodBledy));
            }
        }
    }

    for (int i = 0; i < problemWynikowy->getIloscFabryk(); i++) {
        for (int j = 0; j < problemWynikowy->getIloscDystrybucji(); j++) {
            iterTab = 0;
            if (this->czyZmieniamy()) {
                do {
                    problemWynikowy->setFabrykaMagazyn(tabProblemow[iterTab]->getFabrykaMagazyn(i, j), i, j);
                    iterTab++;
                } while (!problemWynikowy->bConstraintsSatisfied(this->pdSol, kodBledy));

            }
        }
    }

    for (int i = 0; i < problemWynikowy->getIloscDystrybucji(); i++) {
        for (int j = 0; j < problemWynikowy->getIloscSklepow(); j++) {
            iterTab = 0;
            if (this->czyZmieniamy()) {
                do {
                    problemWynikowy->setMagazynSklep(tabProblemow[iterTab]->getMagazynSklep(i, j), i, j);
                    iterTab++;
                } while (!problemWynikowy->bConstraintsSatisfied(this->pdSol, kodBledy));
            }
        }
    }

    double obliczonyWynikPd = problemWynikowy->dGetQuality(this->pdSol, kodBledy);

    if (obliczonyWynikPd > this->najlepszyWynik) {
        this->najlepszyWynik = obliczonyWynikPd;
        this->najlepszyProblem = problemWynikowy;
    }
}

bool DE::czyZmieniamy() {
    double progZamiany = PROG_ZAMIANY
    return (this->mojeLosowanie.getDouble(0, 1) < progZamiany);
}

void DE::najlepszeRozwiazanieSrednia(int wielkoscPopulacji, int iloscWybierana) {
    int* kodBledy = new int;

    MscnProblem **tabProblemow = new MscnProblem*[wielkoscPopulacji];
    for (int i = 0; i < wielkoscPopulacji; i++) {
        losowanieProblemu->losujProblem();
        tabProblemow[i] = this->losowanieProblemu->getBestSolution();
    }

    int *tabRoz = new int[iloscWybierana];
    for (int i = 0; i < iloscWybierana; i++) {
        tabRoz[i] = this->mojeLosowanie.getInt(0, wielkoscPopulacji-1);
    }

    for (int i = 0; i < iloscWybierana; i++) {
        for (int j = i; j < iloscWybierana - 1; j++) {
            if (tabProblemow[tabRoz[i]]->dGetQuality(this->pdSol, kodBledy) > tabProblemow[tabRoz[j]]->dGetQuality(this->pdSol, kodBledy)) {
                int temp = tabRoz[i];
                tabRoz[i] = tabRoz[j];
                tabRoz[j] = temp;
            }
        }
    }
    this->wybierzNajlepsze(tabProblemow[tabRoz[0]], tabProblemow[tabRoz[1]], tabProblemow[tabRoz[2]]);
}

