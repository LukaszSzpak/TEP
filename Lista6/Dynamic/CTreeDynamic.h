//
// Created by RC on 19.11.2019.
//

#ifndef LISTA5_CTREEDYNAMIC_H
#define LISTA5_CTREEDYNAMIC_H

#include "CNodeDynamic.h"

template <typename T> class CTreeDynamic {
private:
    CNodeDynamic<T> *pc_root;

public:
    CTreeDynamic();
    ~CTreeDynamic();
    CNodeDynamic<T> *pcGetRoot();
    void vPrintTree();
    bool bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode);

};//class CTreeStatic


#endif //LISTA5_CTREEDYNAMIC_H
