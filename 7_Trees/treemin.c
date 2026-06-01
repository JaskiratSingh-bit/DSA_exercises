# include "elemtype.h"
#include "tree.h"

extern const ElemType *BstTreeMin(const Node *n) {
    if (TreeIsEmpty(n)) {
        return NULL;
    }

    while (TreeLeft(n) != NULL) {
      n = TreeLeft(n);
    }

    return &n->value;
}

ElemType ContaNodi(const Node*n) {
    if (TreeIsEmpty(n)) {
        return 0;
    }
    return 1 + ContaNodi(TreeLeft(n)) + ContaNodi(TreeRight(n));
}

ElemType *Nodi(const Node *n,ElemType *min) {
    if (TreeIsEmpty(n)) {
        return NULL;
    }

    if (n->value<*min) {
        *min=n->value;
    }

    Nodi(TreeLeft(n),min);
    Nodi(TreeRight(n),min);
    return min;
}

extern const ElemType *TreeMin(const Node *n) {

    if (TreeIsEmpty(n)) {
        return NULL;
    }

    const ElemType *max = &n->value;
    ElemType *m = Nodi(n,max);
    return m;

}

