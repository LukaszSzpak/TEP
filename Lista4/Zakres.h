//
// Created by RC on 12.11.2019.
//

#ifndef LISTA4_ZAKRES_H
#define LISTA4_ZAKRES_H

#include <String>


class Zakres {

private:
    int liczba;
    int tempLiczba;
    int min;
    int max;
    bool czyUdane;
    bool stringToInt(std::string testObiekt);
    std::string charToString(char* liczbaCh);
    void utworzLiczbe(std::string liczbaS);
public:
    Zakres(std::string liczbaS, int min, int max);
    Zakres(char* liczbaCh, int min, int max);
    int getLiczba();
    bool getCzyUdane();
    void operator=(const Zakres *zak);
    void operator=(std::string liczbaS);

};


#endif //LISTA4_ZAKRES_H
