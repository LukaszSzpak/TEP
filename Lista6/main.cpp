#include <iostream>
#include "Dynamic/CTreeDynamic.h"
#include "CTable.h"
#include <string>

int main() {

    CTreeDynamic<std::string> *c_tree = new CTreeDynamic<std::string>();
    CNodeDynamic<std::string> *c_root = c_tree->pcGetRoot();
    c_root->vAddNewChild();
    c_root->vAddNewChild();
    c_root->pcGetChild(0)->vSetValue("1");
    c_root->pcGetChild(1)->vSetValue("2");
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue("11");
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue("12");
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue("21");
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue("22");
    c_tree->vPrintTree();

    std::cout<<"\nTab int:\n";
    CTable<int> *cTabInt = new CTable<int>();
    std::cout<<"Czy udalo sie zmienic dlugosc: "<<cTabInt->bSetLength(5);
    std::cout<<"\nCzy udalo sie 5: "<<cTabInt->bSetElement(2, 5);
    std::cout<<"\nCzy udalo sie -1: "<<cTabInt->bSetElement(1, -1);
    cTabInt->printTable();

    std::cout<<"\n\nTab float:\n";
    CTable<float> *cTabFloat = new CTable<float>();
    std::cout<<"Czy udalo sie zmienic dlugosc: "<<cTabFloat->bSetLength(3);
    std::cout<<"\nCzy udalo sie 5: "<<cTabFloat->bSetElement(2, 5.0);
    std::cout<<"\nCzy udalo sie -1: "<<cTabFloat->bSetElement(1, -1.2);
    cTabFloat->printTable();

    return 0;
}