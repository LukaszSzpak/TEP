#include <iostream>
#include "Static/CTreeStatic.h"

int main() {

    //Test drzewa statycznego
    CTreeStatic c_tree;
    CNodeStatic *c_root = c_tree.pcGetRoot();
    c_root->vAddNewChild();
    c_root->vAddNewChild();
    c_root->pcGetChild(0)->vSetValue(1);
    c_root->pcGetChild(1)->vSetValue(2);
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);
    c_tree.vPrintTree();

    return 0;
}