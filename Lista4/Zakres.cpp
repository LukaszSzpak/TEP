//
// Created by RC on 12.11.2019.
//

#include "Zakres.h"

Zakres::Zakres(std::string liczbaS, int min, int max) {
    this->min = min;
    this->max = max;

    utworzLiczbe(liczbaS);
}

Zakres::Zakres(char *liczbaCh, int min, int max) {
    this->min = min;
    this->max = max;

    utworzLiczbe(this->charToString(liczbaCh));
}

bool Zakres::stringToInt(std::string testObiekt) {
    int liczbaKoncowa = 0;

    for(int i = 0; i < testObiekt.length(); i++) {
        if (testObiekt[i] < '0' || testObiekt[i] > '9')
            return false;
        liczbaKoncowa *= 10;
        liczbaKoncowa += (int)(testObiekt[i]) - (int)('0');
    }

    this->tempLiczba = liczbaKoncowa;
    return true;
}

std::string Zakres::charToString(char *liczbaCh) {
   /* std::string wynik = "";

    for (int i = 0; i < dlug; i++) {
        wynik += liczbaCh[i];
    }

    return wynik; */
   return liczbaCh;
}

void Zakres::utworzLiczbe(std::string liczbaS) {
    this->czyUdane = true;

    if (this->stringToInt(liczbaS)) {
        if(this->tempLiczba > min && this->tempLiczba < max)
            this->liczba = this->tempLiczba;
        else
            this->czyUdane = false;
    } else
        this->czyUdane = false;
}

int Zakres::getLiczba() {
    return this->liczba;
}

bool Zakres::getCzyUdane() {
    return this->czyUdane;
}

void Zakres::operator=(const Zakres *zak) {
    this->czyUdane = true;

    this->min = zak->min;
    this->max = zak->max;
    this->liczba = zak->liczba;
}

void Zakres::operator=(std::string liczbaS) {
    this->czyUdane = true;
    this->utworzLiczbe(liczbaS);
}


