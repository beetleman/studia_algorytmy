#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort_contest.h"

int main()
{

    int status;
    FILE * fp_random = fopen("data/random.csv", "w");
    FILE * fp_sorted = fopen("data/sorted.csv", "w");
    FILE * fp_reverse_sorted = fopen("data/reverse_sorted.csv", "w");
    if(fp_random == NULL || fp_sorted == NULL || fp_reverse_sorted == NULL) {
        fprintf(stderr, "Nie moge otworzyc pliku!");
    }

    status = start_contest(fp_random, fp_sorted, fp_reverse_sorted);

    fclose(fp_random);
    fclose(fp_sorted);
    fclose(fp_reverse_sorted);

    return status;
}
