//
// Created by RC on 19.11.2019.
//

#include "CNodeStatic.h"

CNodeStatic::CNodeStatic() {
    i_val = 0;
    pc_parent_node = NULL;
}

CNodeStatic::~CNodeStatic() {

}

void CNodeStatic::vAddNewChild() {
    CNodeStatic cNewNode;
    cNewNode.pc_parent_node = this;
    v_children.push_back(cNewNode);
}

CNodeStatic *CNodeStatic::pcGetChild(int iChildOffset) {
    if (iChildOffset < v_children.size())
        return &v_children.at(iChildOffset);

    else return NULL;
}


void CNodeStatic::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < v_children.size(); i++)
        if (pcGetChild(i) != NULL) pcGetChild(i)->vPrintAllBelow();
}

void CNodeStatic::vPrintUp() {
    vPrint();
    if (pc_parent_node != NULL)
        if (pc_parent_node != NULL) pc_parent_node->vPrintUp();

}


void CNodeStatic::vAddNewChild(CNodeStatic &cNewNode) {
    cNewNode.pc_parent_node = this;
    v_children.push_back(cNewNode);
}

void CNodeStatic::vRemoveChild(CNodeStatic &cRemoveNode) {
    cRemoveNode.pc_parent_node = NULL;

    int iChildPosition = iGetChildPosition(cRemoveNode);

    if (iChildPosition != -1)
        v_children.erase(v_children.begin() + iChildPosition);
}
int CNodeStatic::iGetChildPosition(const CNodeStatic &cNodeStatic) {
    for (int i = 0; i < v_children.size(); i++) {
        if (&v_children.at(i) == &cNodeStatic)
            return i;
    }
    return -1;
}

CNodeStatic *CNodeStatic::pcGetParent() const {
    return pc_parent_node;
}

CNodeStatic *CNodeStatic::pcGetRoot(CNodeStatic* cNodeStatic) {
    if (cNodeStatic->pc_parent_node != NULL)
        pcGetRoot(cNodeStatic->pc_parent_node);

    return cNodeStatic;
}

void CNodeStatic::vSetValue(int iNewVal) {
    i_val = iNewVal;
}

int CNodeStatic::iGetChildrenNumber() {
    return (v_children.size());
}

void CNodeStatic::vPrint() {
    std::cout << " " << i_val;
}

