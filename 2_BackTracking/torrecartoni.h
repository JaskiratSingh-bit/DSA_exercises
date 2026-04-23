#ifndef TORRECARTONI_H
#define TORRECARTONI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    unsigned p; // Peso
    unsigned a; // Altezza
    unsigned l; // Limite
} Cartone;

typedef struct {
    int *ids;
    int size;
    int peso;
    int alt;
} Torre;

extern void TorreCartoni(const Cartone *c, size_t n);

#endif //TORRECARTONI_H
