#include <stdio.h>

#ifndef _SORT_CONTEST_H_
#define _SORT_CONTEST_H_

#define FROM   1000
#define TO    10000
#define STEP    100

#define TABLE_HEADER "n, wstawiamy, wybieranie, scalanie, szybkie, szybkie losowe \n"

int start_contest(FILE * fp_random, FILE * fp_sorted, FILE * fp_reverse_sorted);
int fight(int size, FILE * fp_random, FILE * fp_sorted, FILE * fp_reverse_sorted);
int strike(int tab[], int size, FILE * fp);
int *check_sort(void (*sortuj)(int [], int, int),
                int *tab, int *tab_ref, int size, int last, FILE * fp);

#endif /* _SORT_CONTEST_H_ */
