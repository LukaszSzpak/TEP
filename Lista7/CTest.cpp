//
// Created by RC on 03.12.2019.
//

#include <iostream>
#include "CTest.h"

CTest::CTest(std::string name) {
    this->name = name;
}

std::string CTest::getName() {
    return this->name;
}

void CTest::print() {
    std::cout<<this->name<<"\n";
}
