//
// Created by RC on 20.10.2019.
//

#include <iostream>
#include "CTable.h"


CTable::CTable() {
    this->sName = this->DEF_NAME;
    this->tabLen = this->DEF_SIZE;
    this->tab = new int[this->tabLen];
    this->sPassword = this->DEF_PASS;
}

CTable::CTable(std::string sName, int tabLen) {
    this->sName = sName;
    this->tabLen = tabLen;
    this->tab = new int[tabLen];
    this->sPassword = this->DEF_PASS;
}

CTable::CTable(const CTable &pcOther) {
    this->sName = pcOther.sName + "_copy";
    this->tabLen = pcOther.tabLen;
    this->tab = pcOther.tab;
    this->sPassword = pcOther.sPassword;

    std::cout<<"Kopiuj "<<pcOther.sName<<"\n";
}

CTable::~CTable() {
    std::cout<<"usuwam "<<this->sName<<"\n";

    delete(this->tab);
}

void CTable::vSetName(std::string sName) {
    this->sName = sName;
}

bool CTable::bSetNewSize(int newSize) {
    if(newSize < 1 || newSize > 1000)
        return false;

    this->tabLen = newSize;
    delete(this->tab);

    this->tab = new int[this->tabLen];
    return true;
}

CTable *CTable::pcClone() {
    CTable *newTable = new CTable(*this);
    return newTable;
}

void CTable::v_mod_table(CTable *pcTab, int newSize) {
    if(newSize < 1 || newSize > 1000)
        return;
    delete(pcTab->tab);

    pcTab->tab = new int[newSize];

}

void CTable::print_CTable() {
    std::cout<<this->sName<<" "<<this->tabLen<<"\n";
}

bool CTable::vSetPassword(std::string sPass) {
    if (this->checkPass(sPass)) {
        this->sPassword = sPass;
        return true;
    }

    return false;
}

bool CTable::vChangePassword(std::string sPass) {
    if (this->checkPass(sPass)) {
        int count = 0;

        for (int i = 0; i < sPass.size() && i < sPass.size(); i++) {
            if (sPass[i] != this->sPassword[i])
                count++;
        }

        if (count >= 2 || (sPass.size() - this->sPassword.size() == 1 && count >= 1) || sPass.size() - this->sPassword.size() >= 2)
            return true;
    }
    return false;
}

bool CTable::checkPass(std::string sPass) {
    if(sPass.size() < 5)
        return false;

    bool isBig = false;
    bool isSmall = false;
    bool isSign = false;

    for (int i = 0; i < sPass.size(); i++) {
        if (sPass[i] >= 'A' && sPass[i] <= 'Z')
            isBig = true;
        else if (sPass[i] >= 'a' && sPass[i] <= 'z')
            isSmall = true;
        else if (sPass[i] >= '0' && sPass[i] <= '9')
            isSign = true;
    }

    return isBig && isSign && isSmall;

}

void CTable::vSetValueAt(int iOffset, int iNewVal) {
    if (iOffset >= this->tabLen)
        return;
    this->tab[iOffset] = iNewVal;
}

void CTable::printTable() {
    for(int i = 0; i < this->tabLen; i++)
        std::cout<<this->tab[i]<<" ";
    std::cout<<"\n";
}

CTable *CTable::operator+(CTable &CTother) {
    int newLen = this->tabLen + CTother.tabLen;
    int *newTab = new int[newLen];
    int i;

    for (i = 0; i < this->tabLen; ++i) {
        newTab[i] = this->tab[i];
    }

    for(; i < CTother.tabLen; i++) {
        newTab[i] = CTother.tab[i - CTother.tabLen];
    }

    this->tab = newTab;
    this->tabLen = newLen;

    return this;
}
