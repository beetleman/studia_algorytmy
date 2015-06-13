#include <stdio.h>
#include <stdlib.h>
#include "algorytmy.h"

#define N 5

struct LISTA * read_and_print(char *file_name)
{
    FILE *fp;
    struct LISTA *lista = nowa_lista();
    int counter = 1;

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("\nError: %s\n", file_name);
        return lista;
    }

    dodaj_do_konca_listy(lista, nowy_element());
    while (fgets(lista->end->dane->s, DANE_SIZE, fp)) {
        printf("%4.d | %s", counter++, lista->end->dane->s);
    }

    fclose(fp);
    return lista;
}


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

    read_and_print("./listy.c");

    return (EXIT_SUCCESS);
}
