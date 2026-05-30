#include <string.h>
#include "list.h"
#include <stdlib.h>

extern const ElemType *Find(const Item *i, const char *name) {

    ElemType *nome=malloc(sizeof(ElemType));
    strcpy(nome->name,name);

    const Item *tmp = i;
    while (tmp != NULL) {
        if (ElemCompare(&tmp->value,nome) == 0) {
            free(nome);
            return &tmp->value ;
        }
        tmp = tmp->next;
    }

    free(nome);
    return NULL;
}

Item *Delete(Item *i, const char *name) {
    if (ListIsEmpty(i)) {
        return i;
    }

    Item fake_head;
    fake_head.next = i;

    Item *pre = &fake_head;
    Item *curr = i;

    while (curr != NULL) {
        if (strcmp(curr->value.name, name) == 0) {
            pre->next = curr->next;
            ElemDelete(&curr->value);
            free(curr);
            break;
        }

        pre = curr;
        curr = curr->next;
    }

    return fake_head.next;
}

int ListLen(const Item *i,int len) {
    if (ListIsEmpty(i)) {
        return len;
    }
    return ListLen(ListGetTail(i),len+1);
}


extern Item *SortV(Item *i) {
    if (ListIsEmpty(i)) return i;

    int len = ListLen(i, 0);

    for (int pass = 0; pass < len-1; pass++) {
        Item *curr = i;           // ← riparte dall'inizio ad ogni passata
        Item *suc = i->next;

        for (int y = 0; y < len-1-pass; y++) {
            if (ElemCompare(&curr->value, &suc->value) > 0) {
                ElemSwap(&curr->value, &suc->value);
            }
            curr = suc;           // ← avanza dentro il for
            suc = suc->next;
        }
    }
    return i;
}

extern Item *Sort(Item *i) {
    if (ListIsEmpty(i)) return i;

    Item fake_head;
    fake_head.next = i;

    int len = ListLen(i, 0);

    for (int pass = 0; pass < len-1; pass++) {
        Item *prev = &fake_head;
        Item *curr = prev->next;
        Item *suc = curr->next;

        for (int y = 0; y < len-1-pass; y++) {
            if (ElemCompare(&curr->value, &suc->value) > 0) {
                // cambia le 3 frecce
                prev->next = suc;
                curr->next = suc->next;
                suc->next = curr;
                // aggiorna prev (curr è già ok)
                prev = suc;
            } else {
                // nessuno swap, avanza normalmente
                prev = curr;
                curr = suc;
            }
            suc = curr->next;
        }
    }

    return fake_head.next;
}

Item *Filtra(const Item *i, const char *city) {
    if (ListIsEmpty(i)) {
        Item *y = ListCreateEmpty();
        return y;
    }

    const Item *tmp = i;

    Item *l = ListCreateEmpty();

    while (tmp != NULL) {
        if (strcmp(tmp->value.city,city)==0) {
            l = ListInsertBack(l,&tmp->value);
        }
        tmp= tmp->next;
    }

    return l;
}

Item *Reverse(const Item *i) {
    if (ListIsEmpty(i)) {
        Item *y = ListCreateEmpty();
        return y;
    }

    Item *ret = ListCreateEmpty();
    const Item *tmp = i;

    while (tmp != NULL) {
        ret = ListInsertHead(&tmp->value,ret);
        tmp = tmp->next;
    }
    return ret;
}


Item *Append(const Item *i1, const Item *i2) {

    const Item *tmp = i1;
    const Item *tmp1 = i2;

    Item *ls = ListCreateEmpty();

    while (tmp != NULL){
        ls = ListInsertBack(ls,&tmp->value);
        tmp = tmp->next;
    }
    while (tmp1 != NULL){
        ls = ListInsertBack(ls,&tmp1->value);
        tmp1 = tmp1->next;
    }

    return ls;
}


Item *AppendMod(Item *i1, Item *i2) {
    if (ListIsEmpty(i1)) return i2;  // caso particolare

    Item *tmp = i1;
    while (tmp->next != NULL) {  // ← vai fino all'ultimo nodo
        tmp = tmp->next;
    }
    tmp->next = i2;  // ← l'ultimo nodo punta a i2
    return i1;
}


/*
int main(void) {
    Item *list = ListCreateEmpty();

    ElemType a1 = {
        "Mario Rossi",
        "Via Roma",
        10,
        "Milano",
        "MI",
        "20100"
    };

    ElemType a2 = {
        "Luca Bianchi",
        "Corso Italia",
        25,
        "Torino",
        "TO",
        "10100"
    };

    ElemType a3 = {
        "Anna Verdi",
        "Via Garibaldi",
        7,
        "Bologna",
        "BO",
        "40100"
    };

    ElemType a4 = {
        "Mario Rossi",
        "Via Dante",
        15,
        "Roma",
        "RM",
        "00100"
    };

    list = ListInsertBack(list, &a1);
    list = ListInsertBack(list, &a2);
    list = ListInsertBack(list, &a3);
    list = ListInsertBack(list, &a4);


   // invece di fare cosi si puo usare la funzione da olj documentazione listformvector

    //const ElemType *found = Find(list, "Mario Rossi");
   // list = Delete(list, "Mario Rossi");


    list = SortN(list);

    //printf("%s\n",found->name);
    //printf("%s\n",found->street);
    //printf("%d\n",found->number);
    //printf("%s\n",found->city);
    //printf("%s\n",found->postal_code);
    //printf("%s\n",found->province);

    ListWriteStdout(list);


    ListDelete(list);

    return 0;
}*/