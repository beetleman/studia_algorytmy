#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algorytmy.h"

#define N 5
#define N_RANDOM 11

int main()
{
    int i, j;
    int tab[N] = {0, 1, 2, 3, 4};
    int **macierz = Macierz(2, N);
    int *tab_ptr;
    int *tab_r = Tablica(N_RANDOM);
    int *tab_tmp= Tablica(N_RANDOM);

    for (i = 0; i < 2; i++) {
        for (j = 0; j < N; j++) {
            macierz[i][j] = i+j;
        }
    }


    printf("\tMnorzenie wektorow: ");
    printf("\nm = \n");
    drukujM(macierz, 0, N, 2);
    printf("\nw = ");
    drukujT(tab, 0, N);
    printf("\nm x w = ");
    tab_ptr = mnorzenie_m_w(macierz, tab, 2, N);
    drukujT(tab_ptr, 0, 2);

    printf("\n\n\tTablica: ");
    drukujT(tab, 0, N);
    printf("\n");
    printf("2 jest pod indexem: %d \n", szukaj_binarne(tab, 2, 0, N));

    printf("\n\tSortowanie.\nTablica do posortowania: \n");
    losuj(tab_r, N_RANDOM, 50);
    drukujT(tab_r, 0, N_RANDOM);

    printf("\nsortowanie przez wstawianie: \n");
    kopiujT(tab_tmp, tab_r, N_RANDOM);
    sortuj_wstawianie(tab_tmp, 0, N_RANDOM);
    drukujT(tab_tmp, 0, N_RANDOM);

    printf("\nsortowanie przez wybieranie: \n");
    kopiujT(tab_tmp, tab_r, N_RANDOM);
    sortuj_wybieranie(tab_tmp, 0, N_RANDOM);
    drukujT(tab_tmp, 0, N_RANDOM);
    printf("\n");

    printf("\nsortowanie przez scalanie: \n");
    kopiujT(tab_tmp, tab_r, N_RANDOM);
    sortuj_scalanie(tab_tmp, 0, N_RANDOM);
    drukujT(tab_tmp, 0, N_RANDOM);
    printf("\n");


    return (EXIT_SUCCESS);
}
