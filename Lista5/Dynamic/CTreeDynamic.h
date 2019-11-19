//
// Created by RC on 19.11.2019.
//

#ifndef LISTA5_CTREEDYNAMIC_H
#define LISTA5_CTREEDYNAMIC_H

#include "CNodeDynamic.h"

class CTreeDynamic {
private:
    CNodeDynamic *pc_root;

public:
    CTreeDynamic();
    ~CTreeDynamic();
    CNodeDynamic *pcGetRoot();
    void vPrintTree();
    bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);

};//class CTreeStatic


#endif //LISTA5_CTREEDYNAMIC_H
