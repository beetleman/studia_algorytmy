#ifndef _ALGORYTMY
#define _ALGORYTMY


int *Tablica(int n);

int **Macierz(int w,int k);

void UsunMacierz(int**,int);

void losuj(int t[], int n, int p);

void drukujT(int t[], int p, int k);

void drukujM(int **t, int p, int k, int N);

void kopiujT(int t1[],int t2[],int n);

int porownajT(int t1[], int t2[], int p, int k);

void odwrocT(int t[],int n);

int* czytaj_z_pliku(const char *nazwa, int *ile);

void zapisz_do_pliku(const char * nazwa,int a[], int n);

int* mnorzenie_m_w(int **mat, int *wek, int w, int k);

int szukaj_binarne(int tab[], int s, int p, int k);

float sum_wielomianu_algorytm_hornera(int tab[], int start, int end, float x);
float sum_wielomianu(int tab[], int start, int end, float x);


void sortuj_wstawianie( int tab[], int start, int end);
void sortuj_wybieranie( int tab[], int start, int end);
void sortuj_scalanie(int tab[], int start, int end);

void sortuj_szybkie (int tab[], int start, int end);
void sortuj_szybkie_rand_piwot (int tab[], int start, int end);

/* lista */

struct element
{
    int x;
    int y;

    struct element * next;
};

/* drzewo */

struct node
{
    int x;
    int y;

    struct node * root;
    struct node * left;
    struct node * right;
};

#endif
