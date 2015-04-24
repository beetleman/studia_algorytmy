#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algorytmy.h"
#include "timer_lib.h"

#define FROM   1000
#define TO   100000
#define STEP   2000
#define MAX_RANDOM 100

int fight(int size);


int main()
{
    int size;
    printf("n, wstawiamy, wybieranie, scalanie\n");
    for (size = FROM; size < TO; size = size + STEP) {
        
        if(!fight(size))
            printf("\nZle!!, jeden z algorytmow inaczej sortuje!\n");
    }

    return (EXIT_SUCCESS);
}


int fight(int size){
    int *tab = Tablica(size);
    int *tab_tmp = Tablica(size);
    int *tab_ref = Tablica(size);
    losuj(tab, size, MAX_RANDOM);

    printf("%d, ", size);

    kopiujT(tab_ref, tab, size);
    start_timer();
    sortuj_wstawianie(tab_ref, 0, size);
    printf("%ld, ", stop_timer());


    kopiujT(tab_tmp, tab, size);
    start_timer();
    sortuj_wybieranie(tab_tmp, 0, size);
    printf("%ld, ", stop_timer());

    if(!porownajT(tab_tmp, tab_ref, 0, size))
        return 0;

    kopiujT(tab_tmp, tab, size);
    start_timer();
    sortuj_scalanie(tab_tmp, 0, size);
    printf("%ld", stop_timer());

    if(!porownajT(tab_tmp, tab_ref, 0, size))
        return 0;

    printf("\n");
    return 1;
}
