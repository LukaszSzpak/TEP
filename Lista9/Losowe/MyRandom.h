//
// Created by RC on 05.01.2020.
//

#ifndef LISTA9_MYRANDOM_H
#define LISTA9_MYRANDOM_H

#include <random>
#include <iostream>

class MyRandom {
public:
    MyRandom(std::random_device rd);
    MyRandom();

    int getInt(int min, int max);
    double getDouble(double min, double max);

private:
    std::uniform_int_distribution<> dis;
    std::mt19937 gen;
};


#endif //LISTA9_MYRANDOM_H
