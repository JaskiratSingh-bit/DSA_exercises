#include "elemtype.h"
#include "maxheap.h"

ElemType max_h(Heap *h) {
    ElemType max = h->data[0];
    h->data[0] = h->data[h->size-1];
    ElemDelete(&h->data[h->size-1]);
    h->size--;
    HeapMaxMoveDown(h,0);
    return max;
}

extern int LastStoneWeight(Heap *h) {
    while (h->size >1) {
        ElemType max = max_h(h);
        ElemType max_2 = max_h(h);
        if (max != max_2) {
            ElemType sub= max - max_2;
            HeapMaxInsertNode(h,&sub);
        }
    }
    if (HeapIsEmpty(h)) {
        return 0;
    }

    return h->data[0];
}