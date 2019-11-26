//
// Created by RC on 19.11.2019.
//

#include "CNodeDynamic.h"

template <typename T>
CNodeDynamic<T>::CNodeDynamic() {
    i_val = 0;
    pc_parent_node = NULL;
}

template <typename T>
CNodeDynamic<T>::~CNodeDynamic() {
    std::cout<<"usuwanie wezla: "<<i_val<<"\n";

    for (int i = 0; i < v_children.size(); i++)
        if (v_children[i] != NULL)
            delete v_children[i];
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild() {
    CNodeDynamic<T> *cNewNode = new CNodeDynamic;
    cNewNode->pc_parent_node = this;
    v_children.push_back(cNewNode);
}

template <typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetChild(int iChildOffset) {
    if (iChildOffset < v_children.size() && iChildOffset >= 0)
        return v_children.at(iChildOffset);

    return NULL;
}

template <typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < v_children.size(); i++)
        if (v_children.at(i) != NULL)
            v_children.at(i)->vPrintAllBelow();

}

template <typename T>
void CNodeDynamic<T>::vPrintUp() {
    vPrint();
    if (pc_parent_node != NULL)
        pc_parent_node->vPrintUp();

}

template <typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic<T> *cNewChild) {
    cNewChild->pc_parent_node = this;
    v_children.push_back(cNewChild);
}

template <typename T>
int CNodeDynamic<T>::iGetChildPosition(const CNodeDynamic<T>  *cNodeDynamic) {
    for (int i = 0; i < v_children.size(); i++)
        if (v_children.at(i) == cNodeDynamic)
            return i;

    return -1;
}

template <typename T>
void CNodeDynamic<T>::vRemoveChild(CNodeDynamic<T> *cRemoveNode) {
    cRemoveNode->pc_parent_node = NULL;

    int iChildPosition = iGetChildPosition(cRemoveNode);

    if (iChildPosition >= 0)
        v_children.erase(v_children.begin() + iChildPosition);
}

template <typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetParent() {
    return pc_parent_node;
}

template <typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetRoot(CNodeDynamic<T>* cNodeDynamic) {
    if (cNodeDynamic->pc_parent_node != NULL)
        pcGetRoot(cNodeDynamic->pc_parent_node);

    return cNodeDynamic;
}

template <typename T>
void CNodeDynamic<T>::vPrint() {
    std::cout << " " << i_val;
}

template <typename T>
int CNodeDynamic<T>::iGetChildrenNumber() {
    return v_children.size();
}

template <typename T>
void CNodeDynamic<T>::vSetValue(T iNewVal) {
    i_val = iNewVal;
}
