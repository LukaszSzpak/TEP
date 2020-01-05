//
// Created by RC on 17.12.2019.
//

#include "WczytanieRozwiazania.h"

#include <utility>

WczytanieRozwiazania::WczytanieRozwiazania(std::string nazwaPliku) {
    this->nazwaPliku = std::move(nazwaPliku);
}

bool WczytanieRozwiazania::otworzPlik() {
    this->plikRozwiazania = std::ifstream(this->nazwaPliku, std::ios::in);

    return this->plikRozwiazania.is_open();
}

double *WczytanieRozwiazania::wczytajDaneRozwiazania() {
    int D;
    int F;
    int M;
    int S;
    std::string sSyf;

    this->getString();
    D = this->getInt(); //wczytaj ilosc dostawcow

    this->getString();
    F = this->getInt(); //wczytaj ilosc fabryk

    this->getString();
    M = this->getInt(); //wczytaj ilosc magazynow

    this->getString();
    S = getInt(); //wczytaj ilosc sklepow

    int rozmiar = (S * D) + (D * F) + (F * D);
    auto *pdSolution = new double[rozmiar];

    this->getString();
    int i = 0;
    for (; i < D * F; ++i) {
        pdSolution[i] = this->getDouble();
    } //wczytanie macierzy xd

    this->getString();
    for (; i < (D * F) + (F * M); ++i) {
        pdSolution[i] = this->getDouble();
    } //wczytanie macierzy xf

    this->getString();
    for (; i < rozmiar; ++i) {
        pdSolution[i] = this->getDouble();
    } //wczytanie macierzy xm

    return pdSolution;
}

std::string WczytanieRozwiazania::getString() {
    std::string newString;
    this->plikRozwiazania >> newString;

    return std::move(newString);
}

double WczytanieRozwiazania::getDouble() {
    double wartosc;
    this->plikRozwiazania >> wartosc;

    return wartosc;
}

int WczytanieRozwiazania::getInt() {
    int wartosc;
    this->plikRozwiazania >> wartosc;

    return wartosc;
}
