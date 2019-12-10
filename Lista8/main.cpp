#include <iostream>
#include "CTab.h"
#include "CTable.h"
#include <ratio>
#include <chrono>
#include <algorithm>

#define iloscProb 100000

int main() {
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < iloscProb; i++) {
        CTab Ct1;
        CTab Ct2 = std::move(Ct1);
    }

    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time = t2 - t1;

    std::cout<<"\nCzas move: "<<time.count()<<"\n";



    t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iloscProb; i++) {
        int *tab = new int[100];
        int *tab2 = new int[100];
        std::copy(tab, tab+99, tab2);
    }
    t2 = std::chrono::high_resolution_clock::now();
    time = t2 - t1;
    std::cout<<"\nCzas copy: "<<time.count()<<"\n";

   // CTable Ctab1;
   // CTable Ctab2 = std::move(Ctab1);

    return 0;
}