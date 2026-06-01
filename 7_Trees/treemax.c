# include "elemtype.h"
#include "tree.h"


extern const ElemType *BstTreeMax(const Node *n) {

    if (TreeIsEmpty(n)) {
        return NULL;
    }

    while (TreeRight(n) != NULL) {
        n=TreeRight(n);
    }

    return TreeGetRootValue(n);
}

ElemType *TreeMaxRec(const Node *n,ElemType *max) {
    if (TreeIsEmpty(n)) {
        return NULL;
    }

    if (n->value>*max) {
        *max=n->value;
    }

    TreeMaxRec(TreeLeft(n),max);
    TreeMaxRec(TreeRight(n),max);
    return max;
}

extern const ElemType *TreeMax(Node *n) {
    if (TreeIsEmpty(n)) {
        return NULL;
    }
    const ElemType *max = &n->value;
    ElemType *m = TreeMaxRec(n,max);
    return m;
}
