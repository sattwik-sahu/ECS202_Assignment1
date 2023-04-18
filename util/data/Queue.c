#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queueNode {
    int value;
    struct queueNode *next;
} QueueNode;

typedef struct queue {
    QueueNode *top, *bottom;
} Queue;

QueueNode *createQueueNode(int value) {
    QueueNode *node = (QueueNode *) malloc(sizeof(QueueNode *));
    node->value = value;
    node->next = NULL;
    return node;
}

Queue *createQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue *));
    queue->top = NULL;
    queue->bottom = NULL;
    return queue;
}

bool isQueueEmpty(Queue *queue) {
    return queue->top == NULL;
}

QueueNode *pushQueueNode(Queue *queue, QueueNode *node) {
    if (isQueueEmpty(queue)) {
        queue->top = node;
    } else {
        queue->bottom->next = node;
    }
    queue->bottom = node;
    return queue->bottom;
}

QueueNode *pushQueueValue(Queue *queue, int value) {
    return pushQueueNode(queue, createQueueNode(value));
}

QueueNode *popQueueNode(Queue *queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }
    QueueNode *poppedNode = queue->top;
    queue->top = queue->top->next;
    poppedNode->next = NULL;
    return poppedNode;
}

QueueNode *pushQueueQueue(Queue *queue, Queue *queue_) {
    while (!isQueueEmpty(queue_)) {
        pushQueueNode(queue, popQueueNode(queue_));
    }
    free(queue_);
    return queue->top;
}

void printQueue(Queue *queue) {
    QueueNode *node = queue->top;
    while (node != NULL) {
        printf("%d", node->value);
        if (node->next) {
            printf(" -> ");
        }
        node = node->next;
    }
    printf("\n");
}

// int main(int argc, char const *argv[])
// {
//     Queue *queue = createQueue();
//     printf("empty = %d\n", isQueueEmpty(queue));
//     pushQueueValue(queue, 9);
//     printf("empty = %d\n", isQueueEmpty(queue));
//     pushQueueValue(queue, 4);
//     pushQueueValue(queue, -2);
//     pushQueueValue(queue, 3);
//     pushQueueValue(queue, 2);
//     pushQueueValue(queue, 1);
//     printQueue(queue);
//     for (int i = 0; i < 10; i++) {
//         QueueNode *node = popQueueNode(queue);
//         pushQueueNode(queue, node);
//         printQueue(queue);
//     }
//     // printQueue(queue);
//     printf("Pop %d\n", popQueueNode(queue)->value);
//     printQueue(queue);
//     printf("Pop %d\n", popQueueNode(queue)->value);
//     printQueue(queue);

//     return 0;
// }
