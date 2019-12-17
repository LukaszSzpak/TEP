//
// Created by RC on 17.12.2019.
//

#ifndef LISTA9_ZAPISROZWIAZANIA_H
#define LISTA9_ZAPISROZWIAZANIA_H


#include <fstream>
#include "MscnProblem.h"

class ZapisRozwiazania {
public:
    ZapisRozwiazania(std::string nazwaPliku);
    bool otworzPlik();
    void zapiszRozwiazanie(MscnProblem *problemDoZapisu);

private:
    std::string nazwaPliku;
    std::ofstream plikRozwiazania;

    void saveString(std::string wartosc);
    void saveDouble(double wartosc);
    void saveInt(double wartosc);

};


#endif //LISTA9_ZAPISROZWIAZANIA_H
