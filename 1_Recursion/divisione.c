#include <stdio.h>
#include <stdlib.h>

static int DivisioneRec(int a, int b, const int c) {
    if (a == b) {
        return 1;
    }
    else if (a < b) {
        return 0;
    }
    return 1 + DivisioneRec(a, b + c, c);
}

int Divisione(int a, int b) {
    if (a < 0 || b <= 0) {
        return -1;
    }
    if (a == 0 || a < b) {
        return 0;
    }
    int con_a = b;
    return DivisioneRec(a, b, con_a);
}