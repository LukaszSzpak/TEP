//
// Created by RC on 17.12.2019.
//

#ifndef LISTA9_WCZYTANIEROZWIAZANIA_H
#define LISTA9_WCZYTANIEROZWIAZANIA_H


#include <string>
#include <fstream>

class WczytanieRozwiazania {
public:
    WczytanieRozwiazania(std::string nazwaPliku);
    bool otworzPlik();
    double* wczytajDaneRozwiazania();

private:
    std::string nazwaPliku;
    std::basic_ifstream<char> plikRozwiazania;

    std::string getString();
    double getDouble();
    int getInt();
};


#endif //LISTA9_WCZYTANIEROZWIAZANIA_H
