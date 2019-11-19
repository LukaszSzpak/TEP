//
// Created by RC on 19.11.2019.
//

#include "CTreeStatic.h"

CTreeStatic::CTreeStatic() {

}

CTreeStatic::~CTreeStatic() {

}

void CTreeStatic::vPrintTree() {
    c_root.vPrintAllBelow();
}

bool CTreeStatic::bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode) {
    if (pcParentNode != NULL && pcNewChildNode != NULL) {
        if (pcParentNode->pcGetRoot(pcParentNode) == pcNewChildNode->pcGetRoot(pcNewChildNode))
            return false;

        CNodeStatic *pc_parent_temp = pcNewChildNode->pcGetParent();
        if (pc_parent_temp == NULL)
            return false;

        pcParentNode->vAddNewChild(*pcNewChildNode);
        pc_parent_temp->vRemoveChild(*pcNewChildNode);

        return true;
    }

    return false;
}

CNodeStatic *CTreeStatic::pcGetRoot() {
    return(&c_root);
}

