#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algorytmy.h"

#define N 5
#define N_RANDOM 30

int main()
{
    int tab[N] = {0, 1, 2, 3, 4};
    int *tab_r = Tablica(N_RANDOM);
    int *tab_tmp= Tablica(N_RANDOM);

    printf("Tablica: ");
    drukujT(tab, 0, N);
    printf("\n");
    printf("2 jest pod indexem: %d \n", szukaj_binarne(tab, 2, 0, N));

    printf("\n\tSortowanie.\nTablica do posortowania: \n");
    losuj(tab_r, N_RANDOM, 50);
    drukujT(tab_r, 0, N_RANDOM);

    printf("\nsortowanie przez wstawianie, posortowana: \n");
    kopiujT(tab_tmp, tab_r, N_RANDOM);
    sortuj_wstawianie(tab_tmp, 0, N_RANDOM);
    drukujT(tab_tmp, 0, N_RANDOM);

    printf("\nsortowanie przez wstawianie, posortowana: \n");
    kopiujT(tab_tmp, tab_r, N_RANDOM);
    sortuj_wybieranie(tab_tmp, 0, N_RANDOM);
    drukujT(tab_tmp, 0, N_RANDOM);

    return (EXIT_SUCCESS);
}
