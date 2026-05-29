#ifndef VETTORE_H
#define VETTORE_H

#include <stdio.h>
#include "elemtype.h"

typedef struct {
    size_t capacity;
    size_t size;
    ElemType *data;
} Vector;

int VectorFind(const Vector *v, const ElemType *e);

#endif
