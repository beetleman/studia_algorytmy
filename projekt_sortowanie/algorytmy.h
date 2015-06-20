#ifndef _ALGORYTMY
#define _ALGORYTMY

int *Tablica(int n);
void losuj(int t[], int n, int p);
void kopiujT(int t1[],int t2[],int n);
int porownajT(int t1[], int t2[], int p, int k);
void odwrocT(int t[],int n);


void sortuj_wstawianie( int tab[], int start, int end);
void sortuj_wybieranie( int tab[], int start, int end);
void sortuj_scalanie(int tab[], int start, int end);

void sortuj_szybkie (int tab[], int start, int end);
void sortuj_szybkie_rand_piwot (int tab[], int start, int end);
void sortuj_zliczanie_for_contest (int tab[], int start, int end);
void sortuj_zliczanie (int tab[], int start, int end, int max);

#endif
