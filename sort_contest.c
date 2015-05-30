#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algorytmy.h"
#include "timer_lib.h"

#define FROM   1000
#define TO    10000
#define STEP    100
#define MAX_RANDOM 100

int fight(int size);


int main()
{
    int size;
    printf("n, wstawiamy, wybieranie, scalanie, szybkie, szybkie losowe \n");
    for (size = FROM; size < TO; size = size + STEP) {
        if(!fight(size)){
            printf("\nZle!!, jeden z algorytmow inaczej sortuje!\n");
            return (EXIT_FAILURE);
        }
    }

    return (EXIT_SUCCESS);
}


int * check_sort(void (*sortuj)(int [], int, int),
                int *tab, int *tab_ref, int size){
    int *tab_tmp = Tablica(size);
    kopiujT(tab_tmp, tab, size);

    start_clock_timer();
    (*sortuj)(tab_tmp, 0, size);
    printf("%ld, ", stop_clock_timer());

    if(tab_ref != NULL && !porownajT(tab_tmp, tab_ref, 0, size)){
        printf("powinno byc: ");
        drukujT(tab_tmp, 0, size);
        printf("\njest: ");
        drukujT(tab_ref, 0, size);
        return NULL;
    }

    return tab_tmp;
}


int fight(int size){
    int *tab = Tablica(size);
    int *tab_ref = Tablica(size);
    losuj(tab, size, MAX_RANDOM);

    printf("%d, ", size);

    tab_ref = check_sort(&sortuj_wstawianie, tab, NULL, size);

    if(!(check_sort(&sortuj_wybieranie, tab, tab_ref, size) &&
         check_sort(&sortuj_scalanie, tab, tab_ref, size) &&
         check_sort(&sortuj_szybkie, tab, tab_ref, size) &&
         check_sort(&sortuj_szybkie_rand_piwot, tab, tab_ref, size))
        )
        return 0;

    printf("\n");
    free(tab_ref);
    free(tab);
    return 1;
}
