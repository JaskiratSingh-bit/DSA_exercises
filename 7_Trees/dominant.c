# include "elemtype.h"
#include "tree.h"

extern int CountDominant(const Node *t) {
    if (TreeIsEmpty(t)) return 0;
    if (TreeIsLeaf(t))  return 0;

    ElemType somma = 0;
    if (!TreeIsEmpty(TreeLeft(t)))
        somma += *TreeGetRootValue(TreeLeft(t));
    if (!TreeIsEmpty(TreeRight(t)))
        somma += *TreeGetRootValue(TreeRight(t));

    int dom = 0;
    if (*TreeGetRootValue(t) > somma)
        dom = 1;

    dom += CountDominant(TreeLeft(t));
    dom += CountDominant(TreeRight(t));

    return dom;
}