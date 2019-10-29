#include <iostream>
#include "CTable.h"

int main() {

    CTable *cTable = new CTable();
    cTable->print_CTable();

    cTable->vSetName("jaaa");
    cTable->print_CTable();
    std::cout<<"Czy udalo haslo: "<<cTable->vSetPassword("KlaoD56l")<<"\n";
    std::cout<<"Czy udalo haslo: "<<cTable->vChangePassword("KlaoD56a")<<"\n";
    std::cout<<"Czy udalo haslo: "<<cTable->vChangePassword("KokddvD56a")<<"\n";

    delete(cTable);

    CTable *c1 = new CTable();
    CTable *c2 = new CTable();

    c1->bSetNewSize(5);
    c2->bSetNewSize(4);
    c1 = c2;

    std::cout<<"Testy \n";
    c1->print_CTable();
    c2->print_CTable();

    c2->vSetValueAt(0, 5);
    c2->printTable();
    c1->printTable();
}