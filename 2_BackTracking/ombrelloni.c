#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void OmbrelloniRec(int n, int k, bool *vcurr, int i, int *nsol) {

    if (i == n) {
        int cnt = 0;

        for (int j = 0; j < n; ++j) {
            if (vcurr[j]) cnt++;
        }

        bool valido = true;
        for (int p = 0; p < n - 1; ++p) {
            if (vcurr[p] == 1 && vcurr[p + 1] == 1) {
                valido = false;
                break;
            }
        }

        if (cnt == k && valido) {

            fprintf(stdout, "%4d) ", (*nsol) + 1);

            for (int p = 0; p < n; ++p) {
                fprintf(stdout, "%d ", vcurr[p]);
            }

            fprintf(stdout, "\n");
            (*nsol)++;
        }

        return;
    }

    vcurr[i] = 0;
    OmbrelloniRec(n, k, vcurr, i + 1, nsol);
    vcurr[i] = 1;
    OmbrelloniRec(n, k, vcurr, i + 1, nsol);
}

extern int Ombrelloni(int k, int n) {
    if (k < 0 || n < 0) {
        return 0;
    }
    if (n >= (k + 2)) {
        int nsol = 0;
        bool *vcurr = malloc(sizeof(bool) * n);
        OmbrelloniRec(n, k, vcurr, 0, &nsol);
        free(vcurr);
        return nsol;
    }
    return 0;
}