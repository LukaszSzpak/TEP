//
// Created by RC on 20.10.2019.
//

#include <string>

#ifndef LISTA2_CTABLE_H
#define LISTA2_CTABLE_H

#define DEF_SIZE 5;
#define DEF_NAME "Tom";
#define DEF_PASS "Pass5";

class CTable {

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
    void vSetValueAt(int iOffset, int iNewVal);
    void printTable();
    CTable operator+(const CTable &CTother);
    void operator=(const CTable &pcOther);

private:
    std::string sName;
    std::string sPassword;
    int tabLen;
    int *tab;

    bool checkPass(std::string sPass);
};


#endif //LISTA2_CTABLE_H
