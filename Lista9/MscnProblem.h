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
#define BRAK_TABLICY 3;

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
    int getDostraczenieDostawcaFabryka(int pozX, int pozY);
    void setDostraczenieDostawcaFabryka(int iloscDostarczana, int pozX, int pozY);
    int getDostarczenieFabrykaMagazyn(int pozX, int pozY);
    void setDostarczenieFabrykaMagazyn(int iloscDostarczana, int pozX, int pozY);
    int getDostarczenieMagazynSklep(int pozX, int pozY);
    void setDostarczenieMagazynSklep(int iloscDostarczana, int pozX, int pozY);
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

    double dGetQuality(double *pdSolution, int *kodBledu);
    bool bConstraintsSatisfied(double *pdSolution);

private:
    int kodBledu;

    int iloscDostawcow; //D
    int iloscFabryk; //F
    int iloscDystrybucji; //M
    int iloscSklepow;  //S

    int* wydajnosc_dostawcow; //sd
    int* wydajnosc_fabryk; //sf
    int* wydajnosc_centrow_dys; //sm
    int* potrzeby_sklepow; //ss

    int** dostawca_fabryka; //cd
    int** fabryka_magazyn; //cf
    int** magazyn_sklep; //cm

    int** dostraczenie_dostawca_fabryka; //xd
    int** dostarczenie_fabryka_magazyn; //xf
    int** dostarczenie_magazyn_sklep; //xm

    std::pair<int, int>** zakres_dostawca_fabryka; //xdminmax
    std::pair<int, int>** zakres_fabryka_magazyn; //xfminmax
    std::pair<int, int>** zakres_magazyn_sklep; //xmminmax

    int* koszt_uslug_dostawcy; //ud
    int* koszt_korzystania_fabryki; //uf
    int* koszt_korzystania_centra; //um

    void set_tab_dwu(int **tab, int rozX, int rozY);
    void set_tab_jedno(int *tab, int roz);

    int get_check(int** tab, int pozX, int pozY, int maxX, int maxY);
    int set_check(int** tab, int wartosc, int pozX, int pozY, int maxX, int maxY);

    bool sprawdzenieOgraniczen();
    bool czy_wszystko_istnieje();
    bool sprawdzenie_tabelki();

    void set_zakres_magazyn_sklep();
    void set_zakres_fabryka_magazyn();
    void set_zakres_dostawca_fabryka();
};


#endif //LISTA9_MSCNPROBLEM_H
