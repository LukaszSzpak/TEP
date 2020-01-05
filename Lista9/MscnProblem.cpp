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

        this->set_tab_dwu(&this->dostawca_fabryka, this->iloscDostawcow, this->iloscFabryk);
        this->set_tab_dwu(&this->dostraczenie_dostawca_fabryka, this->iloscDostawcow, this->iloscFabryk);

        this->set_tab_jedno(&this->koszt_uslug_dostawcy, this->iloscDostawcow);
        this->set_tab_jedno(&this->wydajnosc_dostawcow, this->iloscDostawcow);

        this->set_zakres_dostawca_fabryka();

        this->set_tab_dwu(&this->dostraczenie_dostawca_fabryka, this->iloscDostawcow, this->iloscFabryk);

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

        this->set_tab_jedno(&this->koszt_korzystania_fabryki, this->iloscFabryk);
        this->set_tab_jedno(&this->wydajnosc_fabryk, this->iloscFabryk);

        this->set_tab_dwu(&this->dostawca_fabryka, this->iloscDostawcow, this->iloscFabryk);
        this->set_tab_dwu(&this->fabryka_magazyn, this->iloscFabryk, this->iloscDystrybucji);

        this->set_zakres_fabryka_magazyn();
        this->set_zakres_dostawca_fabryka();

        this->set_tab_dwu(&this->dostraczenie_dostawca_fabryka, this->iloscDostawcow, this->iloscFabryk);
        this->set_tab_dwu(&this->fabryka_magazyn, this->iloscFabryk, this->iloscDystrybucji);
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

        this->set_tab_jedno(&this->koszt_korzystania_centra, this->iloscDystrybucji);
        this->set_tab_jedno(&this->wydajnosc_centrow_dys, this->iloscDystrybucji);

        this->set_tab_dwu(&this->fabryka_magazyn, this->iloscFabryk, this->iloscDystrybucji);
        this->set_tab_dwu(&this->magazyn_sklep, this->iloscDystrybucji, this->iloscSklepow);

        this->set_zakres_fabryka_magazyn();
        this->set_zakres_magazyn_sklep();

        this->set_tab_dwu(&this->dostarczenie_fabryka_magazyn, this->iloscFabryk, this->iloscDystrybucji);
        this->set_tab_dwu(&this->dostarczenie_magazyn_sklep, this->iloscDystrybucji, this->iloscSklepow);
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

        this->set_tab_jedno(&this->potrzeby_sklepow, this->iloscSklepow);

        this->set_zakres_magazyn_sklep();

        this->set_tab_dwu(&this->magazyn_sklep, this->iloscDystrybucji, this->iloscSklepow);
        this->set_tab_dwu(&this->dostarczenie_magazyn_sklep, this->iloscDystrybucji, this->iloscSklepow);

        this->set_tab_jedno(&this->zysk_sprzedazy_produktu, this->iloscSklepow);

    } else
        this->kodBledu = BLEDNA_ILOSC
}

void MscnProblem::set_zakres_magazyn_sklep() {
    if(this->zakres_magazyn_sklep != nullptr)
        delete[](zakres_magazyn_sklep);

    this->zakres_magazyn_sklep = new std::pair<double, double>*[iloscDystrybucji];
    for (int k = 0; k < iloscDystrybucji; ++k) {
        zakres_magazyn_sklep[k] = new std::pair<double, double>[iloscSklepow];
    }
}

void MscnProblem::set_zakres_fabryka_magazyn() {
    if (this->zakres_fabryka_magazyn != nullptr)
        delete[](zakres_fabryka_magazyn);

    this->zakres_fabryka_magazyn = new std::pair<double, double>*[iloscFabryk];
    for (int j = 0; j < iloscFabryk; ++j) {
        zakres_fabryka_magazyn[j] = new std::pair<double, double>[iloscDystrybucji];
    }
}

void MscnProblem::set_zakres_dostawca_fabryka() {
    if (this->zakres_dostawca_fabryka != nullptr)
        delete[](zakres_dostawca_fabryka);

    this->zakres_dostawca_fabryka = new std::pair<double, double>*[iloscDostawcow];
    for (int j = 0; j < iloscDostawcow; ++j) {
        zakres_dostawca_fabryka[j] = new std::pair<double, double>[iloscFabryk];
    }
}

double MscnProblem::getWydajnoscDostawcow(int pozycja)  {
    return this->get_check(this->wydajnosc_dostawcow, pozycja, this->iloscDostawcow);
}

void MscnProblem::setWydajnoscDostawcow(double wydajnoscDostawcow, int pozycja) {
    this->set_check(this->wydajnosc_dostawcow, wydajnoscDostawcow, pozycja, this->iloscDostawcow);
}

double MscnProblem::getWydajnoscFabryk(int pozycja) {
    return this->get_check(this->wydajnosc_fabryk, pozycja, this->iloscFabryk);
}

void MscnProblem::setWydajnoscFabryk(double wydajnoscFabryk, int pozycja) {
    this->set_check(this->wydajnosc_fabryk, wydajnoscFabryk, pozycja, this->iloscFabryk);
}

double MscnProblem::getWydajnoscCentrowDys(int pozycja) {
    return this->get_check(this->wydajnosc_centrow_dys, pozycja, this->iloscDystrybucji);
}

void MscnProblem::setWydajnoscCentrowDys(double wydajnoscCentrowDys, int pozycja) {
    this->set_check(this->wydajnosc_centrow_dys, wydajnoscCentrowDys, pozycja, this->iloscDystrybucji);
}

double MscnProblem::getPotrzebySklepow(int pozycja) {
    return this->get_check(this->potrzeby_sklepow, pozycja, this->iloscSklepow);
}

void MscnProblem::setPotrzebySklepow(double potrzebySklepow, int pozycja) {
    this->set_check(this->potrzeby_sklepow, potrzebySklepow, pozycja, this->iloscSklepow);
}

double MscnProblem::getDostawcaFabryka(int pozX, int pozY) {
    return this->get_check(this->dostawca_fabryka, pozX, pozY, this->iloscDostawcow, this->iloscFabryk);
}

void MscnProblem::setDostawcaFabryka(double dostawcaFabryka, int pozX, int pozY) {
    this->set_check(this->dostawca_fabryka, dostawcaFabryka, pozX, pozY, this->iloscDostawcow, this->iloscFabryk);
}

double MscnProblem::getFabrykaMagazyn(int pozX, int pozY) {
    return this->get_check(this->fabryka_magazyn, pozX, pozY, this->iloscFabryk, this->iloscDystrybucji);
}

void MscnProblem::setFabrykaMagazyn(double fabrykaMagazyn, int pozX, int pozY) {
    this->set_check(this->fabryka_magazyn, fabrykaMagazyn, pozX, pozY, this->iloscFabryk, this->iloscDystrybucji);
}

double MscnProblem::getMagazynSklep(int pozX, int pozY) {
    return this->get_check(this->magazyn_sklep, pozX, pozY, this->iloscDystrybucji, this->iloscSklepow);
}

void MscnProblem::setMagazynSklep(double magazynSklep, int pozX, int pozY) {
    this->set_check(this->magazyn_sklep, magazynSklep, pozX, pozY, this->iloscDystrybucji, this->iloscSklepow);
}

std::pair<double, double> MscnProblem::getZakresDostawcaFabryka(int pozX, int pozY) {
    return this->get_check(this->zakres_dostawca_fabryka, pozX, pozY, this->iloscDostawcow, this->iloscFabryk);
}

void MscnProblem::setZakresDostawcaFabryka(std::pair<double, double> minmax, int pozX, int pozY) {
    this->set_check(this->zakres_dostawca_fabryka, minmax, pozX, pozY, this->iloscDostawcow, this->iloscFabryk);
}

std::pair<double, double> MscnProblem::getZakresFabrykaMagazyn(int pozX, int pozY) {
    return this->get_check(this->zakres_fabryka_magazyn, pozX, pozY, this->iloscFabryk, this->iloscDystrybucji);
}

void MscnProblem::setZakresFabrykaMagazyn(std::pair<double, double> minmax, int pozX, int pozY) {
    this->set_check(this->zakres_fabryka_magazyn, minmax, pozX, pozY, this->iloscFabryk, this->iloscDystrybucji);
}

std::pair<double, double> MscnProblem::getZakresMagazynSklep(int pozX, int pozY) {
    return this->get_check(this->zakres_magazyn_sklep, pozX, pozY, this->iloscDystrybucji, this->iloscSklepow);
}

void MscnProblem::setZakresMagazynSklep(std::pair<double, double> minmax, int pozX, int pozY) {
    this->set_check(this->zakres_magazyn_sklep, minmax, pozX, pozY, this->iloscDystrybucji, this->iloscSklepow);
}

double MscnProblem::getKosztUslugDostawcy(int pozycja) {
    return this->get_check(this->koszt_uslug_dostawcy, pozycja, this->iloscDostawcow);
}

void MscnProblem::setKosztUslugDostawcy(double kosztUslugDostawcy, int pozycja) {
    this->set_check(this->koszt_uslug_dostawcy, kosztUslugDostawcy, pozycja, this->iloscDostawcow);
}

double MscnProblem::getKosztKorzystaniaFabryki(int pozycja) {
    return this->get_check(this->koszt_korzystania_fabryki, pozycja, this->iloscFabryk);
}

void MscnProblem::setKosztKorzystaniaFabryki(double kosztKorzystaniaFabryki, int pozycja) {
    this->set_check(this->koszt_korzystania_fabryki, kosztKorzystaniaFabryki, pozycja, this->iloscFabryk);
}

double MscnProblem::getKosztKorzystaniaCentra(int pozycja) {
    return this->get_check(this->koszt_korzystania_centra, pozycja, this->iloscDystrybucji);
}

void MscnProblem::setKosztKorzystaniaCentra(double kosztKorzystaniaCentra, int pozycja) {
    this->set_check(this->koszt_korzystania_centra, kosztKorzystaniaCentra, pozycja, this->iloscDystrybucji);
}

double MscnProblem::getDostraczenieDostawcaFabryka(int pozX, int pozY) {
    return this->get_check(this->dostraczenie_dostawca_fabryka, pozX, pozY, this->iloscDostawcow, this->iloscFabryk);
}

void MscnProblem::setDostraczenieDostawcaFabryka(double iloscDostarczana, int pozX, int pozY) {
    set_check(this->dostraczenie_dostawca_fabryka, iloscDostarczana, pozX, pozY, this->iloscDostawcow, this->iloscFabryk);
}

double MscnProblem::getDostarczenieFabrykaMagazyn(int pozX, int pozY) {
    return this->get_check(this->dostarczenie_fabryka_magazyn, pozX, pozY, this->iloscFabryk, this->iloscDystrybucji);
}

void MscnProblem::setDostarczenieFabrykaMagazyn(double iloscDostarczana, int pozX, int pozY) {
    this->set_check(this->dostarczenie_fabryka_magazyn, iloscDostarczana, pozX, pozY, this->iloscFabryk, this->iloscDystrybucji);
}

double MscnProblem::getDostarczenieMagazynSklep(int pozX, int pozY) {
    return this->get_check(this->dostarczenie_magazyn_sklep, pozX, pozY, this->iloscDystrybucji, this->iloscSklepow);
}

void MscnProblem::setDostarczenieMagazynSklep(double iloscDostarczana, int pozX, int pozY) {
    this->set_check(this->dostarczenie_magazyn_sklep, iloscDostarczana, pozX, pozY, this->iloscDystrybucji, this->iloscSklepow);
}

bool MscnProblem::czy_wszystko_istnieje() {
    return !(this->dostarczenie_magazyn_sklep == nullptr || this->dostarczenie_fabryka_magazyn == nullptr
             || this->dostraczenie_dostawca_fabryka == nullptr || this->wydajnosc_centrow_dys == nullptr
             || this->wydajnosc_fabryk == nullptr || this->wydajnosc_dostawcow == nullptr
             || this->potrzeby_sklepow == nullptr || this->dostawca_fabryka == nullptr
             || this->fabryka_magazyn == nullptr || this->magazyn_sklep == nullptr
             || this->zakres_magazyn_sklep == nullptr || this->zakres_dostawca_fabryka == nullptr
             || this->zakres_fabryka_magazyn == nullptr || this->koszt_korzystania_centra == nullptr
             || this->koszt_korzystania_fabryki == nullptr || this->koszt_uslug_dostawcy == nullptr);

}

bool MscnProblem::sprawdzenieOgraniczen() {
    for (int i = 0; i < this->iloscDostawcow; ++i)
        for (int j = 0; j < this->iloscFabryk; ++j)
            if (this->zakres_dostawca_fabryka[i][j].first > this->dostraczenie_dostawca_fabryka[i][j] ||
                    this->zakres_dostawca_fabryka[i][j].second < this->dostraczenie_dostawca_fabryka[i][j])
                return false;

    for (int i = 0; i < this->iloscFabryk; i++)
        for (int j = 0; j < this->iloscDystrybucji; j++)
            if (this->zakres_fabryka_magazyn[i][j].first > this->dostarczenie_fabryka_magazyn[i][j] ||
                    this->zakres_fabryka_magazyn[i][j].second < this->dostarczenie_fabryka_magazyn[i][j])
                return false;

    for (int i = 0; i < this->iloscDystrybucji; i++)
        for (int j = 0; j < this->iloscSklepow; j++)
            if (this->zakres_magazyn_sklep[i][j].first > this->dostarczenie_magazyn_sklep[i][j] ||
                    this->zakres_magazyn_sklep[i][j].second < this->dostarczenie_magazyn_sklep[i][j])
                return false;

    return true;
}

bool MscnProblem::sprawdzenie_tabelki() {

    for (int i = 0; i < this->iloscDostawcow; i++) {
        double suma = 0;
        for (int j = 0; j < this->iloscFabryk; j++) {
            suma += this->dostraczenie_dostawca_fabryka[i][j]; //suma zamówien u danego dostawcy
        }

        if (suma > this->wydajnosc_dostawcow[i]) //czy zamowiono wiecej niz dostawca jest w stanie wyprodukowac
            return false;
    } // czy nie zamawia sie wiecej u dostawcy niz produkuja

    for (int i = 0; i < this->iloscFabryk; i++) {
        double suma = 0;
        for (int j = 0; j < this->iloscDystrybucji; j++) {
            suma += this->dostarczenie_fabryka_magazyn[i][j]; //suma zamówien w jednej fabryce
        }

        if (suma > this->wydajnosc_fabryk[i]) //czy zamowieono wiecej niz fabryka produkuje
            return false;
    } //czy nie zamawia wiecej niz fabryki produkuja

    for (int i = 0; i < this->iloscDystrybucji; i++) {
        double suma = 0;
        for (int j = 0; j < this->iloscSklepow; j++) {
            suma += this->dostarczenie_magazyn_sklep[i][j]; //suma zamowien w jednym magazynie
        }

        if (suma > this->wydajnosc_centrow_dys[i]) //czy zamowieono wiecej niz magazyn ma
            return false;
    } //czy nie zamawiaja wiecej niz magazyny maja

    for (int i = 0; i < this->iloscSklepow; i++) {
        double suma = 0;
        for (int j = 0; j < this->iloscDystrybucji; j++) {
            suma += this->dostarczenie_magazyn_sklep[j][i]; //suma zamowien danego sklepu
        }

        if (suma > this->potrzeby_sklepow[i]) //czy sklep zamowil wiecej niz potrzebuje
            return false;
    } //czy sklepu nie zamawiaja wiecej niz potrzebuja

    for (int i = 0; i < iloscFabryk; i++) {
        double sumaWejsc = 0.0;
        double sumaWyjsc = 0.0;

        for (int j = 0; j < this->iloscDostawcow; j++)
            sumaWejsc += this->dostraczenie_dostawca_fabryka[j][i]; //suma wejsc towaru do danej fabryki
        for (int j = 0; j < this->iloscDystrybucji; j++)
            sumaWyjsc += this->dostarczenie_fabryka_magazyn[i][j]; //suma wyjsc produktow z danej fabryki

        if (sumaWejsc < sumaWyjsc) //czy wychodzi wiecej niz wchodzi
            return false;
    }

    for (int i = 0; i < this->iloscDystrybucji; i++) {
        double sumaWejsc = 0.0;
        double sumaWyjsc = 0.0;

        for (int j = 0; j < this->iloscFabryk; j++)
            sumaWejsc += this->dostarczenie_fabryka_magazyn[j][i]; //suma wejsc towarow do magazynu
        for (int j = 0; j < this->iloscSklepow; j++)
            sumaWyjsc += this->dostarczenie_magazyn_sklep[i][j]; //syma wyjsc towarow z magazynu

        if (sumaWejsc < sumaWyjsc) //czy wychodzi wiecej niz wchodzi
            return false;
    }

    return true;
}

bool MscnProblem::bConstraintsSatisfied(double *pdSolution, int *kodBleduWartosc) {
    *kodBleduWartosc = BRAK_BLEDU
    this->pdSolutionDoMacierzy(pdSolution);

    if (!this->czy_wszystko_istnieje()) {
        *kodBleduWartosc = BRAK_TABLICY
        return 0;
    }

    if (!this->sprawdzenieOgraniczen()) {
        *kodBleduWartosc = BLAD_MINMAX
        return false;
    }

    if (!this->sprawdzenie_tabelki()) {
        *kodBleduWartosc = BLAD_ILOSC_TOWAROW
        return false;
    }

    return true;
}

double MscnProblem::dGetQuality(double *pdSolution, int *kodBledu) {
    *kodBledu = BRAK_BLEDU
    this->pdSolutionDoMacierzy(pdSolution);

    if (!this->czy_wszystko_istnieje()) {
        *kodBledu = BRAK_TABLICY
        return 0;
    }

    return this->policzZysk();
}

double MscnProblem::policzZysk() {
    return this->policzP() - (this->policzKT() + this->policzKU());
}

void MscnProblem::pdSolutionDoMacierzy(double *pdSolution) {
    if (pdSolution == nullptr) {
        this->kodBledu = BRAK_TABLICY;
        return;
    }

    int rozmiar = (this->iloscSklepow * this->iloscDystrybucji)  + (this->iloscDystrybucji * this->iloscFabryk)
            + (this->iloscFabryk * this->iloscDostawcow);
    for (int l = 0; l < rozmiar; ++l)
        if (pdSolution[l] < 0) {
            this->kodBledu = BLEDNA_WARTOSC
            return;
        }

    int i = 0;
    for (int j = 0; j < this->iloscDostawcow; j++)
        for (int k = 0; k < this->iloscFabryk; k++, i++)
            this->dostraczenie_dostawca_fabryka[j][k] = pdSolution[i];

    for (int j = 0; j < this->iloscFabryk; j++)
        for (int k = 0; k < this->iloscDystrybucji; k++, i++)
            this->dostarczenie_fabryka_magazyn[j][k] = pdSolution[i];

    for (int j = 0; j < this->iloscDystrybucji; j++)
        for (int k = 0; k < this->iloscSklepow; k++, i++)
            this->dostarczenie_magazyn_sklep[j][k] = pdSolution[i];
}

double MscnProblem::policzP() {
    double p = 0;

    for (int i = 0; i < this->iloscSklepow; i++) {
        double xm = 0;

        for (int j = 0; j < this->iloscDystrybucji; j++)
            xm += this->dostarczenie_magazyn_sklep[j][i];

        xm *= this->zysk_sprzedazy_produktu[i];
        p += xm;
    }

    return p;
}

void MscnProblem::setZyskSprzedazyProduktu(double zysk, int pozycja) {
    this->set_check(this->zysk_sprzedazy_produktu, zysk, pozycja, this->iloscSklepow);
}

double MscnProblem::policzKT() {
    double KT = 0;

    for (int i = 0; i < this->iloscDostawcow; i++) {
        for (int j = 0; j < this->iloscFabryk; j++) {
            KT += (this->dostawca_fabryka[i][j] * this->dostraczenie_dostawca_fabryka[i][j]);
        }
    }

    for (int i = 0; i < this->iloscFabryk; i++) {
        for (int j = 0; j < this->iloscDystrybucji; j++) {
            KT += (this->fabryka_magazyn[i][j] * this->dostarczenie_fabryka_magazyn[i][j]);
        }
    }

    for (int i = 0; i < this->iloscDystrybucji; i++) {
        for (int j = 0; j < this->iloscSklepow; j++) {
            KT += (this->magazyn_sklep[i][j] * this->dostarczenie_magazyn_sklep[i][j]);
        }
    }

    return KT;
}

double MscnProblem::policzKU() {
    double KU = 0;
    bool czyDalej = true;

    for (int i = 0; i < this->iloscDostawcow; i++) {
        czyDalej = true;
        for (int j = 0; j < this->iloscFabryk && czyDalej; j++) {
            if (this->dostraczenie_dostawca_fabryka[i][j] > 0) {
                KU += this->koszt_uslug_dostawcy[i];
                czyDalej = false;
            }

        }
    }

    for (int i = 0; i < this->iloscFabryk; i++) {
        czyDalej = true;
        for (int j = 0; j < this->iloscDystrybucji && czyDalej; j++) {
            if (this->dostarczenie_fabryka_magazyn[i][j] > 0) {
                KU += this->koszt_korzystania_fabryki[i];
                czyDalej = false;
            }


        }
    }

    for (int i = 0; i < this->iloscDystrybucji; i++) {
        czyDalej = true;
        for (int j = 0; j < this->iloscSklepow && czyDalej; j++) {
            if (this->dostarczenie_magazyn_sklep[i][j] > 0) {
                KU += this->koszt_korzystania_centra[i];
                czyDalej = false;
            }

        }
    }

    return KU;
}

void MscnProblem::utworzTabliceIMacierze() {
    this->set_tab_dwu(&this->dostawca_fabryka, this->iloscDostawcow, this->iloscFabryk);
    this->set_tab_dwu(&this->fabryka_magazyn, this->iloscFabryk, this->iloscDystrybucji);
    this->set_tab_dwu(&this->magazyn_sklep, this->iloscDystrybucji, this->iloscSklepow);

    this->set_tab_dwu(&this->dostraczenie_dostawca_fabryka, this->iloscDostawcow, this->iloscFabryk);
    this->set_tab_dwu(&this->dostarczenie_fabryka_magazyn, this->iloscFabryk, this->iloscDystrybucji);
    this->set_tab_dwu(&this->dostarczenie_magazyn_sklep, this->iloscDystrybucji, this->iloscSklepow);

    this->set_tab_jedno(&this->koszt_uslug_dostawcy, this->iloscDostawcow);
    this->set_tab_jedno(&this->koszt_korzystania_fabryki, this->iloscFabryk);
    this->set_tab_jedno(&this->koszt_korzystania_centra, this->iloscDystrybucji);

    this->set_tab_jedno(&this->wydajnosc_dostawcow, this->iloscDostawcow);
    this->set_tab_jedno(&this->wydajnosc_fabryk, this->iloscFabryk);
    this->set_tab_jedno(&this->wydajnosc_centrow_dys, this->iloscDystrybucji);
    this->set_tab_jedno(&this->potrzeby_sklepow, this->iloscSklepow);

    this->set_zakres_dostawca_fabryka();
    this->set_zakres_fabryka_magazyn();
    this->set_zakres_magazyn_sklep();

    this->set_tab_jedno(&this->zysk_sprzedazy_produktu, this->iloscSklepow);
}

void MscnProblem::set_tab_dwu(double **(*tab), int rozX, int rozY) {
    if ((*tab) != nullptr)
        delete[](*tab);

    (*tab) = new double*[rozX];
    for (int i = 0; i < rozX; ++i) {
        (*tab)[i] = new double[rozY];
    }
}

void MscnProblem::set_tab_jedno(double **tab, int roz) {
    if ((*tab) != nullptr)
        delete(*tab);

    (*tab) = new double[roz];
}

double MscnProblem::get_check(double **tab, int pozX, int pozY, int maxX, int maxY) {
    this->kodBledu = BRAK_BLEDU

    if (pozX >= 0 && pozX < maxX && pozY >= 0 && pozY < maxY)
        return tab[pozX][pozY];

    this->kodBledu = BLEDNY_ZAKRES
    return -1;
}

std::pair<double, double> MscnProblem::get_check(std::pair<double, double> **tab, int pozX, int pozY, int maxX, int maxY) {
    this->kodBledu = BRAK_BLEDU

    if (pozX >= 0 && pozX < maxX && pozY >= 0 && pozY < maxY)
        return tab[pozX][pozY];

    this->kodBledu = BLEDNY_ZAKRES
    return std::move(std::pair<double, double>(-1, -1));
}

void MscnProblem::set_check(double **tab, double wartosc, int pozX, int pozY, int maxX, int maxY) {
    this->kodBledu = BRAK_BLEDU

    if (pozX >= 0 && pozX < maxX && pozY >= 0 && pozY < maxY)
        tab[pozX][pozY] = wartosc;
    else
        this->kodBledu = BLEDNY_ZAKRES
}

void MscnProblem::set_check(std::pair<double, double> **tab, std::pair<double, double>wartosc, int pozX, int pozY, int maxX, int maxY) {
    this->kodBledu = BRAK_BLEDU

    if (pozX >= 0 && pozX < maxX && pozY >= 0 && pozY < maxY)
        tab[pozX][pozY] = wartosc;
    else
        this->kodBledu = BLEDNY_ZAKRES
}

double MscnProblem::get_check(double *tab, int pozycja, int maxPozycja) {
    this->kodBledu = BRAK_BLEDU

    if (pozycja >= 0 && pozycja < maxPozycja)
        return tab[pozycja];

    this->kodBledu = BLEDNY_ZAKRES
    return -1;
}

void MscnProblem::set_check(double *tab, double wartosc, int pozycja, int maxPozycja) {
    this->kodBledu = BRAK_BLEDU

    if (pozycja >= 0 && pozycja < maxPozycja)
        tab[pozycja] = wartosc;
    else
        this->kodBledu = BLEDNY_ZAKRES
}
