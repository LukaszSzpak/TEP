//
// Created by RC on 19.11.2019.
//

#ifndef LISTA5_CTREEDYNAMIC_H
#define LISTA5_CTREEDYNAMIC_H

#include "CNodeDynamic.h"

template < typename T > class CTreeDynamic {
private:
    CNodeDynamic<T> *pc_root;

public:
    CTreeDynamic();
    ~CTreeDynamic();
    CNodeDynamic<T> *pcGetRoot();
    void vPrintTree();
    bool bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode);
};//class CTreeDynamic

    template <typename T>
    CTreeDynamic<T>::CTreeDynamic() {
        pc_root = new CNodeDynamic<T>();
    }

    template <typename T>
    CTreeDynamic<T>::~CTreeDynamic() {
        delete pc_root;
    }

    template <typename T>
    void CTreeDynamic<T>::vPrintTree() {
        pc_root->vPrintAllBelow();
    }

    template <typename T>
    bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode) {
        if (pcParentNode != NULL && pcNewChildNode != NULL) {
            if (pcParentNode->pcGetRoot(pcParentNode) == pcNewChildNode->pcGetRoot(pcNewChildNode))
                return false;

            CNodeDynamic<T> *pc_parent_temp = pcNewChildNode->pcGetParent();
            if (pc_parent_temp == NULL)
                return false;

            pcParentNode->vAddNewChild(pcNewChildNode);
            pc_parent_temp->vRemoveChild(pcNewChildNode);
            return true;
        }

        return false;
    }

    template <typename T>
    CNodeDynamic<T> *CTreeDynamic<T>::pcGetRoot() {
        return pc_root;
    }


#endif //LISTA5_CTREEDYNAMIC_H