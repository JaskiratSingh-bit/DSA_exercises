#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>

// conta i nodi
int ContaNodi(const Node *n) {
    if (TreeIsEmpty(n)) return 0;
    return 1 + ContaNodi(TreeLeft(n)) + ContaNodi(TreeRight(n));
}

void VetSx(const Node *n, ElemType *vet, size_t *dim) {
    if (TreeIsEmpty(n)) return;
    vet[(*dim)] = *TreeGetRootValue(n);
    (*dim)++;
    VetSx(TreeLeft(n),  vet, dim);
    VetSx(TreeRight(n), vet, dim);
}

void VetDx(const Node *n, ElemType *vet, size_t *dim) {
    if (TreeIsEmpty(n)) return;
    vet[(*dim)] = *TreeGetRootValue(n);
    (*dim)++;
    VetDx(TreeRight(n), vet, dim);  // destra prima!
    VetDx(TreeLeft(n),  vet, dim);  // sinistra dopo!
}

extern bool TreeIsMirror(const Node *t) {
    if (TreeIsEmpty(t)) return true;
    if (TreeIsLeaf(t))  return true;

    if (TreeIsEmpty(TreeLeft(t)) && !TreeIsEmpty(TreeRight(t))) return false;
    if (!TreeIsEmpty(TreeLeft(t)) && TreeIsEmpty(TreeRight(t))) return false;

    // conta i nodi di sx e dx
    int n_sx = ContaNodi(TreeLeft(t));
    int n_dx = ContaNodi(TreeRight(t));

    // se dimensioni diverse → non specchio
    if (n_sx != n_dx) return false;

    // alloca vettori della dimensione giusta
    ElemType *vet_sx = malloc(n_sx * sizeof(ElemType));
    ElemType *vet_dx = malloc(n_dx * sizeof(ElemType));

    size_t dim_sx = 0;
    size_t dim_dx = 0;

    VetSx(TreeLeft(t),  vet_sx, &dim_sx);
    VetDx(TreeRight(t), vet_dx, &dim_dx);

    // confronta i due vettori
    bool risultato = true;
    for (size_t i = 0; i < dim_sx; i++) {
        if (vet_sx[i] != vet_dx[i]) {
            risultato = false;
            break;
        }
    }

    free(vet_sx);
    free(vet_dx);
    return risultato;
}