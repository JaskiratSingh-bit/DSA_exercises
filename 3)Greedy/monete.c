#include <stdio.h>
#include <stdlib.h>


extern int *Monete(const int *tagli, size_t tagli_size, int budget) {
    if (budget <= 0) {
        return NULL;
    }

    int *res = calloc(tagli_size,sizeof(int));
    if (res == NULL) {
        return NULL;
    }

    for (size_t i=0;i<tagli_size;i++) {
        res[i] = budget/tagli[i];
        budget = budget%tagli[i];
    }

    return res;
}


int main(void) {

    int tagli[] = {50,20,10,5,2,1};
    int *res = Monete(tagli,6,126);
    for (size_t i =0;i<6;i++) {
        printf("%d ",res[i]);
    }
    free(res);

    return 0;
}