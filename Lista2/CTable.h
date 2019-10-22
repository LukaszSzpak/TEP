//
// Created by RC on 20.10.2019.
//

#include <string>

#ifndef LISTA2_CTABLE_H
#define LISTA2_CTABLE_H


class CTable {
    static const int DEF_SIZE = 5;
    const std::string DEF_NAME = "Tom";

public:
    CTable();
    CTable(std::string sName, int tabLen);
    CTable(CTable &pcOther);
    ~CTable();


    void vSetName(std::string sName);
    bool bSetNewSize(int newSize);
    CTable *pcClone();
    void v_mod_table(CTable *pcTab, int newSize);
    void print_CTable();

private:
    std::string sName;
    int tabLen;
    int *tab;
};


#endif //LISTA2_CTABLE_H
