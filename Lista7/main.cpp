#include <iostream>
#include "CTest.h"
#include "CMySmartPointer.h"

int main() {

    CMySmartPointer<CTest> cmy1(new CTest("Test1"));
    CMySmartPointer<CTest> cmy2 = cmy1;

    cmy1->print();
    cmy2->print();

    cmy1 = cmy1;
    cmy1->print();


    return 0;
}