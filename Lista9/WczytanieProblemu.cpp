//
// Created by RC on 16.12.2019.
//

#include "WczytanieProblemu.h"

WczytanieProblemu::WczytanieProblemu(std::string nazwaPliku) {
    this->nazwaPliku = std::move(nazwaPliku);
}

bool WczytanieProblemu::otworzPlik() {
    this->plikProblemu = std::ifstream(this->nazwaPliku, std::ios::in);

    return this->plikProblemu.is_open();
}

void WczytanieProblemu::wczytajDane(MscnProblem *nowyProblem) {
    std::string sSyf = "";
    int wartoscInt = 0;
    double wartoscDouble = 0.0;
    double wartoscDouble2 = 0.0;

    this->plikProblemu >> sSyf;
    this->plikProblemu >> wartoscInt;
    nowyProblem->setIloscDostawcow(wartoscInt); //ilosc Dostawcow

    this->plikProblemu >> sSyf;
    this->plikProblemu >> wartoscInt;
    nowyProblem->setIloscFabryk(wartoscInt); //ilosc fabryk

    this->plikProblemu >> sSyf;
    this->plikProblemu >> wartoscInt;
    nowyProblem->setIloscDystrybucji(wartoscInt); //ilosc magazynow

    this->plikProblemu >> sSyf;
    this->plikProblemu >> wartoscInt;
    nowyProblem->setIloscSklepow(wartoscInt); //ilosc sklepow

    nowyProblem->utworzTabliceIMacierze(); //utowrzenie macierzy i tablic

    this->plikProblemu >> sSyf;
    for (int i = 0; i < nowyProblem->getIloscDostawcow(); i++) {
        this->plikProblemu >> wartoscDouble;
        nowyProblem->setWydajnoscDostawcow(wartoscDouble, i);
    } //wczytanie wydajnosci dostawcow

    this->plikProblemu >> sSyf;
    for (int j = 0; j < nowyProblem->getIloscFabryk(); ++j) {
        this->plikProblemu >> wartoscDouble;
        nowyProblem->setWydajnoscFabryk(wartoscDouble, j);
    } //wczytanie wydajnosci fabryk

    this->plikProblemu >> sSyf;
    for (int i= 0; i < nowyProblem->getIloscDystrybucji(); i++) {
        this->plikProblemu >> wartoscDouble;
        nowyProblem->setWydajnoscCentrowDys(wartoscDouble, i);
    } //wczytanie wydajnosci centrow / magazynow

    this->plikProblemu >> sSyf;
    for (int i = 0; i < nowyProblem->getIloscSklepow(); i++) {
        this->plikProblemu >> wartoscDouble;
        nowyProblem->setPotrzebySklepow(wartoscDouble, i);
    } //wczytanie zapotrzebowania sklepow

    this->plikProblemu >> sSyf;
    for (int i = 0; i < nowyProblem->getIloscDostawcow(); i++)
        for (int j = 0 ; j < nowyProblem->getIloscFabryk(); j++) {
            this->plikProblemu >> wartoscDouble;
            nowyProblem->setDostawcaFabryka(wartoscDouble, i, j);
        }
    // ustawienie wartosci macierzy dostawca - fabryka //cd

    this->plikProblemu >> sSyf;
    for (int i = 0; i < nowyProblem->getIloscFabryk(); i++)
        for (int j = 0 ; j < nowyProblem->getIloscDystrybucji(); j++) {
            this->plikProblemu >> wartoscDouble;
            nowyProblem->setFabrykaMagazyn(wartoscDouble, i, j);
        }
    // ustawienie wartosci macierzy fabryka - magazyn //cf

    this->plikProblemu >> sSyf;
    for (int i = 0; i < nowyProblem->getIloscDystrybucji(); i++)
        for (int j = 0 ; j < nowyProblem->getIloscSklepow(); j++) {
            this->plikProblemu >> wartoscDouble;
            nowyProblem->setMagazynSklep(wartoscDouble, i, j);
        }
    // ustawienie wartosci macierzy magazyn - sklep //cm

    this->plikProblemu >> sSyf;
    for (int i = 0; i < nowyProblem->getIloscDostawcow(); i++) {
        this->plikProblemu >> wartoscDouble;
        nowyProblem->setKosztUslugDostawcy(wartoscDouble, i);
    } // ustawienie wartosci tablicy koszy usług dostawcy //ud

    this->plikProblemu >> sSyf;
    for (int i = 0; i < nowyProblem->getIloscFabryk(); i++) {
        this->plikProblemu >> wartoscDouble;
        nowyProblem->setKosztKorzystaniaFabryki(wartoscDouble, i);
    } // ustawienie wartosci tablicy koszy usług fabryki //uf

    this->plikProblemu >> sSyf;
    for (int i = 0; i < nowyProblem->getIloscDystrybucji(); i++) {
        this->plikProblemu >> wartoscDouble;
        nowyProblem->setKosztKorzystaniaCentra(wartoscDouble, i);
    } // ustawienie wartosci tablicy koszy usług magazynu //um

    this->plikProblemu >> sSyf;
    for (int i = 0; i < nowyProblem->getIloscSklepow(); i++) {
        this->plikProblemu >> wartoscDouble;
        nowyProblem->setZyskSprzedazyProduktu(wartoscDouble, i);
    } // ustawienie wartosci tablicy zysk sklepu //p

    this->plikProblemu >> sSyf;
    for (int i = 0; i < nowyProblem->getIloscDostawcow(); i++) {
        for (int j = 0; j < nowyProblem->getIloscFabryk(); ++j) {
            this->plikProblemu >> wartoscDouble;
            this->plikProblemu >> wartoscDouble2;
            nowyProblem->setZakresDostawcaFabryka(std::move(std::pair<double, double>(wartoscDouble, wartoscDouble2)), i, j);
        }
    } //ustawienie macierzy min max dla dostawca-fabryka //xdminmax

    this->plikProblemu >> sSyf;
    for (int i = 0; i < nowyProblem->getIloscFabryk(); i++) {
        for (int j = 0; j < nowyProblem->getIloscDystrybucji(); ++j) {
            this->plikProblemu >> wartoscDouble;
            this->plikProblemu >> wartoscDouble2;
            nowyProblem->setZakresFabrykaMagazyn(std::move(std::pair<double, double>(wartoscDouble, wartoscDouble2)), i, j);
        }
    } //ustawienie macierzy min max dla fabryka-magazyn //xfminmax

    this->plikProblemu >> sSyf;
    for (int i = 0; i < nowyProblem->getIloscDystrybucji(); i++) {
        for (int j = 0; j < nowyProblem->getIloscSklepow(); ++j) {
            this->plikProblemu >> wartoscDouble;
            this->plikProblemu >> wartoscDouble2;
            nowyProblem->setZakresMagazynSklep(std::move(std::pair<double, double>(wartoscDouble, wartoscDouble2)), i, j);
        }
    } //ustawienie macierzy min max dla magazyn-sklep //xmminmax

}


