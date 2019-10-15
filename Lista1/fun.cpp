//
// Created by RC on 15.10.2019.
//
#include <iostream>
#include "fun.h"

            //* PIERWSZA CZESC *//
//polecenie 1
void v_alloc_table_add_5(int iSize) {
    std::cout<<"Zadanie 1:\n";
    if(iSize < 0) {
        std::cout<<"Niepoprawne wywołanie funkcji !";
        return;
    }
    //tworzenie tablicy
    int *tab;
    tab = new int[iSize];

    // uzupełnienie tablicy
    for (int i = 0; i < iSize; i++) {
        tab[i] = i + 5;
    }

    //wyswietlenie tablicy
    for(int i = 0; i < iSize; i++) {
        std::cout<<tab[i]<<" ";
    }
    std::cout<<"\n";

    //usuwane tablicy
    delete(tab);
}

//polecenie 2
bool b_alloc_table_2_dim(int **(*piTable), int iSizeX, int iSizeY) {
    if (iSizeX <=0 || iSizeY <= 0)
        return false;

    *piTable = new int*[iSizeX];
    for (int i = 0; i < iSizeX; i++) {
        (*piTable)[i] = new int[iSizeY];

        for (int ii = 0; ii < iSizeY; ii++)
            (*piTable)[i][ii] = i + ii;  //a->   (a*)
    }

    return true;
}

// funkcja wyswietalajaca tablice
void print_tab(int **(*piTable), int iSizeX, int iSizeY) {
    std::cout<<"\nWyswietlam tablice:\n";
    for (int i = 0; i < iSizeX; i++) {
        for (int j = 0; j < iSizeY; j++)
            std::cout<<(*piTable)[i][j]<<" ";
        std::cout<<"\n";
    }
}

//polecenie 3
bool b_dealloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
    if (iSizeX <=0 || iSizeY <= 0)
        return false;

    for (int i = 0; i < iSizeX; i++)
        delete((*piTable)[i]);
    delete(*piTable);
    return true;
}

        //* CZESC DRUGA *//

void showArray(int *array, int size) {
    std::cout<<"\nWyswietalm tablice:\n";
    for (int i = 0; i < size; i++)
        std::cout<<array[i]<<" ";
}

int *v_alloc(int size) {
    if(size < 1 || size > 1000)
        return NULL;

    int *array = new int[size];

    for (int i = 0; i < size; i++)
        array[i] = i + 5;

    return array;
}

bool v_alloc2(int **ptr, int size) {
    if(size < 1 || size > 1000)
        return false;

    *ptr = new int[size];

    for (int i = 0; i < size; i++)
        (*ptr)[i] = i + 10;

    return true;
}

void de_alloc(int **ptr) {
    delete*(ptr);
    ptr = NULL;
}
