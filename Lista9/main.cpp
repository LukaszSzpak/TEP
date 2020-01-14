#include <iostream>
#include "MscnProblem.h"
#include "PlikiOperacje/WczytanieProblemu.h"
#include "PlikiOperacje/WczytanieRozwiazania.h"
#include "PlikiOperacje/ZapisRozwiazania.h"
#include "Losowe/BestRandSol.h"
#include "Losowe/DE.h"

int main() {

    auto *nowyProblem = new MscnProblem();
    auto *wczytanieProblemu = new WczytanieProblemu("problem.txt");
    auto *wczytanieRozwiazania = new WczytanieRozwiazania("rozwiazanie.txt");
    auto *zapisRozwiazania = new ZapisRozwiazania("rozwiazanieNowe.txt");

    std::cout << "Czy udalo sie otworzyc plik problemu: " << wczytanieProblemu->otworzPlik();
    wczytanieProblemu->wczytajDane(nowyProblem);

    std::cout << "\nCzy udalo sie otworzyc plik rozwiazania: " << wczytanieRozwiazania->otworzPlik();
    auto *pdSolution = wczytanieRozwiazania->wczytajDaneRozwiazania();

    int *kodBledu = new int;
    /*
    std::cout << "\nCzy spelnia kryteria: " << nowyProblem->bConstraintsSatisfied(pdSolution, kodBledu);
    std::cout << "\nKod bledu: " << *kodBledu;

    std::cout << "\nWartosc zysku: " << nowyProblem->dGetQuality(pdSolution, kodBledu);

    std::cout << "\nOtwarcie pliku do zapisu: " << zapisRozwiazania->otworzPlik();
    zapisRozwiazania->zapiszRozwiazanie(nowyProblem);

    MyRandom myRand;
    for (int i = 0; i < 10; i++) {
        std::cout << "\nLosowy int z przedzialu <-100, 100>: "<<myRand.getInt(-100, 100);
        std::cout << "\nLosowy double z przedzialu <-100, 100>: "<<myRand.getDouble(-100.00, 100.00);
    }
*/
    double zyski[] = {50.2, 15.6, 90.8, 20.9};
    /*
    BestRandSol *bestRand = new BestRandSol(10000, pdSolution);
    bestRand->ustawInstancje(1, 2, 1, 4, zyski);
    auto *najlepszeRoz = bestRand->getBestSolution();
    */

    auto *DEBest = new DE();
    DEBest->ustawInstancje(1, 2, 1, 4, zyski, pdSolution);
    //DEBest->znajdzNajlepszeRozwiazanie();
    DEBest->najlepszeRozwiazanieSrednia(100, 5);
    auto najlepszeRoz = DEBest->getNajlepszyProblem();

    if (najlepszeRoz == nullptr) {
        std::cout << "\nBRAK ROZWIAZANIA !";
    } else {
        std::cout << "\nWynik najlepszego rozwiazania: " << najlepszeRoz->dGetQuality(pdSolution, kodBledu);
        //najlepszeRoz->printParametryPomiaru();
    }

}