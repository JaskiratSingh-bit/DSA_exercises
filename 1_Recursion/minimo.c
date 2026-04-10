#include <stdio.h>
#include <stdlib.h>

static int MinimoRec(const int *v, int v_size, int i) {
    if (v_size - 1 == i) {
        return v[i];
    }

    int min = MinimoRec(v, v_size, i + 1);
    if (v[i] < min) {
        return v[i];
    } else {
        return min;
    }
}

int Minimo(const int *v, int v_size) {
    int i = 0;
    return MinimoRec(v, v_size, i);
}

/*int main(void) {
    int v[] = {2, 3, 4, 1, 5};
    int size = 5;
    int min = Minimo(v, size);

    printf("Minimo: %d\n", min);

    return 0;
}*/