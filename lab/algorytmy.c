#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <time.h>
#include <time.h>
#include <math.h>
#include "algorytmy.h"

int *Tablica(int n)
{
    int i,*p=(int*)malloc(sizeof(int)*n);
    if (p!=NULL) for (i=0;i<n;i++) p[i]=0;
    return p;
}


int **Macierz(int w,int k)
{
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


void UsunMacierz(int **p,int w)
{
    int i;
    for (i=0;i<w;i++) free(p[i]);
    free(p); 
}


int __seed = 0;
void initonce_srand(void)
{
    if(__seed){
        srand(time(0));
        __seed = 1;
    }
}


void losuj(int t[], int n, int p)
{
    initonce_srand();
    int i;
    for (i=0;i<n;i++) t[i]=rand()%p;
}


void drukujT(int t[], int p, int k)
{
    int i;
    for (i=p;i<k;i++) printf("%d ",t[i]);
}


void drukujM(int **t, int p, int k, int N)
{
    int j;
    for (j=0; j<N; j++){
        drukujT(t[j], p, k);
        if(j + 1 < N)
            printf("\n");
    }
}


void kopiujT(int t1[],int t2[],int n)

{
    int i;
    for (i=0;i<n;i++) t1[i]=t2[i];
}


void odwrocT(int t[],int n)
{
    int i,x;
    for (i=0;i<n/2;i++) {x=t[i];t[i]=t[n-i-1];t[n-i-1]=x;}
}


int* czytaj_z_pliku(const char * nazwa,int *ile)
{
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


void zapisz_do_pliku(const char * nazwa,int a[], int n)
{
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
        printf("n = %d \n", element->n);
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
    el->dane = (struct DANE *) malloc(sizeof(struct DANE));
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


/* dzewo */
struct NODE *nowy_wezel(void)
{
    struct NODE *node = (struct NODE *) malloc(sizeof(struct NODE));

    node->left = NULL;
    node->right = NULL;
    node->root = NULL;

    return node;
}


void wstaw_do_drzewa(struct NODE ** root, struct NODE * leaf)
{
    struct NODE *tmp;
    struct NODE *last;

    last = tmp = *root;

    while (tmp != NULL) {
        last = tmp;
        if(tmp->x > leaf->x)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }

    if (last != NULL) {
        if(last->x > leaf->x)
            last->left = leaf;
        else
            last->right = leaf;
        leaf->root = last;
    }
    else {
        root = &leaf;
    }
}


void drukuj_drzewo(struct NODE * root)
{
    if (root)
        return;
    drukuj_drzewo(root->left);
    printf("%d, ", root->x);
    drukuj_drzewo(root->right);
}
