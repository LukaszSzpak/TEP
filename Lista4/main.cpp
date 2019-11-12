#include <iostream>
#include "CFileThrowEx.h"
#include "CFileErrCode.h"
#include "CFileLastError.h"
#include "Zakres.h"

int main() {
    /*
    CFileLastError *cFileErr = new CFileLastError("plik1.txt");
    std::cout<<"Otwarcie pliku 1: "<<cFileErr->bGetLastError();
    cFileErr->vPrintLine("lubie placki 1");
    std::cout<<"\nWpisanie lini do pliku 1: "<<cFileErr->bGetLastError();
    cFileErr->vCloseFile("plik1.txt");
    std::cout<<"\nZamkniecie pliku 1: "<<cFileErr->bGetLastError();

    std::cout<<"\n\n";

    try {
        CFileThrowEx *cFileThr = new CFileThrowEx("plik2.txt");
        cFileThr->vPrintLine("lubie placki 2");
        cFileThr->vCloseFile("plik2.txt");
        std::cout<<"Plik 2 bez bledow";
    } catch (std::string s) {
        std::cout<<s<<"\n";
    }

    std::cout<<"\n\n";

    CFileErrCode *cFileCode = new CFileErrCode();

    std::cout<<"Otwarcie pliku 3: "<<cFileCode->vOpenFile("plik3.txt");
    std::cout<<"\nWpisanie lini: "<<cFileCode->vPrintLine("lubie placki 3");
    std::cout<<"\nZamkniecie pliku 3: "<<cFileCode->vCloseFile("plik3.txt");

     */
    std::cout<<"\n\nCzesc na zajeciach:\n";
    Zakres *zak = new Zakres((std::string)"223", 10, 300);
    std::cout<<"Wynik: "<<zak->getLiczba()<<"\nCZy udalo sie: "<<zak->getCzyUdane()<<"\n";

    Zakres *zak1 = new Zakres((std::string)"A23", 10, 300);
    std::cout<<"Wynik: "<<zak1->getLiczba()<<"\nCzy udalo sie: "<<zak1->getCzyUdane()<<"\n";

    Zakres *zak2 = new Zakres((std::string)"363", 10, 500);
    std::cout<<"Wynik: "<<zak2->getLiczba()<<"\nCzy udalo sie: "<<zak2->getCzyUdane()<<"\n";

    zak = zak2;
    std::cout<<"Przepisz: Wynik: "<<zak->getLiczba()<<"\nCzy udalo sie: "<<zak->getCzyUdane()<<"\n";

    zak->operator=("435");
    std::cout<<"Przepisz: Wynik: "<<zak->getLiczba()<<"\nCzy udalo sie: "<<zak->getCzyUdane()<<"\n";

    return 0;
}