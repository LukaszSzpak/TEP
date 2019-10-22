//
// Created by RC on 20.10.2019.
//

#include <iostream>
#include "CTable.h"


CTable::CTable() {
    this->sName = this->DEF_NAME;
    this->tabLen = this->DEF_SIZE;
    this->tab = new int[this->tabLen];
}

CTable::CTable(std::string sName, int tabLen) {
    this->sName = sName;
    this->tabLen = tabLen;
    this->tab = new int[tabLen];
}

CTable::CTable(CTable &pcOther) {
    this->sName = pcOther.sName + "_copy";
    this->tabLen = pcOther.tabLen;
    this->tab = pcOther.tab;

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
