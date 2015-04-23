#ifndef _ALGORYTMY
#define _ALGORYTMY


int *Tablica(int n);

int **Macierz(int w,int k);

void UsunMacierz(int**,int);

void losuj(int t[], int n, int p);

void drukujT(int t[], int p, int k);

void kopiujT(int t1[],int t2[],int n);

void odwrocT(int t[],int n);

int* czytaj_z_pliku(const char *nazwa, int *ile); 

void zapisz_do_pliku(const char * nazwa,int a[], int n);

int szukaj_binarne(int tab[], int s, int p, int k);

float sum_wielomianu_algorytm_hornera(int tab[], int start, int end, float x);
float sum_wielomianu(int tab[], int start, int end, float x);

void sortuj_wstawianie( int tab[], int start, int end);
void sortuj_wybieranie( int tab[], int start, int end);

#endif
