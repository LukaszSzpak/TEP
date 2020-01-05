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
    int wartoscInt = 0;
    double wartoscDouble = 0.0;
    double wartoscDouble2 = 0.0;

    this->getString();
    wartoscInt = this->getInt();
    nowyProblem->setIloscDostawcow(wartoscInt); //ilosc Dostawcow

    this->getString();
    wartoscInt = this->getInt();
    nowyProblem->setIloscFabryk(wartoscInt); //ilosc fabryk

    this->getString();
    wartoscInt = this->getInt();
    nowyProblem->setIloscDystrybucji(wartoscInt); //ilosc magazynow

    this->getString();
    wartoscInt = this->getInt();
    nowyProblem->setIloscSklepow(wartoscInt); //ilosc sklepow

    nowyProblem->utworzTabliceIMacierze(); //utowrzenie macierzy i tablic

    this->getString();
    for (int i = 0; i < nowyProblem->getIloscDostawcow(); i++) {
        wartoscDouble = this->getDouble();
        nowyProblem->setWydajnoscDostawcow(wartoscDouble, i);
    } //wczytanie wydajnosci dostawcow

    this->getString();
    for (int j = 0; j < nowyProblem->getIloscFabryk(); ++j) {
        wartoscDouble = this->getDouble();
        nowyProblem->setWydajnoscFabryk(wartoscDouble, j);
    } //wczytanie wydajnosci fabryk

    this->getString();
    for (int i= 0; i < nowyProblem->getIloscDystrybucji(); i++) {
        wartoscDouble = this->getDouble();
        nowyProblem->setWydajnoscCentrowDys(wartoscDouble, i);
    } //wczytanie wydajnosci centrow / magazynow

    this->getString();
    for (int i = 0; i < nowyProblem->getIloscSklepow(); i++) {
        wartoscDouble = this->getDouble();
        nowyProblem->setPotrzebySklepow(wartoscDouble, i);
    } //wczytanie zapotrzebowania sklepow

    this->getString();
    for (int i = 0; i < nowyProblem->getIloscDostawcow(); i++)
        for (int j = 0 ; j < nowyProblem->getIloscFabryk(); j++) {
            wartoscDouble = this->getDouble();
            nowyProblem->setDostawcaFabryka(wartoscDouble, i, j);
        }
    // ustawienie wartosci macierzy dostawca - fabryka //cd

    this->getString();
    for (int i = 0; i < nowyProblem->getIloscFabryk(); i++)
        for (int j = 0 ; j < nowyProblem->getIloscDystrybucji(); j++) {
            wartoscDouble = this->getDouble();
            nowyProblem->setFabrykaMagazyn(wartoscDouble, i, j);
        }
    // ustawienie wartosci macierzy fabryka - magazyn //cf

    this->getString();
    for (int i = 0; i < nowyProblem->getIloscDystrybucji(); i++)
        for (int j = 0 ; j < nowyProblem->getIloscSklepow(); j++) {
            wartoscDouble = this->getDouble();
            nowyProblem->setMagazynSklep(wartoscDouble, i, j);
        }
    // ustawienie wartosci macierzy magazyn - sklep //cm

    this->getString();
    for (int i = 0; i < nowyProblem->getIloscDostawcow(); i++) {
        wartoscDouble = this->getDouble();
        nowyProblem->setKosztUslugDostawcy(wartoscDouble, i);
    } // ustawienie wartosci tablicy koszy usług dostawcy //ud

    this->getString();
    for (int i = 0; i < nowyProblem->getIloscFabryk(); i++) {
        wartoscDouble = this->getDouble();
        nowyProblem->setKosztKorzystaniaFabryki(wartoscDouble, i);
    } // ustawienie wartosci tablicy koszy usług fabryki //uf

    this->getString();
    for (int i = 0; i < nowyProblem->getIloscDystrybucji(); i++) {
        wartoscDouble = this->getDouble();
        nowyProblem->setKosztKorzystaniaCentra(wartoscDouble, i);
    } // ustawienie wartosci tablicy koszy usług magazynu //um

    this->getString();
    for (int i = 0; i < nowyProblem->getIloscSklepow(); i++) {
        wartoscDouble = this->getDouble();
        nowyProblem->setZyskSprzedazyProduktu(wartoscDouble, i);
    } // ustawienie wartosci tablicy zysk sklepu //p

    this->getString();
    for (int i = 0; i < nowyProblem->getIloscDostawcow(); i++) {
        for (int j = 0; j < nowyProblem->getIloscFabryk(); ++j) {
            wartoscDouble = this->getDouble();
            wartoscDouble2 = this->getDouble();
            nowyProblem->setZakresDostawcaFabryka(std::move(std::pair<double, double>(wartoscDouble, wartoscDouble2)), i, j);
        }
    } //ustawienie macierzy min max dla dostawca-fabryka //xdminmax

    this->getString();
    for (int i = 0; i < nowyProblem->getIloscFabryk(); i++) {
        for (int j = 0; j < nowyProblem->getIloscDystrybucji(); ++j) {
            wartoscDouble = this->getDouble();
            wartoscDouble2 = this->getDouble();
            nowyProblem->setZakresFabrykaMagazyn(std::move(std::pair<double, double>(wartoscDouble, wartoscDouble2)), i, j);
        }
    } //ustawienie macierzy min max dla fabryka-magazyn //xfminmax

    this->getString();
    for (int i = 0; i < nowyProblem->getIloscDystrybucji(); i++) {
        for (int j = 0; j < nowyProblem->getIloscSklepow(); ++j) {
            wartoscDouble = this->getDouble();
            wartoscDouble2 = this->getDouble();
            nowyProblem->setZakresMagazynSklep(std::move(std::pair<double, double>(wartoscDouble, wartoscDouble2)), i, j);
        }
    } //ustawienie macierzy min max dla magazyn-sklep //xmminmax

}

std::string WczytanieProblemu::getString() {
    std::string newString;
    this->plikProblemu >> newString;

    return std::move(newString);
}

double WczytanieProblemu::getDouble() {
    double wartosc;
    this->plikProblemu >> wartosc;

    return wartosc;
}

int WczytanieProblemu::getInt() {
    int wartosc;
    this->plikProblemu >> wartosc;

    return wartosc;
}
