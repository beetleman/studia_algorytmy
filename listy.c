#include <stdio.h>
#include <stdlib.h>
#include "algorytmy.h"

#define N 5


int main()
{
    int i;
    struct ELEMENT * head;
    struct ELEMENT * last;
    head = nowy_element();
    last = head;

    for (i = 0; i < N; i++) {
        last = wstaw_nowy_element(last);
        last->x = i;
        last->y = i;
    }

    return (EXIT_SUCCESS);
}
