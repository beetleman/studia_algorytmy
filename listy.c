#include <stdio.h>
#include <stdlib.h>
#include "algorytmy.h"

#define N 5


int main()
{
    int i;
    struct LISTA *lista = nowa_lista();


    for (i = 0; i < N; i++) {
        printf("1\n");
        dodaj_do_konca_listy(lista, nowy_element());
        lista->end->x = i;
        lista->end->y = i;
        printf("start.x = %d\n", lista->start->x);
        printf("end.x = %d\n", lista->end->y);
    }

    return (EXIT_SUCCESS);
}
