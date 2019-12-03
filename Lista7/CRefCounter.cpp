//
// Created by RC on 03.12.2019.
//

#include "CRefCounter.h"

CRefCounter::CRefCounter() {
    this->i_count = 0;
    this->max_count = 0;
}

void CRefCounter::check_max() {
    if (this->i_count > this-> max_count)
        max_count = i_count;
}

int CRefCounter::iAdd() {
    this->i_count++;
    this->check_max();

    return this->i_count;
}
