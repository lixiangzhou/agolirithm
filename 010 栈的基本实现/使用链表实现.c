#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node * createNode(int value) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->value = value;
    n->next = NULL;
    return n;
}

void clean(Node *node) {
    node->next = NULL;
}

int getTop(Node *node) {
    if (node->next != NULL) {
        return node->next->value;
    }
    return -10000;
}

void push(Node *node, int e) {
    Node *n = createNode(e);
    n->next = node->next;
    node->next = n;
}

int pop(Node *node) {
    if (node->next != NULL) {
        int value = node->next->value;
        node->next = node->next->next;
        return value;
    }
    return -10000;
}

int isEmpty(Node *node) {
    return node->next == NULL;
}

int main() {
    Node *stack = createNode(0);
    for (int i = 0; i < 20; i++) {
        int v = rand() % 100;
        push(stack, v);
        printf("%d ", v);
    }
    printf("\n");
    
    printf("%d \n", getTop(stack));
    printf("%d \n", isEmpty(stack));
    
    printf("%d \n", pop(stack));
    printf("%d \n", getTop(stack));
    printf("%d \n", isEmpty(stack));
    
    clean(stack);
    printf("%d \n", getTop(stack));
    printf("%d \n", isEmpty(stack));
    
    pop(stack);
    printf("%d \n", getTop(stack));
    printf("%d \n", isEmpty(stack));
    return 0;
}


