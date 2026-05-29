#include "list.h"
#include "elemtype.h"

Item *Intersect(const Item *i1, const Item *i2) {

    Item *list = ListCreateEmpty();
    const Item *tmp = i1;
    int flag = 0;
    while (tmp != NULL) {
        const Item *tmp1 = i2;
        while (tmp1 != NULL) {
            if (ElemCompare(&tmp->value, &tmp1->value) == 0) {
                flag = 1;
            }
            tmp1 = tmp1->next;
        }

        if (flag == 1) {
            list = ListInsertBack(list, &tmp->value);
        }
        flag = 0;
        tmp = tmp->next;
    }

    return list;
}


/*int main(void) {
    ElemType v1[] = {3, 4, 2, 0, 45, 1, 3};
    ElemType v2[] = {8, 5, 2, 3, 45, 7};

    size_t n1 = sizeof(v1) / sizeof(ElemType);
    size_t n2 = sizeof(v2) / sizeof(ElemType);

    Item *i1 = ListCreateEmpty();
    Item *i2 = ListCreateEmpty();

    for (size_t i = 0; i < n1; ++i) {
        i1 = ListInsertBack(i1, &v1[i]);
    }

    for (size_t i = 0; i < n2; ++i) {
        i2 = ListInsertBack(i2, &v2[i]);
    }

    printf("i1 = ");
    ListWriteStdout(i1);
    printf("\n");

    printf("i2 = ");
    ListWriteStdout(i2);
    printf("\n");

    Item *r = Intersect(i1, i2);

    printf("r  = ");
    ListWriteStdout(r);
    printf("\n");

    ListDelete(i1);
    ListDelete(i2);
    ListDelete(r);

    return 0;
}
*/