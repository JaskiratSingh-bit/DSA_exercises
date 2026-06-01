#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>

extern Node *DeleteBstNode(Node *n, const ElemType *key) {

    if (TreeIsEmpty(n)) {
        return n;
    }
    Node *t = n;
    Node *parent = NULL;
    ElemType son = 0;  // 0 se sx e 1 se dx
    /* Logica del while : Continua a camminare finché:
    - n non è NULL (non sei uscito dall'albero)
    - E il valore corrente non è quello cercato*/
    while (!TreeIsEmpty(n) && ElemCompare(key,TreeGetRootValue(n)) != 0) {
        parent = n;
        if (*TreeGetRootValue(n)>*key) {
            son=0;
            n=TreeLeft(n);
        }
        else {
            son=1;
            n=TreeRight(n);
        }
    }

    bool flag=false;
    //caso 1 nodo è una foglia
    if (TreeIsLeaf(n)) {
        flag = true;
    }
    if (flag) {
        if (n==t) {
            ElemDelete(&n->value);
            free(n);
            return TreeCreateEmpty();
        }
        if (son==0) {
            parent->left= NULL;
        }
        else {
            parent->right=NULL;
        }
        ElemDelete(&n->value);
        free(n);
        return t;
    }

    // caso 2 — un solo figlio
    if (n->left != NULL && n->right == NULL) {
        if (n == t) {
            Node *tmp = n->left;
            ElemDelete(&n->value);
            free(n);
            return tmp;
        }
        if (son == 0) parent->left  = n->left;
        else          parent->right = n->left;
        ElemDelete(&n->value);
        free(n);
        return t;
    }
    else if (n->left == NULL && n->right != NULL) {
        if (n == t) {
            Node *tmp = n->right;
            ElemDelete(&n->value);
            free(n);
            return tmp;
        }
        if (son == 0) parent->left  = n->right;
        else          parent->right = n->right;
        ElemDelete(&n->value);
        free(n);
        return t;
    }

    //Caso 3 se il nodo ha due figli
    if (n->left != NULL && n->right != NULL) {
        Node *y          = n;
        Node *succ       = TreeLeft(n);  // parti da sinistra
        Node *succ_parent = y;           // padre del successore — inizia con y!

        while (!TreeIsEmpty(TreeRight(succ))) {
            succ_parent = succ;
            succ = TreeRight(succ);
        }
        // succ = successore, succ_parent = suo padre

        ElemSwap(&y->value, &succ->value);

        // stacca succ — può avere al massimo un figlio sinistro
        if (succ_parent == y)
            succ_parent->left  = TreeLeft(succ);  // succ era figlio sx di y
        else
            succ_parent->right = TreeLeft(succ);  // succ era figlio dx di succ_parent

        ElemDelete(&succ->value);
        free(succ);
        return t;
    }
    return n;
}
