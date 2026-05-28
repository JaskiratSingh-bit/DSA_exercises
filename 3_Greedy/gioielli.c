#include "gioielli.h"

Gioiello *CompraGioielli(const char *filename, float budget, size_t *ret_size) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) return NULL;

    *ret_size = 0;
    Gioiello g;
    size_t size = 0;
    Gioiello *ptr = malloc(sizeof(Gioiello));

    // 1) leggi tutti i gioielli
    while (fscanf(f, "%d %f %f", &g.codice, &g.peso, &g.prezzo) == 3) {
        ptr = realloc(ptr, (size + 1) * sizeof(Gioiello)); // usa size!
        ptr[size] = g;
        size++;
    }
    fclose(f);

    // 2) ordina per peso/prezzo decrescente (appetibilità)
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - 1 - i; j++) {
            float ra = ptr[j].peso   / ptr[j].prezzo;
            float rb = ptr[j+1].peso / ptr[j+1].prezzo;
            if (ra < rb) {
                Gioiello tmp = ptr[j];
                ptr[j]   = ptr[j+1];
                ptr[j+1] = tmp;
            }
        }
    }

    // 3) selezione greedy
    Gioiello *ptr1 = malloc(sizeof(Gioiello));
    for (size_t i = 0; i < size; i++) {       // size, non size-1
        if (ptr[i].prezzo <= budget) {
            ptr1 = realloc(ptr1, (*ret_size + 1) * sizeof(Gioiello));
            ptr1[*ret_size] = ptr[i];           // *ret_size come indice
            (*ret_size)++;                       // parentesi!
            budget -= ptr[i].prezzo;
        }
    }

    free(ptr);    // libera il temporaneo
    return ptr1;  // ritorna quello selezionato
}

int main(void) {
    size_t n=0;
    Gioiello *vet = CompraGioielli("gioielli_1.txt",125,&n);
    for (int i = 0; i<n;i++) {
        // ✅ devi stampare i singoli campi
        printf("%d %f %f\n", vet[i].codice, vet[i].peso, vet[i].prezzo);
    }
    free(vet);
    return 0;
}



//la logica dietro l'aapetibilità insomma è :
/*
* Immagina che sei al mercato con 121€ in tasca. Ci sono 3 gioielli:
GioielloPesoPrezzoG112g100€G210g21€G325g120€
L'obiettivo è portare a casa il massimo peso possibile senza sforare il budget.

La domanda che ti fai per ogni gioiello è:

"Quanti grammi mi dà questo gioiello per ogni euro che spendo?"

Questo è l'appetibilità — cioè il rapporto peso/prezzo. Più è alto, meglio è.
G1: 12 / 100 = 0.12 g per euro   ← pessimo affare
G2: 10 / 21  = 0.47 g per euro   ← ottimo affare
G3: 25 / 120 = 0.20 g per euro   ← medio
Quindi l'ordine greedy è: G2 → G3 → G1

Ora applichi la logica greedy: prendi dall'inizio finché hai soldi.
Budget: 121€

Prendo G2 (21€) → mi rimangono 100€, peso accumulato 10g
Prendo G3 (120€) → costa troppo, skip
Prendo G1 (100€) → mi rimangono 0€, peso accumulato 22g

Risultato: G2 + G1 = 22g con 121€
Senza l'appetibilità avresti preso G1 per primo (100€), poi ti sarebbero rimasti 21€
— prendi G2 ma il peso è sempre 22g... ok in questo caso viene uguale, ma con più gioielli l'ordine cambia tutto.

Quindi in una frase sola:

L'appetibilità è il criterio con cui dici "questo gioiello vale la pena più di quell'altro" —
e il greedy prende sempre quello che vale di più prima.

 */