#include <stdio.h>
#include <stdlib.h>
#include "algorytmy.h"

#define N 5


int main()
{
    int i;
    struct LISTA *lista = nowa_lista();


    for (i = 0; i < N; i++) {
        dodaj_do_konca_listy(lista, nowy_element());
        lista->end->n = i;
    }

    for (i = 1; i < N; i++) {
        dodaj_do_poczatka_listy(lista, nowy_element());
        lista->start->n = i * -1;
    }

    drukuj_liste(lista);

    return (EXIT_SUCCESS);
}
