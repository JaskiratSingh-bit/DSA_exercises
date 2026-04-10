#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int DivisioneRec(int a, int b, const int c) {
    if (a == b) {
        return 1;
    }
    else if (a < b) {
        return 0;
    }
    return 1 + DivisioneRec(a, b + c, c);
}

int DivisioneNegativi(int a, int b) {
    if (b == 0) {
        return INT_MAX;
    }
    if (a == 0) {
        return 0;
    }

    int con_a = b;

    if (a < 0 && b < 0) {
        return DivisioneRec(abs(a), abs(b), abs(con_a));
    }
    else if (a < 0 || b < 0) {
        return -DivisioneRec(abs(a), abs(b), abs(con_a));
    }
    else {
        return DivisioneRec(abs(a), abs(b), abs(con_a));
    }
}