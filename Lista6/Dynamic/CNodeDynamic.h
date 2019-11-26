//
// Created by RC on 19.11.2019.
//

#ifndef LISTA5_CNODEDYNAMIC_H
#define LISTA5_CNODEDYNAMIC_H

#include "vector"
#include "iostream"

template <typename T > class CNodeDynamic {
private:
    std::vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node;
    T i_val;
public:
    CNodeDynamic();
    ~CNodeDynamic();
    void vSetValue(T iNewVal);
    void vAddNewChild();
    void vAddNewChild(CNodeDynamic *cNewChild);
    void vPrint();
    void vPrintAllBelow();
    void vPrintUp();
    void vRemoveChild(CNodeDynamic *cNodeToRemove);
    CNodeDynamic *pcGetParent();
    CNodeDynamic *pcGetRoot(CNodeDynamic *cNodeDynamic);
    CNodeDynamic *pcGetChild(int iChildOffset);
    int iGetChildrenNumber();
    int iGetChildPosition(const CNodeDynamic *cNodeDynamic);
};


#endif //LISTA5_CNODEDYNAMIC_H
