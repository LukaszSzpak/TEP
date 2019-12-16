//
// Created by RC on 16.12.2019.
//

#ifndef LISTA9_WCZYTANIEPROBLEMU_H
#define LISTA9_WCZYTANIEPROBLEMU_H


#include <mbstring.h>
#include <string>
#include <fstream>
#include "MscnProblem.h"

class WczytanieProblemu {
public:
    WczytanieProblemu(std::string nazwaPliku);
    bool otworzPlik();
    void wczytajDane(MscnProblem *nowyProblem);

private:
    std::basic_ifstream<char> plikProblemu;
    std::string nazwaPliku;

};


#endif //LISTA9_WCZYTANIEPROBLEMU_H
