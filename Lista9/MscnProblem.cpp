//
// Created by RC on 14.12.2019.
//

#include "MscnProblem.h"

int MscnProblem::getIloscDostawcow() const {
    return iloscDostawcow;
}

void MscnProblem::setIloscDostawcow(int newIloscDostawcow) {
    if (newIloscDostawcow > 0) {
        this->iloscDostawcow = newIloscDostawcow;

        this->set_koszt_uslug_dostawcy();
        this->set_dostawca_fabryka();
        this->set_wydajnosc_dostawcow();
        this->set_zakres_dostawca_fabryka();
    }

}

int MscnProblem::getIloscFabryk() const {
    return iloscFabryk;
}

void MscnProblem::setIloscFabryk(int newiloscFabryk) {
    if (newiloscFabryk > 0) {
        this->iloscFabryk = newiloscFabryk;

        this->set_koszt_korzystania_fabryki();
        this->set_wydajnosc_fabryk();

        this->set_dostawca_fabryka();
        this->set_fabryka_magazyn();

        this->set_zakres_fabryka_magazyn();
        this->set_zakres_dostawca_fabryka();
    }

}

int MscnProblem::getIloscDystrybucji() const {
    return iloscDystrybucji;
}

void MscnProblem::setIloscDystrybucji(int newIoscDystrybucji) {
    if (newIoscDystrybucji > 0) {
        this->iloscDystrybucji = newIoscDystrybucji;

        this->set_koszt_korzystania_centra();
        this->set_wydajnosc_centrow_dys();

        this->set_fabryka_magazyn();
        this->set_magazyn_sklep();

        this->set_zakres_fabryka_magazyn();
        this->set_zakres_magazyn_sklep();
    }

}

int MscnProblem::getIloscSklepow() const {
    return iloscSklepow;
}

void MscnProblem::setIloscSklepow(int newiloscSklepow) {
    if (newiloscSklepow > 0) {
        this->iloscSklepow = newiloscSklepow;

        this->set_potrzeby_sklepow();
        this->set_magazyn_sklep();
        this->set_zakres_magazyn_sklep();

    }
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
    if (wydajnosc_dostawcow != nullptr)
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

