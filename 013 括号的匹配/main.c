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

int match(char *string) {
    Stack *stack = createStack(20);
    
    int i = 0;
    char c = string[i];
    
    while (c != '\n') {
        if (c == '(' || c == '[' || c == '{') {
            push(stack, c);
        } else if (c == ')') {
            if (!(getTop(stack) == '(')) {
                return 0;
            }
            pop(stack);
        } else if (c == ']') {
            if (!(getTop(stack) == '[')) {
                return 0;
            }
            pop(stack);
       } else if (c == '}') {
            if (!(getTop(stack) == '{')) {
                return 0;
            }
           pop(stack);
       }
        
        
        i++;
        c = string[i];
    }
    
    return isEmpty(stack);
}


int main() {
    
    char *test = "{dfasfa(32432fdasf])32324}\n";
    
    printf("%d \n", match(test));
    
    return 0;
}



