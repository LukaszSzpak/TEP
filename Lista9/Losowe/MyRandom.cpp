//
// Created by RC on 05.01.2020.
//

#include "MyRandom.h"

MyRandom::MyRandom(std::random_device rd) {
    this->gen = std::mt19937(rd());
}

MyRandom::MyRandom() {
    std::random_device rd;
    this->gen = std::mt19937(rd());
}

int MyRandom::getInt(int min, int max) {
    this->dis = std::uniform_int_distribution<> (min, max);

    return this->dis(this->gen);
}

double MyRandom::getDouble(double min, double max) {
    this->dis = std::uniform_int_distribution<> ((min * 100), (max * 100));

    double temp = this->dis(this->gen);
    temp = temp / 100.00;

    return temp;
}
