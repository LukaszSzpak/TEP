#include <iostream>
#include "CTab.h"
#include "CTable.h"

int main() {

    CTab Ct1;
    CTab Ct2 = std::move(Ct1);

    CTable Ctab1;
    CTable Ctab2 = std::move(Ctab1);

    return 0;
}