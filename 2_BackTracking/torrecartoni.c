#include "torrecartoni.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void TorreCartoniRec(const Cartone *c, int n, int i, int k, bool *used, Torre *t,Torre *tbest) {

    if (t->alt>tbest->alt) {
        tbest->peso = t->peso;
        tbest->size = t->size;
        tbest->alt = t->alt;
        memcpy(tbest->ids,t->ids,t->size * sizeof(int));
    }

    if (i == k) {
        return;
    }

    for (int j = 0; j < k; j++) {
        if (!used[j]) {
            if (c[j].l>=(unsigned int)t->peso) {
                used[j] = true;
                t->ids[t->size] = j;
                t->size++;
                t->peso = t->peso+c[j].p;
                t->alt = t->alt+c[j].a;
                TorreCartoniRec(c, n, i + 1, k, used, t,tbest);

                t->size--;
                t->peso = t->peso-c[j].p;
                t->alt = t->alt-c[j].a;
                used[j] = false;
            }
        }
    }
}

extern void TorreCartoni(const Cartone *c, size_t n) {
    bool *used = calloc(n, sizeof(bool));
    if (used == NULL) {
        return;
    }

    Torre *t = malloc(sizeof(Torre));
    if (t == NULL) {
        free(used);
        return;
    }

    t->ids = malloc(n * sizeof(int));
    if (t->ids == NULL) {
        free(used);
        free(t);
        return;
    }

    Torre *tbest = malloc(sizeof(Torre));
    if (tbest == NULL) {
        free(t->ids);
        free(used);
        free(t);
        return;
    }

    tbest->ids = malloc(n * sizeof(int));
    if (tbest->ids == NULL) {
        free(t->ids);
        free(used);
        free(t);
        return;
    }

    t->size = 0;
    t->peso = 0;
    t->alt = 0;
    tbest->size = 0;
    tbest->peso = 0;
    tbest->alt = 0;
    TorreCartoniRec(c, (int)n, 0, (int)n, used, t,tbest);

    for (int j = 0;j<tbest->size;j++) {
        printf("%d\n",tbest->ids[j]);
    }
    printf("Altezza: %d cm\n", tbest->alt);

    free(t->ids);
    free(tbest->ids);
    free(tbest);
    free(t);
    free(used);
}


/*int main(void) {
    Cartone c[3] = {
        {.p= 25,.a= 20,.l= 40},
        {.p= 10,.a= 10,.l= 12},
        {.p=  9,.a=  3,.l=  5}
    };

    TorreCartoni(c, 3);

    return 0;
}*/