#include "elemtype.h"
#include "tree.h"
// un nuovo nodo da inserire in un albero finsice sempre come una foglia indipendete se ha figli o meno
extern Node *BstInsert(const ElemType *e, Node *n) {

    Node *nn = TreeCreateRoot(e,NULL,NULL);

    if (TreeIsEmpty(n)) {
        return nn;
    }
    Node *tmp=n;
    Node *padre=NULL;
    while (tmp != NULL) {
        padre = tmp;
        if (ElemCompare(&tmp->value,e)<0) {
            tmp=tmp->right;
        }
        else {
            tmp=tmp->left;
        }
    }

    if (ElemCompare(&padre->value,e)<0) {
       padre->right=nn;
    }
    else {
        padre->left = nn;
    }
    return n;
}

extern Node *BstInsertRec(const ElemType *e, Node *n) {

        if (TreeIsEmpty(n)){
            return
            TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
        }
        if(ElemCompare(e, TreeGetRootValue(n)) <= 0) {
            n->left = BstInsertRec(e, TreeLeft(n)); // sottoalb. sx
        } else {
            n->right = BstInsertRec(e, TreeRight(n)); // sottoalb. dx
        }
        return n;

}