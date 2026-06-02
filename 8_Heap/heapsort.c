#include "elemtype.h"
#include "minheap.h"
#include "stdlib.h"


extern void HeapMinHeapsort(Heap *h) {

    // salvo la dimensione originale per ripristinarla alla fine
    size_t dimensione_originale = h->size;

    while (h->size >= 2) {

        // scambia la radice (minimo corrente) con l'ultimo elemento
        ElemSwap(HeapGetNodeValue(h, 0),
                 HeapGetNodeValue(h, h->size - 1));

        // l'ultimo e' ora "congelato": non fa piu' parte dell'heap
        h->size--;

        // ripristina la proprieta' heap sulla nuova radice
        HeapMinMoveDown(h, 0);
    }

    // ripristina la dimensione originale
    // (i dati ci sono ancora, solo ordinati in modo decrescente)
    h->size = dimensione_originale;


}


/*Perché h->size >= 2
Il ciclo continua finché nell'heap ci sono almeno 2 elementi. Se c'è un solo elemento non c'è niente da scambiare — è già al posto giusto.
Con un elemento solo il while non parte nemmeno.

Cosa succede dentro, passo per passo
Partiamo da questo min-heap con 4 elementi: [1, 3, 2, 4]. Size = 4.

Giro 1 — size = 4
cElemSwap(pos 0, pos 3)  // scambia 1 con 4
Array diventa: [4, 3, 2, 1]
ch->size--   // size diventa 3
L'heap ora "vede" solo [4, 3, 2]. L'1 in fondo è congelato — non fa più parte dell'heap.
cHeapMinMoveDown(h, 0)   // 4 è troppo grande per la radice, scende
Array diventa: [2, 3, 4, | 1]. Il 4 è sceso, il 2 è salito in cima.

Giro 2 — size = 3
cElemSwap(pos 0, pos 2)  // scambia 2 con 4
Array: [4, 3, 2, | 1]
ch->size--   // size diventa 2
L'heap vede solo [4, 3]. Il 2 è congelato.
cHeapMinMoveDown(h, 0)   // 4 > 3, scende
Array: [3, 4, | 2, 1]

Giro 3 — size = 2
cElemSwap(pos 0, pos 1)  // scambia 3 con 4
Array: [4, 3, | 2, 1]
ch->size--   // size diventa 1
L'heap vede solo [4]. Il 3 è congelato.
cHeapMinMoveDown(h, 0)   // un solo nodo, non fa niente
Ora size = 1, il while si ferma.
Array finale: [4, 3, 2, 1] → decrescente ✓*/