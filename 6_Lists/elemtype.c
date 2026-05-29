#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"

#include <string.h>
#include <stdlib.h>

#define _unused(x) ((void)(x))

int ElemCompare(const ElemType *e1, const ElemType *e2) {

    int ris = strcmp(e1->name,e2->name);
    return ris;
}

ElemType ElemCopy(const ElemType *e) {

/*
    ElemType new_e = *e;
    return new_e;
*/ // insomma fa la stessa cosa di questa roba di retun sotto

    return *e;
}

void ElemSwap(ElemType *e1, ElemType *e2) {
    ElemType tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
} // Questa bestia non cambia mai

void ElemDelete(ElemType *e) { // non c'è ninete di dinamico quindi non cambia mai
    // In questo caso la funzione ElemDelete non deve fare nulla, ma il 
    // compilatore potrebbe segnalare il mancato utilizzo di e, come warning
    // o come errore. Utilizzando la macro _unused sopra definita eliminiamo
    // questo problema.
    _unused(e);
}

int ElemRead(FILE *f, ElemType *e) {
    return fscanf(f, " %39[^\n] %49[^\n] %d %29[^\n] %2s %5s",
                  e->name, e->street, &e->number,
                  e->city, e->province, e->postal_code);
}

int ElemReadStdin(ElemType *e) {
    return ElemRead(stdin, e);
}

void ElemWrite(const ElemType *e, FILE *f) {
    fprintf(f, "%s, %s %d, %s (%s) %s",
            e->name, e->street, e->number,
            e->city, e->province, e->postal_code);
}

void ElemWriteStdout(const ElemType *e) {
    ElemWrite(e, stdout);
}
