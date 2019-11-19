//
// Created by RC on 19.11.2019.
//

#ifndef LISTA5_CTREESTATIC_H
#define LISTA5_CTREESTATIC_H

#include "CNodeStatic.h"

class CTreeStatic {
public:
    CTreeStatic();
    ~CTreeStatic();
    CNodeStatic *pcGetRoot();
    bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode);
    void  vPrintTree();
private:
    CNodeStatic c_root;
};


#endif //LISTA5_CTREESTATIC_H
