#include <iostream>
#include "CFileThrowEx.h"
#include "CFileErrCode.h"
#include "CFileLastError.h"

int main() {

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

    return 0;
}