#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int ProdottoRec(int a, int b) {
    if (b == 1) {
        return a;
    }
    return a + ProdottoRec(a, b - 1);
}

int ProdottoNegativi(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a < 0 && b < 0) {
        return ProdottoRec(abs(a), abs(b));
    }
    else if (a < 0 || b < 0) {
        return -ProdottoRec(abs(a), abs(b));
    }
    return ProdottoRec(a, b);
}