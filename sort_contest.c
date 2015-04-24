#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algorytmy.h"
#include "timer_lib.h"

#define FROM   1000
#define TO   100000
#define STEP   5000
#define MAX_RANDOM 100

void fight(int size);


int main()
{
    int size;
    for (size = FROM; size < TO; size = size + STEP) {
        fight(size);
    }

    return (EXIT_SUCCESS);
}


void fight(int size){
    int *tab = Tablica(size);
    int *tab_tmp = Tablica(size);
    losuj(tab, size, MAX_RANDOM);

    kopiujT(tab_tmp, tab, size);
    start_timer();
    sortuj_wstawianie(tab_tmp, 0, size);
    printf("%ld, ", stop_timer());

    kopiujT(tab_tmp, tab, size);
    start_timer();
    sortuj_wstawianie(tab_tmp, 0, size);
    printf("%ld, ", stop_timer());

    kopiujT(tab_tmp, tab, size);
    start_timer();
    sortuj_wybieranie(tab_tmp, 0, size);
    printf("%ld, ", stop_timer());

    kopiujT(tab_tmp, tab, size);
    start_timer();
    sortuj_scalanie(tab_tmp, 0, size);
    printf("%ld", stop_timer());

    printf("\n");
}
