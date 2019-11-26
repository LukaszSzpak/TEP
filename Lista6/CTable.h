//
// Created by RC on 26.11.2019.
//

#ifndef LISTA6_CTABLE_H
#define LISTA6_CTABLE_H

#include <iostream>

template< typename T > class CTable
{
public:
    CTable() { i_size = 0; pt_table = NULL; }
    ~CTable() { if (pt_table != NULL) delete [] pt_table; }
    bool bSetLength(int iNewSize);

    T* ptGetElement(int iOffset);
    bool bSetElement(int iOffset, T tVal);
    void printTable();
private:
    int i_size;
    T *pt_table;
};

template <typename T>
bool CTable<T>::bSetLength(int iNewSize) {
    if (iNewSize <= 0)
        return(false);
    T *pt_new_table;
    pt_new_table = new T[iNewSize];

    if (pt_table != NULL) {
        int i_min_len;
        if (iNewSize < this->i_size)
            i_min_len = iNewSize;
        else
            i_min_len = this->i_size;
        for (int ii = 0; ii < i_min_len; ii++)
            pt_new_table[ii] = pt_table[ii];
        delete[] pt_table;
    }

    pt_table = pt_new_table;
    this->i_size = iNewSize;
    return(true);
}

template <typename T>
T* CTable<T>::ptGetElement(int iOffset) {
    if (!(0 <= iOffset) && (iOffset < this->i_size))
        return(NULL);

    return(&(pt_table[iOffset]));
}

template <typename T>
bool CTable<T>::bSetElement(int iOffset, T tVal) {
    if (!(0 <= iOffset) && (iOffset < this->i_size))
        return(false);

    pt_table[iOffset] = tVal;
    return(true);
}

template<typename T>
void CTable<T>::printTable() {
    std::cout<<"\nWyswietlam tablice:\n";
    for(unsigned int i = 0; i < this->i_size; i++) {
        std::cout<<this->pt_table[i]<<"\t";
    }
}

template<>
bool CTable<int>::bSetElement(int iOffset, int Val) {
    if (!(0 <= iOffset) && (iOffset < this->i_size))
        return(false);

    if (Val <= 0)
        return false;

    pt_table[iOffset] = Val;
    return(true);
}

template<>
bool CTable<float>::bSetElement(int iOffset, float Val) {
    if (!(0 <= iOffset) && (iOffset < this->i_size))
        return(false);

    if (Val >= 0)
        return false;

    pt_table[iOffset] = Val;
    return(true);
}

#endif //LISTA6_CTABLE_H
