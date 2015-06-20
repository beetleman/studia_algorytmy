#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "algorytmy.h"


int *Tablica(int n)
{
    int i;
    int *p = (int*) malloc(sizeof(int)*n);
    if (p!=NULL) {
        for (i=0;i<n;i++) {
            p[i]=0;
        }
    }
    return p;
}


int __seed = 0;
void losuj(int t[], int n, int p)
{
    if(__seed){
        srand(time(0));
        __seed = 1;
    }
    int i;
    for (i=0;i<n;i++)
        t[i]=rand()%p;
}


void kopiujT(int t1[],int t2[],int n)
{
    int i;
    for (i=0;i<n;i++)
        t1[i]=t2[i];
}


void odwrocT(int t[],int n)
{
    int i,x;
    for (i=0; i < n/2; i++) {
        x=t[i];
        t[i]=t[n-i-1];
        t[n-i-1]=x;
    }
}


int porownajT(int t1[], int t2[], int p, int k)
{
    int i;
    for (i = p; i < k; i++) {
        if(t1[i] != t2[i])
            return 0;
    }
    return 1;
}


/* tab: tablica 1d; start: poczatek tablicy(zwykle 0); end: koniec tablicy */
void sortuj_wstawianie( int tab[], int start, int end)
{
    /*
      http://pl.wikipedia.org/wiki/Sortowanie_przez_wstawianie
    */
    int i ,j, tmp;
    for (i = start; i < end; i++) {
        tmp = tab[i];
        /* 
           tutaj cofiemy sie, bo uznajemy ze np w tablicy 10 elementowej
           tablica skladajaca sie tylko z pierwszego elementu jest posortowana
           wiec kolejne elementy wstawiamy gdzes w posortowanej tabeli od 0 do i
           tak by pasowalo, np jak mamay [1, 3], tab[i] == 2 to wstawimy je miedzu 1 a 3.
           ale nalerzy poamietac ze to tylko wycinek tabeli. cala moze wygladac:
           [1, 3, 2, 5, 0], jak cos zamienimy. bez ryzunkow cierzkot o wyjasnic:(
        */
        for (j = i - 1; j >= 0 && tab[ j ] > tmp; j--) {
            tab[j + 1] = tab[j];
        }
        tab[j +1] = tmp;
    }
}


/* tab: tablica 1d; start: poczatek tablicy(zwykle 0); end: koniec tablicy */
void sortuj_wybieranie( int tab[], int start, int end)
{
    /*
      http://pl.wikipedia.org/wiki/Sortowanie_przez_wybieranie
    */
    int i, j, m, tmp;
    for (i = start; i < end; i++) {
        for (j = i, m = i; j < end; j++) {
            if (tab[j] < tab[m]) {
                m = j;
            }
        }
        tmp = tab[i];
        tab[i] = tab[m];
        tab[m] = tmp;
    }
}


/* merge sort */

void scal (int *tab, int start, int sr, int end)
{
    int i = start, j = sr, k = 0;
    int * tmp = Tablica(end - start);

    while (i < sr && j < end) {
        if(tab[i] < tab[j]){
            tmp[k] = tab[i];
            i++;
        }
        else {
            tmp[k] = tab[j];
            j++;
        }
        k++;
    }
    for(;i < sr; i++,k++){
        tmp[k] = tab[i];
    }
    for(;j < end; j++,k++){
        tmp[k] = tab[j];
    }
    for (i = 0; i < k; i++) {
        tab[start+i] = tmp[i];
    }
    free(tmp);
}


void sortuj_scalanie (int tab[], int start, int end)
{
    int n = end - start;
    if (n < 2)
        return;
    /* srodek tablicy */
    int sr = start + n/2;
    sortuj_scalanie(tab, start, sr);
    sortuj_scalanie(tab, sr, end);
    scal(tab, start, sr, end);
}


/* qsort */

int podzial (int tab[], int start, int end, int rand_piwot)
{
    int i, j, tmp, piwot;

    j= start - 1;
    piwot = end - 1;

    if(rand_piwot){
        i = start + rand() % (end - start);
        tmp = tab[i];
        tab[i] = tab[piwot];
        tab[piwot] = tmp;
    }

    for (i = start; i < end; i++) {
        if(tab[i] <= tab[piwot]){
            j++;
            tmp = tab[i];
            tab[i] = tab[j];
            tab[j] = tmp;
        }
    }

    return j;
}


void _sortuj_szybkie (int tab[], int start, int end, int rand_piwot)
{
    if(start >= end)
        return;
    int sr = podzial(tab, start, end, rand_piwot);

    _sortuj_szybkie(tab, start, sr, rand_piwot);
    _sortuj_szybkie(tab, sr + 1, end, rand_piwot);
}


void sortuj_szybkie (int tab[], int start, int end)
{
    _sortuj_szybkie (tab, start, end, 0);
}


void sortuj_szybkie_rand_piwot (int tab[], int start, int end)
{
    // inicjuje losowosc
    srand(time(0));
    _sortuj_szybkie (tab, start, end, 1);
}


void sortuj_zliczanie (int tab[], int start, int end, int max)
{
    int i;

    int *tab_copy = Tablica(end);
    int *tab_tmp = Tablica(end);
    kopiujT(tab_copy, tab, end);

    for(i = start; i < end; ++i){
        ++tab_tmp[tab_copy[i]];
    }

    for(i = start + 1; i < max; ++i){
        tab_tmp[i] += tab_tmp[i-1];
    }

    for(i = end - 1; i >= 0; --i){
        tab[--tab_tmp[tab_copy[i]]] =tab_copy[i];
    }
}


void sortuj_zliczanie_for_contest (int tab[], int start, int end)
{
    sortuj_zliczanie (tab, start, end, end);
}
