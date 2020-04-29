#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} LinkQueue;

Node * createNode(int value) {
    Node *node = (Node *)malloc(sizeof(node));
    node->value = value;
    node->next = NULL;
    return node;
}

LinkQueue * createQueue() {
    LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
    Node *node = createNode(0);
    queue->front = node;
    queue->rear = node;
    return queue;
}

int isEmpty(LinkQueue *queue) {
    return queue->front == queue->rear;
}

int length(LinkQueue *queue) {
    return queue->front->value;
}

int getHead(LinkQueue *queue) {
    if (isEmpty(queue)) {
        return -10000;
    }
    return queue->front->next->value;
}

void enQueue(LinkQueue *queue, int value) {
    Node *node = createNode(value);
    queue->rear->next = node;
    queue->rear = node;
    queue->front->value++;
}

int deQueue(LinkQueue *queue) {
    if (isEmpty(queue)) {
        return -10000;
    }
    Node *node = queue->front->next;
    int value = node->value;
    queue->front->next = node->next;
    if (node == queue->rear) {
        queue->rear = queue->front;
    }
    queue->front->value--;
    return value;
}

void traverse(LinkQueue *queue) {
    Node *node = queue->front->next;
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

void printInfo(LinkQueue *queue) {
    traverse(queue);
    printf("isEmpty：%d ", isEmpty(queue));
    printf("length：%d ", length(queue));
    printf("getHead：%d ", getHead(queue));
    printf("\n");
}

int main() {
    
    LinkQueue *queue = createQueue(5);
    printInfo(queue);
    
    enQueue(queue, 12);
    enQueue(queue, 34);
    enQueue(queue, 1);
    printInfo(queue);
    
    enQueue(queue, 53);
    enQueue(queue, 109);
    printInfo(queue);
    
    enQueue(queue, 333);
    printInfo(queue);
    
    printf("%d \n", deQueue(queue));
    printInfo(queue);
    
    
    return 0;
}
