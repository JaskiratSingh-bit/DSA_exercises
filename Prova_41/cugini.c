#include "elemtype.h"
#include "tree.h"

const Node *TrovaPadre(const Node *n, const ElemType *key, const Node *padre) {
    if (TreeIsEmpty(n)) return NULL;  // non trovato

    // trovato! ritorna il padre
    if (ElemCompare(key, TreeGetRootValue(n)) == 0)
        return padre;

    // cerca a sinistra — padre diventa n
    const Node *sx = TrovaPadre(TreeLeft(n),  key, n);
    if (sx != NULL) return sx;

    // cerca a destra — padre diventa n
    return TrovaPadre(TreeRight(n), key, n);
}

int Pro_Node(const Node *n, const ElemType *key, int livello) {
    if (TreeIsEmpty(n)) return -1;  // non trovato

    // trovato! ritorna il livello attuale
    if (ElemCompare(key, TreeGetRootValue(n)) == 0)
        return livello;

    // cerca a sinistra — livello + 1
    int sx = Pro_Node(TreeLeft(n),  key, livello + 1);
    if (sx != -1) return sx;  // trovato a sinistra

    // cerca a destra — livello + 1
    return Pro_Node(TreeRight(n), key, livello + 1);
}


bool Cugini(const Node* t, int a, int b) {
    ElemType pro = 0;
    const Node *padre = t;
    // caso a
    pro = Pro_Node(t,&a,0);
    padre = TrovaPadre(t,&a,padre);
    ElemType pro2 = 0;
    const Node *padre2 = t;
    // caso b
    pro2 = Pro_Node(t,&b,0);
    padre2 = TrovaPadre(t,&b,padre2);

    if (pro != pro2) {
        return false;
    }
    else {
       if (padre->value != padre2->value) {
            return true;
        }
        else {
            return false;
        }
    }
}


/*int main(void)
{
        ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };
        Node* t = TreeCreateRoot(&e[10],
            TreeCreateRoot(&e[5],
                TreeCreateRoot(&e[3], NULL, NULL),
                TreeCreateRoot(&e[7], NULL, NULL)
                ),
            TreeCreateRoot(&e[15],
                TreeCreateRoot(&e[13], NULL, NULL),
                TreeCreateRoot(&e[18], NULL, NULL)
                ));

        int ris = Cugini(t,3,18);
        printf("%d \n",ris);
    return 0;
}*/