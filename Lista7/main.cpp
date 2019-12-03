#include <iostream>
#include "CTest.h"
#include "CMySmartPointer.h"

int main() {

    CMySmartPointer<CTest> cmy1(new CTest("Test1"));
    CMySmartPointer<CTest> cmy2 = CMySmartPointer<CTest>(cmy1);
    CMySmartPointer<CTest> cmy3(new CTest("Test3"));

    cmy1->print();
    cmy2->print();

    cmy1->print();
    cmy1.print_status();


    return 0;
}