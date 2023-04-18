#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "./algorithms/randomizedQuickSort.c"
#include "./algorithms/heapSort.c"
#include "./algorithms/mergeSort.c"
#include "./util/random/readRandom.h"
#include "./util/checkSorted.h"

#define N_RAND 1000000
#define N_RUNS 100

int main(int argc, char const *argv[])
{
    // Get 1M randoms
    printf("Fetching random numbers...\n");
    int *x = getRandoms(N_RAND);
    printf("Done\n\n");

    // Create log files
    FILE *rQuick = fopen("./data/rQuick.txt", "w");
    FILE *hSort = fopen("./data/hSort.txt", "w");
    FILE *mSort = fopen("./data/mSort.txt", "w");

    // Timing var
    clock_t t;
    double total;

    // Randomized quick sort
    total = 0;
    printf("Running RANDOMIZED QUICK SORT %d times\n", N_RUNS);
    for (int i = 0; i < N_RUNS; i++) {
        t = clock();
        randomQuickSort(x, N_RAND, false);
        t = clock() - t;
        double time = (double) t / CLOCKS_PER_SEC;
        fprintf(rQuick, "%.3f\n", time);
        total += time;
        printf(".");
    }
    printf("\nDone in %.3f s.\n\n", total);

    // Heap sort
    total = 0;
    printf("Running HEAP SORT %d times\n", N_RUNS);
    for (int i = 0; i < N_RUNS; i++) {
        t = clock();
        heapSort(x, N_RAND);
        t = clock() - t;
        double time = (double) t / CLOCKS_PER_SEC;
        fprintf(hSort, "%.3f\n", time);
        total += time;
        printf(".");
    }
    printf("\nDone in %.3f s.\n\n", total);

    // Merge sort
    total = 0;
    printf("Running MERGE SORT %d times\n", N_RUNS);
    for (int i = 0; i < N_RUNS; i++) {
        t = clock();
        mergeSort(x, N_RAND, false);
        t = clock() - t;
        double time = (double) t / CLOCKS_PER_SEC;
        fprintf(mSort, "%.3f\n", time);
        total += time;
        printf(".");
    }
    printf("\nDone in %.3f s.\n\n", total);

    printf("[LOGS]\ndata/rQuick.txt\ndata/hSort.txt\ndata/mSort.txt\n");
}
