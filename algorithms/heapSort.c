#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void maxHeapify(int *heap, int f, int len) {
    int max = f;
    int lt = f * 2, rt = f * 2 + 1, t;
    if (lt <= len && heap[lt] > heap[max]) {
        max = lt;
    }
    if (rt <= len && heap[rt] > heap[max]) {
        max = rt;
    }
    if (f != max) {
        t = heap[f];
        heap[f] = heap[max];
        heap[max] = t;
        maxHeapify(heap, max, len);
    }
}

void maxHeap(int *heap, int start, int end) {
    for (int i = end / 2; i >= start; i--) {
        maxHeapify(heap, i, end);
    }
}

void heapSort(int *heap, int len) {
    int t;
    for (int i = len; i >= 2; i--) {
        t = heap[i];
        heap[1] = heap[i];
        heap[i] = t;
        maxHeapify(heap, 1, i - 1);
    }
}
