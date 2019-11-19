//
// Created by RC on 19.11.2019.
//

#ifndef LISTA5_CNODESTATIC_H
#define LISTA5_CNODESTATIC_H

#include <iostream>
#include <vector>

class CNodeStatic {
private:
    std::vector<CNodeStatic> v_children;
    CNodeStatic *pc_parent_node;
    int i_val;
public:
    CNodeStatic();
    ~CNodeStatic();
    void vSetValue(int iNewVal);
    int iGetChildrenNumber();
    void vAddNewChild();
    void vAddNewChild(CNodeStatic& cNewNode);
    void vRemoveChild(CNodeStatic& cNodeToRemove);
    void vPrint();
    void vPrintAllBelow();
    void vPrintUp();
    int iGetChildPosition(const CNodeStatic &cNodeStatic);
    CNodeStatic *pcGetParent() const;
    CNodeStatic *pcGetChild(int iChildOffset);
    CNodeStatic *pcGetRoot(CNodeStatic *cNodeStatic);
};//class CNodeStatic


#endif //LISTA5_CNODESTATIC_H
