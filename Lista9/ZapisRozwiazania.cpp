//
// Created by RC on 17.12.2019.
//

#include "ZapisRozwiazania.h"

ZapisRozwiazania::ZapisRozwiazania(std::string nazwaPliku) {
    this->nazwaPliku = std::move(nazwaPliku);
}

bool ZapisRozwiazania::otworzPlik() {
    this->plikRozwiazania.open(this->nazwaPliku, std::ios::out);

    return this->plikRozwiazania.is_open();
}

void ZapisRozwiazania::zapiszRozwiazanie(MscnProblem *problemDoZapisu) {
    this->saveString("D ");
    this->saveInt(problemDoZapisu->getIloscDostawcow());

    this->saveString("\nF ");
    this->saveInt(problemDoZapisu->getIloscFabryk());

    this->saveString("\nM ");
    this->saveInt(problemDoZapisu->getIloscDystrybucji());

    this->saveString("\nS ");
    this->saveInt(problemDoZapisu->getIloscSklepow());

    this->saveString("\nxd");
    for (int i = 0; i < problemDoZapisu->getIloscDostawcow(); i++) {
        this->saveString("\n");

        for (int j = 0; j < problemDoZapisu->getIloscFabryk(); ++j) {
            this->saveDouble(problemDoZapisu->getDostraczenieDostawcaFabryka(i, j));
            this->saveString(" ");
        }
    }

    this->saveString("\nxf");
    for (int i = 0; i < problemDoZapisu->getIloscFabryk(); i++) {
        this->saveString("\n");

        for (int j = 0; j < problemDoZapisu->getIloscDystrybucji(); ++j) {
            this->saveDouble(problemDoZapisu->getDostarczenieFabrykaMagazyn(i, j));
            this->saveString(" ");
        }
    }

    this->saveString("\nxm");
    for (int i = 0; i < problemDoZapisu->getIloscDystrybucji(); i++) {
        this->saveString("\n");

        for (int j = 0; j < problemDoZapisu->getIloscSklepow(); ++j) {
            this->saveDouble(problemDoZapisu->getDostarczenieMagazynSklep(i, j));
            this->saveString(" ");
        }
    }

    this->plikRozwiazania.close();
}

void ZapisRozwiazania::saveString(std::string wartosc) {
    this->plikRozwiazania << wartosc;
}

void ZapisRozwiazania::saveDouble(double wartosc) {
    this->plikRozwiazania << wartosc;
}

void ZapisRozwiazania::saveInt(double wartosc) {
    this->plikRozwiazania << wartosc;
}
