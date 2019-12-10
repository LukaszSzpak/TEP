#include <iostream>
#include "CTab.h"

CTab::CTab(const CTab &cOther) {
    v_copy(cOther);
    std::cout << "Copy ";
}

CTab::~CTab() {
    if (pi_tab != NULL)
        delete pi_tab;

    std::cout << "Destr ";
}

CTab CTab::operator=(const CTab &cOther) {
    if (pi_tab != NULL)
        delete pi_tab;

    v_copy(cOther);
    std::cout << "op= ";

    return(*this);
}

void CTab::v_copy(const CTab &cOther) {
    pi_tab = new int[cOther.i_size];
    i_size = cOther.i_size;

        for (int ii = 0; ii < cOther.i_size; ii++)
            pi_tab[ii] = cOther.pi_tab[ii];
}

CTab::CTab(CTab &&cOther) {
    if(this->pi_tab != NULL)
        delete(this->pi_tab);

    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;

    cOther.pi_tab = NULL;
    std::cout << "MOVE ";
}

CTab CTab::operator=(CTab &&cOther) {
    if(this->pi_tab != NULL)
        delete(this->pi_tab);

    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;

    cOther.pi_tab = NULL;
    std::cout << "MOVE op= ";

    return *this;
}

bool CTab::bSetSize(int newSize) {
    if(newSize < 1 || newSize > 1000)
        return false;

    this->i_size = newSize;
    delete(this->pi_tab);

    this->pi_tab = new int[this->i_size];
    return true;
}
