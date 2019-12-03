//
// Created by RC on 03.12.2019.
//

#ifndef LISTA7_CTEST_H
#define LISTA7_CTEST_H


#include <string>
#include <iostream>

class CTest {
private:
    std::string name;

public:
    CTest(std::string name);
    std::string getName();
    void print();
    friend std::ostream &operator<<(std::ostream &os, const CTest &myC);
};


#endif //LISTA7_CTEST_H
