#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void TiroAllaFuneRec(int *vet, int dim, bool *vcurr,bool *vbest, int i, int scelti, int k,int *min) {
    if (scelti == k) {
        for (int j = i; j < dim; j++) {
            vcurr[j] = false;
        }

        int somma1 = 0, somma2 = 0;

        for (int j = 0; j < dim; j++) {
            if (vcurr[j]) {
                somma1 += vet[j];
            } else {
                somma2 += vet[j];
            }
        }

        int da = abs(somma1 - somma2);

        if (da < *min) {
            *min = da;
            for (int j = 0; j < dim; j++) {
                vbest[j] = vcurr[j];
            }
        }

        return;
    }

    if (i == dim) {
        return;
    }

    for (int j = 0; j < 2; j++) {
        vcurr[i] = j;

        if (j == 1) {
            TiroAllaFuneRec(vet, dim, vcurr,vbest, i + 1, scelti + 1, k,min);
        } else {
            TiroAllaFuneRec(vet, dim, vcurr,vbest, i + 1, scelti, k,min);
        }
    }
}


void TiroAllaFune(int *vet,int dim) {
    bool *vcurr = calloc(dim,sizeof(bool));
    if (vcurr == NULL) {
        return;
    }

    bool *vbest = calloc(dim,sizeof(bool));
    if (vbest == NULL) {
        return;
    }
    int min = INT_MAX;
    TiroAllaFuneRec(vet,dim,vcurr,vbest,0,0,dim/2,&min);

    printf("\n{");
    bool first = true;
    for (int j = 0; j < dim; j++) {
        if (vbest[j]) {
            if (!first) {
                printf(", ");
            }
            printf("%d", vet[j]);
            first = false;
        }
    }
    printf("},{");

    first = true;
    for (int j = 0; j < dim; j++) {
        if (!vbest[j]) {
            if (!first) {
                printf(", ");
            }
            printf("%d", vet[j]);
            first = false;
        }
    }
    printf("}");

    free(vcurr);
    free(vbest);
}

int main(int argc, char **argv) {
    int dim = argc - 1;

    int *vet = malloc(dim * sizeof(int));
    if (vet == NULL) {
        return -1;
    }

    for (int i = 0; i < dim; i++) {
        char *ptr;
        int num = strtol(argv[i + 1], &ptr, 10);

        if (*ptr != '\0') {
            free(vet);
            return -1;
        }

        vet[i] = num;
    }

    for (int j = 0; j < dim; j++) {
        printf("%d ", vet[j]);
    }

    TiroAllaFune(vet,dim);

    free(vet);
    return 0;
}