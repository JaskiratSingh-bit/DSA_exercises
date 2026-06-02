#include "elemtype.h"
#include "minheap.h"
#include "stdlib.h"

extern bool HeapMinPop(Heap *h, ElemType *e) {
    if (HeapIsEmpty(h)) {
        return false;
    }

    *e = ElemCopy(HeapGetNodeValue(h,0));
    h->data[0] = h->data[h->size-1];
    ElemDelete(&h->data[h->size-1]);
    h->size = h->size-1;
    int i = 0;
    HeapMinMoveDown(h,i);
    return true;

}
