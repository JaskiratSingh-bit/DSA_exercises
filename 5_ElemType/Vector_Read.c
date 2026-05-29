#include "Vector_Read.h"

Vector *VectorRead(const char *filename) {

    if (filename == NULL) {
        return NULL;
    }
    FILE *ptr = fopen(filename,"r");
    if (ptr == NULL) {
        return NULL;
    }

    Vector *vec = malloc(sizeof(Vector)*1);
    if (vec == NULL) {
        fclose(ptr);
        return NULL;
    }

    vec->capacity = 0;
    vec->size = 0;
    vec->data = NULL;

    ElemType e;
    while (ElemRead(ptr, &e) == 1) {
        if (vec->size == vec->capacity) {
            size_t new_capacity;

            if (vec->capacity == 0) {
                new_capacity = 1;
            } else {
                new_capacity = vec->capacity * 2;
            }

            ElemType *tmp = realloc(vec->data, new_capacity * sizeof(ElemType));

            if (tmp == NULL) {
                free(vec->data);
                free(vec);
                fclose(ptr);
                return NULL;
            }

            vec->data = tmp;
            vec->capacity = new_capacity;
        }

        vec->data[vec->size] = ElemCopy(&e);
        vec->size++;
    }

    fclose(ptr);
    return vec;
}


Vector *VectorReadSorted(const char *filename) {
    FILE *ptr = fopen(filename, "r");
    if (ptr == NULL) {
        return NULL;
    }

    Vector *vec = malloc(sizeof(Vector));
    if (vec == NULL) {
        fclose(ptr);
        return NULL;
    }

    vec->capacity = 0;
    vec->size = 0;
    vec->data = NULL;

    ElemType e;

    while (ElemRead(ptr, &e) == 1) {
        if (vec->size == vec->capacity) {
            size_t new_capacity;

            if (vec->capacity == 0) {
                new_capacity = 1;
            } else {
                new_capacity = vec->capacity * 2;
            }

            ElemType *tmp = realloc(vec->data, new_capacity * sizeof(ElemType));

            if (tmp == NULL) {
                free(vec->data);
                free(vec);
                fclose(ptr);
                return NULL;
            }

            vec->data = tmp;
            vec->capacity = new_capacity;
        }

        size_t pos = 0;

        while (pos < vec->size && ElemCompare(&vec->data[pos], &e) <= 0) {
            pos++;
        }

        for (size_t i = vec->size; i > pos; --i) {
            vec->data[i] = vec->data[i - 1];
        }

        vec->data[pos] = ElemCopy(&e);
        vec->size++;
    }

    fclose(ptr);
    return vec;
}