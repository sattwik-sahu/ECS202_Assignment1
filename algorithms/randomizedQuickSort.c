#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../util/data/Queue.c"
#include "../util/random/generator.c"


Queue *randomQuickSortQueue(Queue *queue, int size) {
    if (queue->top->next == NULL) {
        return queue;
    }

    // Random pivot element
    // Rotate the queue some random number of times
    int nRot = (int)(getRandom() * size);
    for (int i = 0; i < nRot; i++) {
        pushQueueNode(queue, popQueueNode(queue));
    }

    // Normal quicksort
    int nLarger = 0, nSmaller = 0;
    Queue *qLarger = createQueue(),
            *qSmaller = createQueue(),
            *sortedQueue = createQueue();
    QueueNode *pivot = popQueueNode(queue);
    while (!isQueueEmpty(queue)) {
        QueueNode *node = popQueueNode(queue);
        if (node->value > pivot->value) {
            pushQueueNode(qLarger, node);
            nLarger++;
        } else {
            pushQueueNode(qSmaller, node);
            nSmaller++;
        }
    }
    if (nLarger > 0) {
        pushQueueQueue(sortedQueue, randomQuickSortQueue(qLarger, nLarger));
    }
    pushQueueNode(sortedQueue, pivot);
    if (nSmaller > 0) {
        pushQueueQueue(sortedQueue, randomQuickSortQueue(qSmaller, nSmaller));
    }

    free(qSmaller);
    free(qLarger);

    return sortedQueue;
}

int *randomQuickSort(int *x, int size, bool reverse) {
    Queue *xQueue = createQueue();
    for (int i = 0; i < size; i++) {
        pushQueueValue(xQueue, x[i]);
    }
    // printQueue(xQueue);
    xQueue = randomQuickSortQueue(xQueue, size);
    int *sorted = (int *) malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        sorted[reverse? i : (size - 1) - i] = popQueueNode(xQueue)->value;
    }
    return sorted;
}

// int main(int argc, char const *argv[])
// {
//     // Get 5 random numbers
//     int *x = getRandoms(N_MAX);
//     printf("Check sort = %d\n", checkSorted(x, N_MAX));
//     // printf("Start\n");
//     time_t t;
//     srand((unsigned)time(&t));

//     clock_t time;
//     int *y;
//     FILE *timeLogfile = fopen("../data/time_randomizedQuickSort.csv", "w");
//     fprintf(timeLogfile, "t_rquick\n");
//     for (int i = 0; i < N_RUNS; i++) {
//         time = clock();
//         y = randomQuickSort(x, N_MAX, true);
//         time = clock() - time;
//         fprintf(timeLogfile, "%.3f\n", (double) time / CLOCKS_PER_SEC);
//     }
//     // printf("End\n");
//     printf("Check sort = %d\n", checkSorted(y, N_MAX));
//     // for (int i = 0; i < 100; i++) {
//     //     printf("%d ", y[i]);
//     // }
//     printf("\n");
//     return 0;
// }
