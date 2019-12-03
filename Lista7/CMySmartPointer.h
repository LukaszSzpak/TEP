//
// Created by RC on 03.12.2019.
//

#ifndef LISTA7_CMYSMARTPOINTER_H
#define LISTA7_CMYSMARTPOINTER_H

#include "CRefCounter.h"

template < typename T > class CMySmartPointer {
public:
    CMySmartPointer(T *pcPointer) {
        pc_pointer = pcPointer;
        pc_counter = new CRefCounter();
        pc_counter->iAdd();
    }
    CMySmartPointer(const CMySmartPointer &pcOther) {
        pc_pointer = pcOther.pc_pointer;
        pc_counter = pcOther.pc_counter;
        pc_counter->iAdd();
    }
    ~CMySmartPointer() {
        if (pc_counter->iDec() == 0) {
            delete pc_pointer;
            delete pc_counter;
        }
    }
    T& operator*() { return(*pc_pointer); }
    T* operator->() { return(pc_pointer); }
    T* operator=(const T* copy) {
        delete(this);
        return new CMySmartPointer(copy);
    }
private:
    CRefCounter *pc_counter;
    T *pc_pointer;
};


#endif //LISTA7_CMYSMARTPOINTER_H
