#include "list.h"
#include "elemtype.h"

const ElemType *MaxElement(const Item *i) {

    if (ListIsEmpty(i)) {
        return NULL;
    }

    const Item *tmp = i;
    const ElemType *max = &i->value;

    while (tmp != NULL) {
        if (ElemCompare(max, &tmp->value) < 0) {
            max = &tmp->value;
        }

        tmp = tmp->next;
    }


    const Item *tmp1 = i;
    while (tmp1 != NULL) {
        if (ElemCompare(max, &tmp1->value) == 0) {
            max = &tmp1->value;
            break;
        }
        tmp1 = tmp1->next;
    }


    return max;
}

/*int main(void) {
    ElemType v1[] = {3, 4, 2, 0, 45, 1, 3};
    size_t n1 = sizeof(v1) / sizeof(ElemType);

    Item *i1 = ListCreateEmpty();

    for (size_t i = 0; i < n1; ++i) {
        i1 = ListInsertBack(i1, &v1[i]);
    }

    printf("i1 = ");
    ListWriteStdout(i1);
    printf("\n");

    const ElemType *max = MaxElement(i1);

    if (max != NULL) {
        printf("%d\n", *max);
    }

    ListDelete(i1);

    return 0;
}

*/
