#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stackNode {
    int value;
    struct stackNode *next;
} StackNode;

typedef struct stack {
    StackNode *top;
} Stack;

StackNode *createStackNode(int value) {
    StackNode *node = (StackNode *) malloc(sizeof(StackNode *));
    node->value = value;
    node->next = NULL;
    return node;
}

Stack *createStack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack *));
    stack->top = NULL;
}

bool isStackEmpty(Stack *stack) {
    return stack->top == NULL;
}

StackNode *pushStackNode(Stack *stack, StackNode *node) {
    node->next = stack->top;
    stack->top = node;
    return stack->top;
}

StackNode *pushStackValue(Stack *stack, int value) {
    return pushStackNode(stack ,createStackNode(value));
}

StackNode *popStackNode(Stack *stack) {
    if (isStackEmpty(stack)) {
        return NULL;
    }
    StackNode *poppedNode = stack->top;
    stack->top = stack->top->next;
    return poppedNode;
}

StackNode *pushStackStack(Stack *stack, Stack *stack_) {
    while (!isStackEmpty(stack_)) {
        pushStackNode(stack, popStackNode(stack_));
    }
    free(stack_);
    return stack->top;
}

void printStack(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("<EMPTY_STACK>");
    }

    StackNode *node = stack->top;
    while (node) {
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
//     Stack *stack = createStack();
//     printf("stack empty = %d\n", isStackEmpty(stack));
//     pushStackValue(stack, 7);
//     printStack(stack);

//     pushStackValue(stack, 3);
//     printStack(stack);

//     pushStackValue(stack, 7);
//     printStack(stack);

//     pushStackValue(stack, 5);
//     printStack(stack);

//     printf("stack empty = %d\n", isStackEmpty(stack));
//     printf("Popped %d from stack...\n", popStackNode(stack)->value);
//     printf("Popped %d from stack...\n", popStackNode(stack)->value);
//     printStack(stack);

//     pushStackValue(stack, 7);
//     printStack(stack);

//     pushStackValue(stack, 0);
//     printStack(stack);

//     pushStackValue(stack, 2);
//     printStack(stack);

//     printStack(stack);
//     return 0;
// }
