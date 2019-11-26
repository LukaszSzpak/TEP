#include <iostream>
#include "Dynamic/CTreeDynamic.h"
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

    return 0;
}