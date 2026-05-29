#ifndef VETTORE_H
#define VETTORE_H

#include "elemtype.h"
#include <stdlib.h>

typedef struct {
    size_t capacity;
    size_t size;
    ElemType *data;
} Vector;


Vector *VectorRead(const char *filename);
Vector *VectorReadSorted(const char *filename);

#endif