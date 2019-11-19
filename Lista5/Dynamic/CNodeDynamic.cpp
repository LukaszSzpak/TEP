//
// Created by RC on 19.11.2019.
//

#include "CNodeDynamic.h"

CNodeDynamic::CNodeDynamic() {
    i_val = 0;
    pc_parent_node = NULL;
}

CNodeDynamic::~CNodeDynamic() {
    std::cout<<"usuwanie wezla: "<<i_val<<"\n";

    for (int i = 0; i < v_children.size(); i++)
        if (v_children[i] != NULL)
            delete v_children[i];
}

void CNodeDynamic::vAddNewChild() {
    CNodeDynamic *cNewNode = new CNodeDynamic;
    cNewNode->pc_parent_node = this;
    v_children.push_back(cNewNode);
}

CNodeDynamic *CNodeDynamic::pcGetChild(int iChildOffset) {
    if (iChildOffset < v_children.size())
        return v_children.at(iChildOffset);

    return NULL;
}

void CNodeDynamic::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < v_children.size(); i++)
        if (v_children.at(i) != NULL)
            v_children.at(i)->vPrintAllBelow();

}
void CNodeDynamic::vPrintUp() {
    vPrint();
    if (pc_parent_node != NULL) pc_parent_node->vPrintUp();

}

void CNodeDynamic::vAddNewChild(CNodeDynamic *cNewChild) {
    cNewChild->pc_parent_node = this;
    v_children.push_back(cNewChild);
}

int CNodeDynamic::iGetChildPosition(const CNodeDynamic  *cNodeDynamic) {
    for (int i = 0; i < v_children.size(); i++)
        if (v_children.at(i) == cNodeDynamic)
            return i;

    return -1;
}

void CNodeDynamic::vRemoveChild(CNodeDynamic *cRemoveNode) {
    cRemoveNode->pc_parent_node = NULL;

    int iChildPosition = iGetChildPosition(cRemoveNode);

    if (iChildPosition >= 0)
        v_children.erase(v_children.begin() + iChildPosition);
}

CNodeDynamic *CNodeDynamic::pcGetParent() {
    return pc_parent_node;
}

CNodeDynamic *CNodeDynamic::pcGetRoot(CNodeDynamic* cNodeDynamic) {
    if (cNodeDynamic->pc_parent_node != NULL)
        pcGetRoot(cNodeDynamic->pc_parent_node);

    return cNodeDynamic;
}

void CNodeDynamic::vPrint() {
    std::cout << " " << i_val;
}

int CNodeDynamic::iGetChildrenNumber() {
    return v_children.size();
}

void CNodeDynamic::vSetValue(int iNewVal) {
    i_val = iNewVal;
}
