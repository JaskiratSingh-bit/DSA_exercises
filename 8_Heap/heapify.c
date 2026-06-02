#include "elemtype.h"
#include "minheap.h"
#include "stdlib.h"

extern Heap *HeapMinHeapify(const ElemType *v, size_t v_size) {
    // Creo heap vuoto
    Heap *h = HeapCreateEmpty();

    // Se il vettore è vuoto restituisco heap vuoto
    if (v_size == 0) {
        return h;
    }

    // Copio tutti gli elementi del vettore nell'heap
    h->size = v_size;
    h->data = malloc(sizeof(ElemType) * v_size);
    for (size_t i = 0; i < v_size; i++) {
        h->data[i] = ElemCopy(&v[i]);
    }

    int i = v_size/2-1;
    while (i>0) {
        HeapMinMoveDown(h,i);
        i--;
    }

    return h;
}