#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <time.h>
#include <time.h>
#include <math.h>
#include "algorytmy.h"

int *Tablica(int n) {
    int i,*p=(int*)malloc(sizeof(int)*n);
    if (p!=NULL) for (i=0;i<n;i++) p[i]=0;
    return p;
}


int **Macierz(int w,int k) {
    int i,j, **p=(int**)malloc(sizeof(int*)*w);
    if (p==0) return 0;

    for (i=0;i<w;i++) {
        p[i]=Tablica(k);
        if (p[i]==NULL) break;
    }

    if (i<w) { 
        for (j=0;j<i;j++) free(p[j]);
        free(p);
        return 0;
    }

    for (i=0;i<w;i++)
        for (j=0;j<k;j++) p[i][j]=0;

    return p;
}


void UsunMacierz(int **p,int w) {
    int i;
    for (i=0;i<w;i++) free(p[i]);
    free(p); 
}


int __seed = 0;
void losuj(int t[], int n, int p) {
    if(__seed){
        srand(time(0));
        __seed = 1;
    }
    int i;
    for (i=0;i<n;i++) t[i]=rand()%p;
}


void drukujT(int t[], int p, int k) {
    int i;
    for (i=p;i<k;i++) printf("%d ",t[i]);
}

void drukujM(int **t, int p, int k, int N) {
    int j;
    for (j=0; j<N; j++){
        drukujT(t[j], p, k);
        if(j + 1 < N)
            printf("\n");
    }
}

void kopiujT(int t1[],int t2[],int n) {
    int i;
    for (i=0;i<n;i++) t1[i]=t2[i];
}


void odwrocT(int t[],int n) {
    int i,x;
    for (i=0;i<n/2;i++) {x=t[i];t[i]=t[n-i-1];t[n-i-1]=x;}
}


int* czytaj_z_pliku(const char * nazwa,int *ile) {
    int i,n,x,*a;
    FILE* f;
    if ((f=fopen(nazwa,"rt"))==0) return 0;
    n=0; 
    while (fscanf(f,"%d",&x)==1) n++;
    fseek(f,0,0); 

    if (*ile > 0 && *ile < n) n=*ile;

    a=Tablica(n);
    *ile=n;
    for (i=0;i<n;i++) if (fscanf(f,"%d",&x)==1) a[i]=x;
    *ile=n;
    fclose(f);
    return a;
}


void zapisz_do_pliku(const char * nazwa,int a[], int n) {
    int i;
    FILE* f;
    if ((f=fopen(nazwa,"wt"))==0) return;
    for (i=0;i<n;i++)fprintf(f,"%d\n",a[i]);
    fclose(f);
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


int szukaj_binarne(int t[], int s, int p, int k)
{
    int l = k - p;
    int sr = p + l/2;

    if(p == k){
        if (t[p] == s)
            return p;
        else
            return -1;
    }

    if(t[sr] < s)
        return szukaj_binarne(t, s, sr, k);
    else if (t[sr] < s)
        return szukaj_binarne(t, s, p, sr);
    else
        return sr;
}


float potega(float x, float p)
{
    int i;
    float w = 1;
    for (i = 0; i < p; i++) {
        w *= x;
    }
    return w;
}


int* mnorzenie_m_w(int **mat, int *wek, int w, int k)
{
    int i, j;
    int * m_w = Tablica(w);

    for (i = 0; i < w; i++) {
        m_w[i] = 0;
        for (j = 0; j < k; j++) {
            m_w[i] += wek[j] * mat[i][j];
        }
    }

    return m_w;
}

float sum_wielomianu_algorytm_hornera(int tab[], int start, int end, float x)
{
    int i;
    float w = tab[end];

    for (i = start; i < end -1; i++) {
        w *= x + tab[i];
    }

    return w;
}


float sum_wielomianu(int tab[], int start, int end, float x)
{
    int i;
    float w = 0;

    for (i = start; i < end; i++) {
        w += tab[i] * potega(x, 2);
    }

    return w;
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

/* LISTA JEDNOKIERUKOWA

   U mnie wszystkie cos zwracaja dziekitemu moge ponizsze funkcje
   ladnie laczyc.
*/

/* wstawia element 'n' za 'c' i nie przerywa lancucha jesli 'c'
   jest gdzes w srodku listy
 */

struct LISTA *nowa_lista(void)
{
    struct LISTA * lista;
    lista = (struct LISTA *) malloc(sizeof(struct LISTA));
    lista->start = NULL;
    lista->end = NULL;
    return lista;
}

void dodaj_do_konca_listy(struct LISTA * lista, struct ELEMENT * el)
{
    if(lista->end == NULL)
        lista->end = el;
    else
        lista->end = wstaw_element(lista->end, el);
    if(lista->start == NULL)
        lista->start = lista->end;
}

void dodaj_do_poczatka_listy(struct LISTA * lista, struct ELEMENT * el)
{
    if(lista->start == NULL){
        lista->start = nowy_element();
    }
    else {
        el->next = lista->start;
        lista->start = el;
    }
    if(lista->end == NULL)
        lista->end  = lista->start;
}

void drukuj_liste(struct LISTA * lista)
{
    struct ELEMENT *element = lista->start;

    while(element != NULL){
        printf("x = %d, y = %d\n", element->x, element->y);
        element = element->next;
    }

}


struct ELEMENT *wstaw_element (struct ELEMENT * el, struct ELEMENT * new_el)
{
    struct ELEMENT * tmp;
    tmp = el->next;
    el->next = new_el;
    new_el->next = tmp;
    return new_el;
}

struct ELEMENT *nowy_element(void)
{
    struct ELEMENT * el;
    el = (struct ELEMENT *) malloc(sizeof(struct ELEMENT));
    el->next = NULL;
    return el;
}

struct ELEMENT *wytnij_nastepny(struct ELEMENT * el)
{
    struct ELEMENT * tmp;
    tmp = el->next;
    if(tmp->next != NULL)
        el->next = tmp->next;
    return tmp;
}

struct ELEMENT *wstaw_nowy_element(struct ELEMENT * el)
{
    return wstaw_element(el, nowy_element());
}
