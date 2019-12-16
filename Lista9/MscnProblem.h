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
#define BLAD_ILOSC_TOWAROW 4;
#define BLAD_MINMAX 5;
#define BLEDNA_WARTOSC 6;

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
    double getWydajnoscDostawcow(int pozycja);
    void setWydajnoscDostawcow(double wydajnoscDostawcow, int pozycja);
    double getWydajnoscFabryk(int pozycja);
    void setWydajnoscFabryk(double wydajnoscFabryk, int pozycja);
    double getWydajnoscCentrowDys(int pozycja);
    void setWydajnoscCentrowDys(double wydajnoscCentrowDys, int pozycja);
    double getPotrzebySklepow(int pozycja);
    void setPotrzebySklepow(double potrzebySklepow, int pozycja);
    double getDostawcaFabryka(int pozX, int pozY);
    void setDostawcaFabryka(double dostawcaFabryka, int pozX, int pozY);
    double getFabrykaMagazyn(int pozX, int pozY);
    void setFabrykaMagazyn(double fabrykaMagazyn, int pozX, int pozY);
    double getDostraczenieDostawcaFabryka(int pozX, int pozY);
    void setDostraczenieDostawcaFabryka(double iloscDostarczana, int pozX, int pozY);
    double getDostarczenieFabrykaMagazyn(int pozX, int pozY);
    void setDostarczenieFabrykaMagazyn(double iloscDostarczana, int pozX, int pozY);
    double getDostarczenieMagazynSklep(int pozX, int pozY);
    void setDostarczenieMagazynSklep(double iloscDostarczana, int pozX, int pozY);
    double getMagazynSklep(int pozX, int pozY);
    void setMagazynSklep(double magazynSklep, int pozX, int pozY);
    std::pair<double, double> getZakresDostawcaFabryka(int pozX, int pozY);
    void setZakresDostawcaFabryka(std::pair<double, double> minmax, int pozX, int pozY);
    std::pair<double, double> getZakresFabrykaMagazyn(int pozX, int pozY);
    void setZakresFabrykaMagazyn(std::pair<double, double> minmax, int pozX, int pozY);
    std::pair<double, double> getZakresMagazynSklep(int pozX, int pozY);
    void setZakresMagazynSklep(std::pair<double, double> minmax, int pozX, int pozY);
    double getKosztUslugDostawcy(int pozycja);
    void setKosztUslugDostawcy(double kosztUslugDostawcy, int pozycja);
    double getKosztKorzystaniaFabryki(int pozycja);
    void setKosztKorzystaniaFabryki(double kosztKorzystaniaFabryki, int pozycja);
    double getKosztKorzystaniaCentra(int pozycja);
    void setKosztKorzystaniaCentra(double kosztKorzystaniaCentra, int pozycja);
    void setZyskSprzedazyProduktu(double zysk, int pozycja);
    int getKodBledu() {return kodBledu;};

    double dGetQuality(double *pdSolution, int *kodBledu);
    bool bConstraintsSatisfied(double *pdSolution, int *kodBledu);

private:
    int kodBledu;

    int iloscDostawcow; //D
    int iloscFabryk; //F
    int iloscDystrybucji; //M
    int iloscSklepow;  //S

    double* wydajnosc_dostawcow; //sd
    double* wydajnosc_fabryk; //sf
    double* wydajnosc_centrow_dys; //sm
    double* potrzeby_sklepow; //ss

    double** dostawca_fabryka; //cd
    double** fabryka_magazyn; //cf
    double** magazyn_sklep; //cm

    double** dostraczenie_dostawca_fabryka; //xd
    double** dostarczenie_fabryka_magazyn; //xf
    double** dostarczenie_magazyn_sklep; //xm

    std::pair<double, double>** zakres_dostawca_fabryka; //xdminmax
    std::pair<double, double>** zakres_fabryka_magazyn; //xfminmax
    std::pair<double, double>** zakres_magazyn_sklep; //xmminmax

    double* koszt_uslug_dostawcy; //ud
    double* koszt_korzystania_fabryki; //uf
    double* koszt_korzystania_centra; //um
    double* zysk_sprzedazy_produktu; //p

    void set_tab_dwu(double **tab, int rozX, int rozY);
    void set_tab_jedno(double *tab, int roz);

    double get_check(double** tab, int pozX, int pozY, int maxX, int maxY);
    void set_check(double** tab, double wartosc, int pozX, int pozY, int maxX, int maxY);
    void set_check(double* tab, double wartosc, int pozycja, int maxPozycja);

    bool sprawdzenieOgraniczen();
    bool czy_wszystko_istnieje();
    bool sprawdzenie_tabelki();

    void set_zakres_magazyn_sklep();
    void set_zakres_fabryka_magazyn();
    void set_zakres_dostawca_fabryka();

    double policzKT();
    double policzKU();
    double policzP();

    double policzZysk();
    void pdSolutionDoMacierzy(double *pdSolution);
};


#endif //LISTA9_MSCNPROBLEM_H
