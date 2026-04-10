#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void BabboNataleRec(const int* pacchi, size_t pacchi_size, bool *vcurr, bool *vcurr_best, int i, int p, int *solmil, int peso, int cnt) {
    if (peso > p) {
        return;
    }
    if (i == (int)pacchi_size) {

        if (cnt > (*solmil)) {
            (*solmil) = cnt;
            for (int j = 0; j < (int)pacchi_size; ++j) {
                vcurr_best[j] = vcurr[j];
            }
        }
        return;
    }

    vcurr[i] = 0;
    BabboNataleRec(pacchi, pacchi_size, vcurr, vcurr_best, i + 1, p, solmil, peso, cnt);

    vcurr[i] = 1;
    BabboNataleRec(pacchi, pacchi_size, vcurr, vcurr_best, i + 1, p, solmil, peso + (pacchi[i]), cnt + 1);
}

extern void BabboNatale(const int *pacchi, size_t pacchi_size, int p) {
    bool *vcurr = malloc(sizeof(bool) * pacchi_size);
    if (vcurr == NULL) {
        return;
    }

    bool *vcurr_best = malloc(sizeof(bool) * pacchi_size);
    if (vcurr_best == NULL) {
        return;
    }

    int milsol = 0;

    BabboNataleRec(pacchi, pacchi_size, vcurr, vcurr_best, 0, p, &milsol, 0, 0);

    for (int j = 0; j < (int)pacchi_size; ++j) {
        fprintf(stdout, "%d ", vcurr_best[j]);
    }

    free(vcurr);
    free(vcurr_best);
}