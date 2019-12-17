#include <iostream>
#include "MscnProblem.h"
#include "WczytanieProblemu.h"
#include "WczytanieRozwiazania.h"
#include "ZapisRozwiazania.h"

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
    std::cout << "\nCzy spelnia kryteria: " << nowyProblem->bConstraintsSatisfied(pdSolution, kodBledu);
    std::cout << "\nKod bledu: " << *kodBledu;

    std::cout << "\nWartosc zysku: " << nowyProblem->dGetQuality(pdSolution, kodBledu);

    std::cout << "\nOtwarcie pliku do zapisu: " << zapisRozwiazania->otworzPlik();
    zapisRozwiazania->zapiszRozwiazanie(nowyProblem);

}