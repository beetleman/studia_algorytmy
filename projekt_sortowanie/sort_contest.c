#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algorytmy.h"
#include "sort_contest.h"
#include "timer_lib.h"


int * check_sort(void (*sortuj)(int [], int, int),
                int *tab, int *tab_ref, int size){
    int *tab_tmp = Tablica(size);
    kopiujT(tab_tmp, tab, size);

    start_timer();
    (*sortuj)(tab_tmp, 0, size);
    printf("%f, ", stop_timer());

    if(tab_ref != NULL && !porownajT(tab_tmp, tab_ref, 0, size)){
        return NULL;
    }

    return tab_tmp;
}


int strike(int tab[], int size){
    int *tab_ref = Tablica(size);

    /* tablica z losowymi danymi */
    tab_ref = check_sort(&sortuj_wstawianie, tab, NULL, size);

    if(!(check_sort(&sortuj_wybieranie, tab, tab_ref, size) &&
         check_sort(&sortuj_scalanie, tab, tab_ref, size) &&
         check_sort(&sortuj_szybkie, tab, tab_ref, size) &&
         check_sort(&sortuj_szybkie_rand_piwot, tab, tab_ref, size))
        )
        return 0;
    return 1;
}


int fight(int size){
    int *tab = Tablica(size);
    int i;
    losuj(tab, size, MAX_RANDOM);

    printf("%d, ", size);

    /* tablica z losowymi danymi */
    if(!strike(tab, size))
        return 1;

    /* tablica uporzadkowana */
    for (i = 0; i < size; i++) {
        tab[0] = i;
    }
    if(!strike(tab, size))
        return 1;

    /* tablica odrwortnie uporzadkowana */
    for (i = 0; i < size; i++) {
        tab[0] = size - i;
    }
    if(!strike(tab, size))
        return 1;

    printf("\n");
    return 1;
}
