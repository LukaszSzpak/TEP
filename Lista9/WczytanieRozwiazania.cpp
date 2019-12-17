//
// Created by RC on 17.12.2019.
//

#include "WczytanieRozwiazania.h"

WczytanieRozwiazania::WczytanieRozwiazania(std::string nazwaPliku) {
    this->nazwaPliku = nazwaPliku;
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
    double wartoscDouble = 0.0;
    std::string sSyf = "";

    this->plikRozwiazania >> sSyf;
    this->plikRozwiazania >> D; //wczytaj ilosc dostawcow

    this->plikRozwiazania >> sSyf;
    this->plikRozwiazania >> F; //wczytaj ilosc fabryk

    this->plikRozwiazania >> sSyf;
    this->plikRozwiazania >> M; //wczytaj ilosc magazynow

    this->plikRozwiazania >> sSyf;
    this->plikRozwiazania >> S; //wczytaj ilosc sklepow

    int rozmiar = (S * D) + (D * F) + (F * D);
    double *pdSolution = new double[rozmiar];

    this->plikRozwiazania >> sSyf;
    int i = 0;
    for (; i < D * F; ++i) {
        this->plikRozwiazania >> wartoscDouble;
        pdSolution[i] = wartoscDouble;
    } //wczytanie macierzy xd

    this->plikRozwiazania >> sSyf;
    for (; i < (D * F) + (F * M); ++i) {
        this->plikRozwiazania >> wartoscDouble;
        pdSolution[i] = wartoscDouble;
    } //wczytanie macierzy xf

    this->plikRozwiazania >> sSyf;
    for (; i < rozmiar; ++i) {
        this->plikRozwiazania >> wartoscDouble;
        pdSolution[i] = wartoscDouble;
    } //wczytanie macierzy xm

    return pdSolution;
}
