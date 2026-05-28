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

    int count = 0;
    int tmp = budget;
    for (size_t i=0;i<tagli_size;i++) {
       while((tmp/tagli[i]) >0) {
           tmp = tmp-tagli[i];
           count++;
           budget = budget - tagli[i];
       }
        res[i] = count;
        count =0;
        tmp = budget;
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
    printf("\n");

    return 0;
}