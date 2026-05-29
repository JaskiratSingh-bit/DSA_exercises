#include "vettore.h"

void VectorSort(Vector* v) {

    if (v == NULL) {
        return;
    }
    size_t tmp = v->size;
    while (tmp>0) {
        for (size_t i=0;i<tmp-1;i++) {
            if (ElemCompare(&v->data[i],&v->data[i+1])>0) {
                ElemSwap(&v->data[i],&v->data[i+1]);
            }
        }
        tmp--;
    }
    return;
}

/*int main(void) {

    Vector v ;
    v.size = 10;
    v.capacity = 10;

    ElemType vet[] = { 4, 34, 12, -2, 3, 4, 5, 1, 3, 4 };
    v.data = vet;


    VectorSort(&v);
    ElemType y ;
    for (y=0;y<v.size;y++) {
        ElemWriteStdout(&vet[y]);
    }


    return 0;
}*/