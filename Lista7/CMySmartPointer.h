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
    CMySmartPointer& operator=(const CMySmartPointer* copy);
    void print_status();
private:
    CRefCounter *pc_counter;
    T *pc_pointer;
};

template <typename T>
CMySmartPointer<T>& CMySmartPointer<T>::operator=(const CMySmartPointer *copy)  {
    if(!(this == copy && this->pc_pointer == copy->pc_pointer)) {
        if (pc_counter->iDec() == 0) {
            delete pc_pointer;
            delete pc_counter;
        }
        this->pc_counter = copy->pc_counter;
        this->pc_pointer = copy->pc_pointer;
        this->pc_counter->iAdd();
    }
    return *this;
}

template <typename T>
void CMySmartPointer<T>::print_status(){
    std::cout<<"Jestem: "<<(*this->pc_pointer);
    std::cout<<"\nMam odwolan: "<<this->pc_counter->iGet();
    std::cout<<"\nMax odwolan: "<<this->pc_counter->iGetMax();
}

template <>
void CMySmartPointer<std::string>::print_status(){
    std::cout<<"Jestem: "<<this->pc_pointer;
    std::cout<<"\nMam odwolan: "<<this->pc_counter->iGet();
    std::cout<<"\nMax odwolan: "<<this->pc_counter->iGetMax();
}

#endif //LISTA7_CMYSMARTPOINTER_H
