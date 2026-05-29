#include "Vector_Find.h"

int VectorFind(const Vector *v, const ElemType *e) {

    if (v==NULL) {
        return -1;
    }

    for (size_t i=0;i<v->size;i++) {
        if (ElemCompare(&v->data[i],e) == 0) {
            return i;
        }
    }
    return -1;
}