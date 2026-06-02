#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int StepsRec(int n, int somma, int *curr, size_t dim, int *nsol) {
    if (n == somma) {
        printf("[");
        for (size_t i = 0; i < dim-1; i++) {
            printf("%d,", curr[i]);
        }
        printf("%d],", curr[dim-1]);
        (*nsol)++;
        return *nsol;
    }
    // caso 1
    if (somma + 1 <= n) {
        int *tmp1 = malloc((dim+1)*sizeof(int));  // nuova memoria fresca
        memcpy(tmp1, curr, dim*sizeof(int));       // copio curr dentro tmp1
        tmp1[dim] = 1;                             // aggiungo il passo
        StepsRec(n, somma+1, tmp1, dim+1, nsol);
        free(tmp1);                                // libero dopo il ritorno
    }
    // caso 2
    if (somma + 2 <= n) {
        int *tmp2 = malloc((dim+1)*sizeof(int));
        memcpy(tmp2, curr, dim*sizeof(int));
        tmp2[dim] = 2;
        StepsRec(n, somma+2, tmp2, dim+1, nsol);
        free(tmp2);
    }
    // caso 3
    if (somma + 3 <= n) {
        int *tmp3 = malloc((dim+1)*sizeof(int));
        memcpy(tmp3, curr, dim*sizeof(int));
        tmp3[dim] = 3;
        StepsRec(n, somma+3, tmp3, dim+1, nsol);
        free(tmp3);
    }
}

extern int Steps(int n) {
    if (n <= 0) return 0;
    int *curr = malloc(1*sizeof(int));
    int result = 0;
    StepsRec(n, 0, curr, 0, &result);
    free(curr);
    return result;
}