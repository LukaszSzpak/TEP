//
// Created by RC on 14.12.2019.
//

#include "MscnProblem.h"

int MscnProblem::getIloscDostawcow() const {
    return iloscDostawcow;
}

void MscnProblem::setIloscDostawcow(int newIloscDostawcow) {
    this->kodBledu = BRAK_BLEDU

    if (newIloscDostawcow > 0) {
        this->iloscDostawcow = newIloscDostawcow;

        this->set_koszt_uslug_dostawcy();
        this->set_dostawca_fabryka();
        this->set_wydajnosc_dostawcow();
        this->set_zakres_dostawca_fabryka();
    } else
        this->kodBledu = BLEDNA_ILOSC

}

int MscnProblem::getIloscFabryk() const {
    return iloscFabryk;
}

void MscnProblem::setIloscFabryk(int newiloscFabryk) {
    this->kodBledu = BRAK_BLEDU

    if (newiloscFabryk > 0) {
        this->iloscFabryk = newiloscFabryk;

        this->set_koszt_korzystania_fabryki();
        this->set_wydajnosc_fabryk();

        this->set_dostawca_fabryka();
        this->set_fabryka_magazyn();

        this->set_zakres_fabryka_magazyn();
        this->set_zakres_dostawca_fabryka();
    } else
        this->kodBledu = BLEDNA_ILOSC

}

int MscnProblem::getIloscDystrybucji() const {
    return iloscDystrybucji;
}

void MscnProblem::setIloscDystrybucji(int newIoscDystrybucji) {
    this->kodBledu = BRAK_BLEDU

    if (newIoscDystrybucji > 0) {
        this->iloscDystrybucji = newIoscDystrybucji;

        this->set_koszt_korzystania_centra();
        this->set_wydajnosc_centrow_dys();

        this->set_fabryka_magazyn();
        this->set_magazyn_sklep();

        this->set_zakres_fabryka_magazyn();
        this->set_zakres_magazyn_sklep();
    } else
        this->kodBledu = BLEDNA_ILOSC

}

int MscnProblem::getIloscSklepow() const {
    return iloscSklepow;
}

void MscnProblem::setIloscSklepow(int newiloscSklepow) {
    this->kodBledu = BRAK_BLEDU

    if (newiloscSklepow > 0) {
        this->iloscSklepow = newiloscSklepow;

        this->set_potrzeby_sklepow();
        this->set_magazyn_sklep();
        this->set_zakres_magazyn_sklep();

    } else
        this->kodBledu = BLEDNA_ILOSC
}

void MscnProblem::set_zakres_magazyn_sklep() {
    if(this->zakres_magazyn_sklep != nullptr)
        delete[](zakres_magazyn_sklep);

    this->zakres_magazyn_sklep = new std::pair<int, int>*[iloscDystrybucji];
    for (int k = 0; k < iloscDystrybucji; ++k) {
        zakres_magazyn_sklep[k] = new std::pair<int, int>[iloscSklepow];
    }
}

void MscnProblem::set_magazyn_sklep() {
    if (this->magazyn_sklep != nullptr)
        delete[](magazyn_sklep);

    this->magazyn_sklep = new int*[iloscDystrybucji];
    for (int i = 0; i < iloscDystrybucji; ++i) {
        this->magazyn_sklep[i] = new int[iloscSklepow];
    }
}

void MscnProblem::set_zakres_fabryka_magazyn() {
    if (this->zakres_fabryka_magazyn != nullptr)
        delete[](zakres_fabryka_magazyn);

    this->zakres_fabryka_magazyn = new std::pair<int, int>*[iloscFabryk];
    for (int j = 0; j < iloscFabryk; ++j) {
        zakres_fabryka_magazyn[j] = new std::pair<int, int>[iloscDystrybucji];
    }
}

void MscnProblem::set_fabryka_magazyn() {
    if(this->fabryka_magazyn != nullptr)
        delete[](fabryka_magazyn);

    this->fabryka_magazyn = new int*[iloscFabryk];
    for (int j = 0; j < iloscFabryk; ++j) {
        this->fabryka_magazyn[j] = new int[iloscDystrybucji];
    }
}

void MscnProblem::set_zakres_dostawca_fabryka() {
    if (this->zakres_dostawca_fabryka != nullptr)
        delete[](zakres_dostawca_fabryka);

    this->zakres_dostawca_fabryka = new std::pair<int, int>*[iloscDostawcow];
    for (int j = 0; j < iloscFabryk; ++j) {
        zakres_dostawca_fabryka[j] = new std::pair<int, int>[iloscFabryk];
    }
}

void MscnProblem::set_dostawca_fabryka() {
    if(this->dostawca_fabryka != nullptr)
        delete[](dostawca_fabryka);

    this->dostawca_fabryka = new int*[iloscDostawcow];
    for (int i = 0; i < iloscDostawcow; ++i) {
        this->dostawca_fabryka[i] = new int[iloscFabryk];
    }
}

void MscnProblem::set_wydajnosc_dostawcow() {
    if(this->wydajnosc_dostawcow != nullptr)
        delete this->wydajnosc_dostawcow;

    this->wydajnosc_dostawcow = new int[iloscDostawcow];
}

void MscnProblem::set_koszt_uslug_dostawcy() {
    if (this->koszt_uslug_dostawcy != nullptr)
        delete(koszt_uslug_dostawcy);

    this->koszt_uslug_dostawcy = new int[iloscDostawcow];
}

void MscnProblem::set_wydajnosc_fabryk() {
    if(this->wydajnosc_fabryk != nullptr)
        delete(wydajnosc_fabryk);

    this->wydajnosc_fabryk = new int[iloscFabryk];
}

void MscnProblem::set_koszt_korzystania_fabryki() {
    if(this->koszt_korzystania_fabryki != nullptr)
        delete(koszt_korzystania_fabryki);

    this->koszt_korzystania_fabryki = new int[iloscFabryk];
}

void MscnProblem::set_wydajnosc_centrow_dys() {
    if (this->wydajnosc_centrow_dys != nullptr)
        delete(wydajnosc_centrow_dys);

    this->wydajnosc_centrow_dys = new int[iloscDystrybucji];
}

void MscnProblem::set_koszt_korzystania_centra() {
    if (this->koszt_korzystania_centra != nullptr)
        delete(koszt_korzystania_centra);

    this->koszt_korzystania_centra = new int[iloscDystrybucji];
}

void MscnProblem::set_potrzeby_sklepow() {
    if(potrzeby_sklepow != nullptr)
        delete(potrzeby_sklepow);

    this->potrzeby_sklepow = new int[iloscSklepow];
}

int MscnProblem::getWydajnoscDostawcow(int pozycja)  {
    this->kodBledu = BRAK_BLEDU

    if (pozycja >= 0 && pozycja < this->iloscDostawcow)
        return this->wydajnosc_dostawcow[pozycja];

    this->kodBledu = BLEDNY_ZAKRES
    return -1;

}

void MscnProblem::setWydajnoscDostawcow(int wydajnoscDostawcow, int pozycja) {
    this->kodBledu = 0;

    if (pozycja >= 0 && pozycja < this->iloscDostawcow)
        this->wydajnosc_dostawcow[pozycja] = wydajnoscDostawcow;
    else
        this->kodBledu = BLEDNY_ZAKRES

}

int MscnProblem::getWydajnoscFabryk(int pozycja) {
    this->kodBledu = 0;

    if (pozycja >= 0 && pozycja < this->iloscFabryk)
        return this->wydajnosc_fabryk[pozycja];

    this->kodBledu = BLEDNY_ZAKRES
    return -1;
}

void MscnProblem::setWydajnoscFabryk(int wydajnoscFabryk, int pozycja) {
    this->kodBledu = BRAK_BLEDU

    if (pozycja >= 0 && pozycja < this->iloscFabryk)
        this->wydajnosc_fabryk[pozycja] = wydajnoscFabryk;
    else
        this->kodBledu = BLEDNY_ZAKRES

}

int MscnProblem::getWydajnoscCentrowDys(int pozycja) {
    this->kodBledu = BRAK_BLEDU

    if (pozycja >= 0 && pozycja < this->iloscDystrybucji)
        return this->wydajnosc_centrow_dys[pozycja];

    this->kodBledu = BLEDNY_ZAKRES
    return -1;
}

void MscnProblem::setWydajnoscCentrowDys(int wydajnoscCentrowDys, int pozycja) {
    this->kodBledu = BRAK_BLEDU

    if (pozycja >= 0 && pozycja < this->iloscDystrybucji)
        this->wydajnosc_centrow_dys[pozycja] = wydajnoscCentrowDys;
    else
        this->kodBledu = BLEDNY_ZAKRES

}

int MscnProblem::getPotrzebySklepow(int pozycja) {
    this->kodBledu = BRAK_BLEDU

    if (pozycja >= 0 && pozycja < this->iloscSklepow)
        return this->potrzeby_sklepow[pozycja];

    this->kodBledu = BLEDNY_ZAKRES
    return -1;
}

void MscnProblem::setPotrzebySklepow(int potrzebySklepow, int pozycja) {
    this->kodBledu = BRAK_BLEDU

    if (pozycja >= 0 && pozycja < this->iloscSklepow)
        this->potrzeby_sklepow[potrzebySklepow] = potrzebySklepow;
    else
        this->kodBledu = BLEDNY_ZAKRES
}

int MscnProblem::getDostawcaFabryka(int pozX, int pozY) {
    this->kodBledu = BRAK_BLEDU

    if (pozX >= 0 && pozX < this->iloscDostawcow && pozY >= 0 && pozY < this->iloscFabryk)
        return this->dostawca_fabryka[pozX][pozY];

    this->kodBledu = BLEDNY_ZAKRES
    return -1;
}

void MscnProblem::setDostawcaFabryka(int dostawcaFabryka, int pozX, int pozY) {
    this->kodBledu = BRAK_BLEDU

    if (pozX >= 0 && pozX < this->iloscDostawcow && pozY >= 0 && pozY < this->iloscFabryk)
        this->dostawca_fabryka[pozX][pozY] = dostawcaFabryka;
    else
        this->kodBledu = BLEDNY_ZAKRES
}

int MscnProblem::getFabrykaMagazyn(int pozX, int pozY) {
    this->kodBledu = BRAK_BLEDU

    if (pozX >= 0 && pozX < this->iloscFabryk && pozY >= 0 && pozY < this->iloscDystrybucji)
        return this->fabryka_magazyn[pozX][pozY];

    this->kodBledu = BLEDNY_ZAKRES
    return -1;
}

void MscnProblem::setFabrykaMagazyn(int fabrykaMagazyn, int pozX, int pozY) {
    this->kodBledu = BRAK_BLEDU

    if (pozX >= 0 && pozX < this->iloscFabryk && pozY >= 0 && pozY < this->iloscDystrybucji)
         this->fabryka_magazyn[pozX][pozY] = fabrykaMagazyn;
    else
        this->kodBledu = BLEDNY_ZAKRES
}

int MscnProblem::getMagazynSklep(int pozX, int pozY) {
    this->kodBledu = BRAK_BLEDU

    if (pozX >= 0 && pozX < this->iloscDystrybucji && pozY >= 0 && pozY < this->iloscSklepow)
        return this->magazyn_sklep[pozX][pozY];

    this->kodBledu = BLEDNY_ZAKRES
    return -1;
}

void MscnProblem::setMagazynSklep(int magazynSklep, int pozX, int pozY) {
    this->kodBledu = BRAK_BLEDU

    if (pozX >= 0 && pozX < this->iloscDystrybucji && pozY >= 0 && pozY < this->iloscSklepow)
        this->magazyn_sklep[pozX][pozY = magazynSklep];
    else
        this->kodBledu = BLEDNY_ZAKRES
}

std::pair<int, int> MscnProblem::getZakresDostawcaFabryka(int pozX, int pozY) {
    this->kodBledu = BRAK_BLEDU

    if (pozX >= 0 && pozX < this->iloscDostawcow && pozY >= 0 && pozY < this->iloscFabryk)
        return this->zakres_dostawca_fabryka[pozX][pozY];

    this->kodBledu = BLEDNY_ZAKRES
    return std::move(std::pair<int, int>(-1, -1));
}

void MscnProblem::setZakresDostawcaFabryka(std::pair<int, int> minmax, int pozX, int pozY) {
    this->kodBledu = BRAK_BLEDU

    if (pozX >= 0 && pozX < this->iloscDostawcow && pozY >= 0 && pozY < this->iloscFabryk)
        this->zakres_dostawca_fabryka[pozX][pozY] = minmax;
    else
        this->kodBledu = BLEDNY_ZAKRES
}

std::pair<int, int> MscnProblem::getZakresFabrykaMagazyn(int pozX, int pozY) {
    this->kodBledu = BRAK_BLEDU

    if (pozX >= 0 && pozX < this->iloscFabryk && pozY >= 0 && pozY < this->iloscDystrybucji)
        return this->zakres_fabryka_magazyn[pozX][pozY];

    this->kodBledu = BLEDNY_ZAKRES
    return std::move(std::pair<int, int>(-1, -1));
}

void MscnProblem::setZakresFabrykaMagazyn(std::pair<int, int> minmax, int pozX, int pozY) {
    this->kodBledu = BRAK_BLEDU

    if (pozX >= 0 && pozX < this->iloscFabryk && pozY >= 0 && pozY < this->iloscDystrybucji)
        this->zakres_fabryka_magazyn[pozX][pozY] = minmax;
    else
        this->kodBledu = BLEDNY_ZAKRES
}

std::pair<int, int> MscnProblem::getZakresMagazynSklep(int pozX, int pozY) {
    this->kodBledu = BRAK_BLEDU

    if (pozX >= 0 && pozX < this->iloscDystrybucji && pozY >= 0 && pozY < this->iloscSklepow)
        return this->zakres_magazyn_sklep[pozX][pozY];

    this->kodBledu = BLEDNY_ZAKRES
    return std::move(std::pair<int, int>(-1, -1));
}

void MscnProblem::setZakresMagazynSklep(std::pair<int, int> minmax, int pozX, int pozY) {
    this->kodBledu = BRAK_BLEDU

    if (pozX >= 0 && pozX < this->iloscDystrybucji && pozY >= 0 && pozY < this->iloscSklepow)
        this->zakres_magazyn_sklep[pozX][pozY] = minmax;
    else
        this->kodBledu = BLEDNY_ZAKRES
}

int MscnProblem::getKosztUslugDostawcy(int pozycja) {
    this->kodBledu = BRAK_BLEDU

    if (pozycja >= 0 && pozycja < this->iloscDostawcow)
        return this->koszt_uslug_dostawcy[pozycja];

    this->kodBledu = BLEDNY_ZAKRES
    return -1;
}

void MscnProblem::setKosztUslugDostawcy(int kosztUslugDostawcy, int pozycja) {
    this->kodBledu = BRAK_BLEDU

    if (pozycja >= 0 && pozycja < this->iloscDostawcow)
        this->koszt_uslug_dostawcy[pozycja] = kosztUslugDostawcy;
    else
        this->kodBledu = BLEDNY_ZAKRES
}

int MscnProblem::getKosztKorzystaniaFabryki(int pozycja) {
    this->kodBledu = BRAK_BLEDU

    if (pozycja >= 0 && pozycja < this->iloscFabryk)
        return this->koszt_korzystania_fabryki[pozycja];

    this->kodBledu = BLEDNY_ZAKRES
    return -1;
}

void MscnProblem::setKosztKorzystaniaFabryki(int kosztKorzystaniaFabryki, int pozycja) {
    this->kodBledu = BRAK_BLEDU

    if (pozycja >= 0 && pozycja < this->iloscFabryk)
        this->koszt_korzystania_fabryki[pozycja] = kosztKorzystaniaFabryki;
    else
        this->kodBledu = BLEDNY_ZAKRES
}

int MscnProblem::getKosztKorzystaniaCentra(int pozycja) {
    this->kodBledu = BRAK_BLEDU

    if (pozycja >= 0 && pozycja < this->iloscDystrybucji)
        return this->koszt_korzystania_centra[pozycja];

    this->kodBledu = BLEDNY_ZAKRES
    return -1;
}

void MscnProblem::setKosztKorzystaniaCentra(int kosztKorzystaniaCentra, int pozycja) {
    this->kodBledu = BRAK_BLEDU

    if (pozycja >= 0 && pozycja < this->iloscDystrybucji)
        this->koszt_korzystania_centra[pozycja] = kosztKorzystaniaCentra;
    else
        this->kodBledu = BLEDNY_ZAKRES
}

