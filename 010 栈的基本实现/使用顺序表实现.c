#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int *base;
    int top;
} Stack;

Stack * createStack(int size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->size = size;
    stack->base = malloc(sizeof(int) * size);
    stack->top = 0;
    return stack;
}

void clean(Stack *stack) {
    stack->top = 0;
}

int length(Stack *stack) {
    return stack->top;
}

int getTop(Stack *stack) {
    if (stack->top == 0) {
        return -1000;
    }
    int idx = stack->top - 1;
    return stack->base[idx];
}

void push(Stack *stack, int e) {
    if (stack->top == stack->size) {
        return;
    }
    stack->base[stack->top] = e;
    stack->top += 1;
}

int pop(Stack *stack) {
    if (stack->top == 0) {
        return -10000;
    }
    stack->top -= 1;
    return stack->base[stack->top];
}

int isEmpty(Stack *stack) {
    return stack->top == 0;
}

void traverse(Stack *stack) {
    for (int i = 0; i < stack->top; i++) {
        printf("%d ", stack->base[i]);
    }
    printf("\n");
}

int main() {
    Stack *stack = createStack(100);
    for (int i = 0; i < 20; i++) {
        int v = rand() % 100;
        push(stack, v);
        printf("%d ", v);
    }
    printf("\n");
    
    traverse(stack);
    
    printf("%d \n", getTop(stack));
    printf("%d \n", isEmpty(stack));
    printf("%d \n", length(stack));
    
    printf("%d \n", pop(stack));
    traverse(stack);
    printf("%d \n", getTop(stack));
    printf("%d \n", isEmpty(stack));
    printf("%d \n", length(stack));
    
    clean(stack);
    traverse(stack);
    printf("%d \n", getTop(stack));
    printf("%d \n", isEmpty(stack));
    printf("%d \n", length(stack));
    
    pop(stack);
    traverse(stack);
    printf("%d \n", getTop(stack));
    printf("%d \n", isEmpty(stack));
    printf("%d \n", length(stack));
    return 0;
}


