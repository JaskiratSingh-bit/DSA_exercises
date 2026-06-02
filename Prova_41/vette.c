#include "vette.h"
#include <limits.h>

bool MaggioreDiTutti(const Item *lista, ElemType curr) {
    while (lista!= NULL) {
        if (ElemCompare(&curr, &lista->value) <= 0) {
            return false;
        }
        lista = lista->next;
    }
    return true;
}

bool MaggioreDiPrecedenti(const Item *testa, const Item *nodo) {
    while (testa != nodo) {
        if (ElemCompare(&nodo->value, &testa->value) <= 0) {
            return false;
        }
        testa = testa->next;
    }
    return true;
}

extern int ContaVette(const Item *i) {
    if (ListIsEmpty(i)) return 0;

    ElemType fake_val = 0;

    // aggiungo INT_MIN in testa e in coda
    Item *lista = ListInsertHead(&fake_val, (Item*)i);
    lista = ListInsertBack(lista, &fake_val);

    int ris = 0;
    const Item *curr = ListGetTail(lista); // primo elemento vero, dopo il fake

    // mi fermo prima del fake in coda
    while (curr->next != NULL) {
        bool vettaPrec = MaggioreDiPrecedenti(lista, curr);
        bool vettaSuc = MaggioreDiTutti(curr->next, curr->value);

        if (vettaPrec || vettaSuc) ris++;

        curr = curr->next;
    }

    return ris;
}

Item *ListCreateFromVector(const ElemType *e, int e_size) {
    Item *n = ListCreateEmpty();
    for (int i = 0; i < e_size; ++i) {
        n = ListInsertBack(n, &e[i]);
    }
    return n;
}

int main(void) {
    ElemType e1[] = { 5,4 };
    ElemType e2[] = { 4, 5, 6 ,4,2};
    ElemType e3[] = { 7, 10, 9 };
    Item *list_1 = ListCreateFromVector(e1, sizeof(e1) / sizeof(ElemType));
    Item *list_2 = ListCreateFromVector(e2, sizeof(e2) / sizeof(ElemType));
    Item *list_3 = ListCreateFromVector(e3, sizeof(e3) / sizeof(ElemType));

    int ris =   ContaVette(list_2);
    printf("%d\n",ris);

    return 0;
}