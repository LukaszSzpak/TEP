//
// Created by RC on 20.10.2019.
//

#include <string>

#ifndef LISTA2_CTABLE_H
#define LISTA2_CTABLE_H


class CTable {
    static const int DEF_SIZE = 5;
    const std::string DEF_NAME = "Tom";
    const std::string DEF_PASS = "Pass5";

public:
    CTable();
    CTable(std::string sName, int tabLen);
    CTable(const CTable &pcOther);
    ~CTable();


    void vSetName(std::string sName);
    bool vSetPassword(std::string sPass);
    bool vChangePassword(std::string sPass);
    bool bSetNewSize(int newSize);
    CTable *pcClone();
    void v_mod_table(CTable *pcTab, int newSize);
    void print_CTable();

private:
    std::string sName;
    std::string sPassword;
    int tabLen;
    int *tab;

    bool checkPass(std::string sPass);
};


#endif //LISTA2_CTABLE_H
