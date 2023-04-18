#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "../util/data/Stack.c"


Stack *merge(Stack *x1, Stack *x2) {
    Stack *mergedStack = createStack(), *tempStack = createStack();
    while (!(isStackEmpty(x1) && isStackEmpty(x2))) {
        StackNode *nextNode;
        if (isStackEmpty(x1)) {
            nextNode = popStackNode(x2);
        } else if (isStackEmpty(x2)) {
            nextNode = popStackNode(x1);
        } else {
            nextNode = popStackNode(
                (x1->top->value < x2->top->value)? x1 : x2
            );
        }
        pushStackNode(tempStack, nextNode);
    };

    while (!isStackEmpty(tempStack)) {
        pushStackNode(mergedStack, popStackNode(tempStack));
    }

    free(tempStack);

    return mergedStack;
}

Stack *mergeSortStack(Stack *x, int size) {
    if (x->top->next == NULL) {
        return x;
    }

    int s1 = size / 2;
    Stack *x1 = createStack(),
            *x2 = createStack(),
            *sortedStack = createStack();
    for (int i = 0; i < size; i++) {
        pushStackNode((i < s1)? x1 : x2, popStackNode(x));
    }
    sortedStack = merge(
        mergeSortStack(x1, s1),
        mergeSortStack(x2, size - s1)
    );

    free(x1);
    free(x2);

    return sortedStack;
}

/**
 * Sorts the array using merge sort algorithm
 * 
 * @param x The array to sort
 * @param size The size of the array
 * @param reverse Whether to sort in descending order
 *                  If true, sorts in descending order
 *                  else sorts in ascending order
 */
int *mergeSort(int *x, int size, bool reverse) {
    Stack *sortedStack = createStack();
    for (int i = 0; i < size; i++) {
        pushStackValue(sortedStack, x[i]);
    }
    sortedStack = mergeSortStack(sortedStack, size);

    int *sorted = (int *) malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        sorted[reverse? (size - 1) - i : i] = popStackNode(sortedStack)->value;
    }

    free(sortedStack);
    return sorted;
}

// int main(int argc, char const *argv[])
// {
//     // Stack *x1 = createStack(), *x2 = createStack();
//     // int y1[] = {7, 4, 3, 2, -6, -9}, y2[] = {-1, -1, 0, 2, 2, 3, 3, 5}; 

//     // for (int i = 0; i < 6; i++) pushStackValue(x1, y1[i]);
//     // // for (int i = 0; i < 8; i++) pushStackValue(x2, y2[7 - i]);

//     // printStack(x1);
//     // printStack(x2);
//     // printStack(merge(x1, x2));

//     const int N = 1000000;
//     int *x = getRandoms(N);
//     printf("Sort check = %d\n", checkSorted(x, N));
//     clock_t time;
//     int *y;
//     for (int i = 0; i < 5; i++) {
//         time = clock();
//         y = mergeSort(x, N, true);
//         time = clock() - time;
//         printf("Running time = %.3f s\n", (double) time / CLOCKS_PER_SEC);
//     }
//     // for (int i = 0; i < N; i++) {
//     //     printf("%d ", y[i]);
//     // }
//     printf("Sort check = %d\n", checkSorted(y, 6));

//     return 0;
// }
