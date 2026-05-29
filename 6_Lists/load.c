#include <complex.h>

#include "list.h"

Item *ListLoad(const char *filename) {

    FILE *f = fopen(filename,"r");
    if (f == NULL) {
        Item *list = ListCreateEmpty();
        return  list;
    }

    Item *list = ListCreateEmpty();

    ElemType1 num = 0;
    while (fscanf(f,"%d",&num) != EOF) {
       list = ListInsertHead(&num,list);
    }

    fclose(f);
    return list;
}

int main(void) {

    Item *list = ListLoad("data_00.txt");
    ListWriteStdout(list);
    printf("\n");

    return 0;
}