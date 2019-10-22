#include "CTable.h"

int main() {

    CTable *cTable = new CTable();
    cTable->print_CTable();

    cTable->vSetName("jaaa");
    cTable->print_CTable();

    delete(cTable);




}