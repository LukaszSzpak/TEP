//
// Created by RC on 14.12.2019.
//

#ifndef LISTA9_MSCNPROBLEM_H
#define LISTA9_MSCNPROBLEM_H


#include <utility>
#include <iostream>

#define BRAK_BLEDU 0;
#define BLEDNY_ZAKRES 1;
#define BLEDNA_ILOSC 2;

class MscnProblem {

public:
    int getIloscDostawcow() const;
    void setIloscDostawcow(int newIloscDostawcow);
    int getIloscFabryk() const;
    void setIloscFabryk(int newiloscFabryk);
    int getIloscDystrybucji() const;
    void setIloscDystrybucji(int newIoscDystrybucji);
    int getIloscSklepow() const;
    void setIloscSklepow(int iloscSklepow);
    int getWydajnoscDostawcow(int pozycja);
    void setWydajnoscDostawcow(int wydajnoscDostawcow, int pozycja);
    int getWydajnoscFabryk(int pozycja);
    void setWydajnoscFabryk(int wydajnoscFabryk, int pozycja);
    int getWydajnoscCentrowDys(int pozycja);
    void setWydajnoscCentrowDys(int wydajnoscCentrowDys, int pozycja);
    int getPotrzebySklepow(int pozycja);
    void setPotrzebySklepow(int potrzebySklepow, int pozycja);
    int getDostawcaFabryka(int pozX, int pozY);
    void setDostawcaFabryka(int dostawcaFabryka, int pozX, int pozY);
    int getFabrykaMagazyn(int pozX, int pozY);
    void setFabrykaMagazyn(int fabrykaMagazyn, int pozX, int pozY);
    int getMagazynSklep(int pozX, int pozY);
    void setMagazynSklep(int magazynSklep, int pozX, int pozY);
    std::pair<int, int> getZakresDostawcaFabryka(int pozX, int pozY);
    void setZakresDostawcaFabryka(std::pair<int, int> minmax, int pozX, int pozY);
    std::pair<int, int> getZakresFabrykaMagazyn(int pozX, int pozY);
    void setZakresFabrykaMagazyn(std::pair<int, int> minmax, int pozX, int pozY);
    std::pair<int, int> getZakresMagazynSklep(int pozX, int pozY);
    void setZakresMagazynSklep(std::pair<int, int> minmax, int pozX, int pozY);
    int getKosztUslugDostawcy(int pozycja);
    void setKosztUslugDostawcy(int kosztUslugDostawcy, int pozycja);
    int getKosztKorzystaniaFabryki(int pozycja);
    void setKosztKorzystaniaFabryki(int kosztKorzystaniaFabryki, int pozycja);
    int getKosztKorzystaniaCentra(int pozycja);
    void setKosztKorzystaniaCentra(int kosztKorzystaniaCentra, int pozycja);
    int getKodBledu() {return kodBledu;};

private:
    int kodBledu;

    int iloscDostawcow;
    int iloscFabryk;
    int iloscDystrybucji;
    int iloscSklepow;

    int* wydajnosc_dostawcow;
    int* wydajnosc_fabryk;
    int* wydajnosc_centrow_dys;
    int* potrzeby_sklepow;

    int** dostawca_fabryka;
    int** fabryka_magazyn;
    int** magazyn_sklep;

    std::pair<int, int>** zakres_dostawca_fabryka;
    std::pair<int, int>** zakres_fabryka_magazyn;
    std::pair<int, int>** zakres_magazyn_sklep;

    int* koszt_uslug_dostawcy;
    int* koszt_korzystania_fabryki;
    int* koszt_korzystania_centra;

    void set_zakres_magazyn_sklep();
    void set_zakres_fabryka_magazyn();
    void set_zakres_dostawca_fabryka();

    void set_magazyn_sklep();
    void set_fabryka_magazyn();
    void set_dostawca_fabryka();

    void set_wydajnosc_dostawcow();
    void set_wydajnosc_fabryk();
    void set_wydajnosc_centrow_dys();
    void set_potrzeby_sklepow();

    void set_koszt_korzystania_centra();
    void set_koszt_uslug_dostawcy();
    void set_koszt_korzystania_fabryki();
};


#endif //LISTA9_MSCNPROBLEM_H
