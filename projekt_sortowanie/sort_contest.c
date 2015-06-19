#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algorytmy.h"
#include "sort_contest.h"
#include "timer_lib.h"


int *check_sort(void (*sortuj)(int [], int, int),
                int *tab, int *tab_ref, int size, int last, FILE * fp)
{
    int *tab_tmp = Tablica(size);

    kopiujT(tab_tmp, tab, size);

    start_timer();
    (*sortuj)(tab_tmp, 0, size);
    fprintf(fp, "%f", stop_timer());
    if(last)
        fprintf(fp, "\n");
    else
        fprintf(fp, ", ");

    if(tab_ref != NULL && !porownajT(tab_tmp, tab_ref, 0, size)){
        return NULL;
    }

    return tab_tmp;
}


int strike(int tab[], int size, FILE * fp)
{
    int *tab_ref = Tablica(size);

    /* tablica z losowymi danymi */
    tab_ref = check_sort(&sortuj_wstawianie, tab, NULL, size, 0, fp);

    if(!(check_sort(&sortuj_wybieranie, tab, tab_ref, size, 0, fp) &&
         check_sort(&sortuj_scalanie, tab, tab_ref, size, 0, fp) &&
         check_sort(&sortuj_szybkie, tab, tab_ref, size, 0, fp) &&
         check_sort(&sortuj_szybkie_rand_piwot, tab, tab_ref, size, 1, fp))
        )
        return 0;
    return 1;
}


int fight(int size, FILE * fp_random, FILE * fp_sorted, FILE * fp_reverse_sorted)
{
    int *tab = Tablica(size);
    int i;
    losuj(tab, size, size);

    fprintf(fp_random, "%d, ", size);
    fprintf(fp_sorted, "%d, ", size);
    fprintf(fp_reverse_sorted, "%d, ", size);

    /* tablica z losowymi danymi */
    if(!strike(tab, size, fp_random))
        return 1;

    /* tablica uporzadkowana */
    for (i = 0; i < size; i++) {
        tab[i] = i;
    }
    if(!strike(tab, size, fp_sorted))
        return 1;

    /* tablica odrwortnie uporzadkowana */
    for (i = 0; i < size; i++) {
        tab[i] = size - i;
    }
    if(!strike(tab, size, fp_reverse_sorted))
        return 1;
    return 1;
}

int start_contest(FILE * fp_random, FILE * fp_sorted, FILE * fp_reverse_sorted)
{
    int size;

    fprintf(fp_random, TABLE_HEADER);
    fprintf(fp_sorted, TABLE_HEADER);
    fprintf(fp_reverse_sorted, TABLE_HEADER);

    for (size = FROM; size < TO; size = size + STEP) {
        if(!fight(size, fp_random, fp_sorted, fp_reverse_sorted)){
            fprintf(stderr, "\nZle!!, jeden z algorytmow inaczej sortuje!\n");
            return (EXIT_FAILURE);
        }
        printf("Wykonano..... %.2f%%\n", ((float) size/TO) * 100 );
    }
    printf("Wykonano..... 100.00%%\n");

    return (EXIT_SUCCESS);
}
