#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort_contest.h"

#define FROM   1000
#define TO    10000
#define STEP    100

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
