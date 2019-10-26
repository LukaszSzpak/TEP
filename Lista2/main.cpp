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




}