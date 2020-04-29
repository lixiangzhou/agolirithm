#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front;
    int rear;
    int size;
    int *elems;
} ArrayQueue;

ArrayQueue * createQueue(int size) {
    if (size > 0) {
        ArrayQueue *queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
        queue->front = 0;
        queue->rear = 0;
        queue->size = size;
        queue->elems = malloc(sizeof(int) * size);
        
        return queue;
    }
    return NULL;
}

int isEmpty(ArrayQueue *queue) {
    return queue->front == queue->rear;
}

int isFull(ArrayQueue *queue) {
    return (queue->rear + 1) % queue->size == queue->front;
}

int length(ArrayQueue *queue) {
    return (queue->rear - queue->front + queue->size) % queue->size;
}

int getHead(ArrayQueue *queue) {
    if (isEmpty(queue)) {
        return -10000;
    }
    return queue->elems[queue->front];
}

void enQueue(ArrayQueue *queue, int value) {
    if (isFull(queue)) {
        return;
    }
    queue->elems[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->size;
}

int deQueue(ArrayQueue *queue) {
    if (isEmpty(queue)) {
        return -10000;
    }
    int value = queue->elems[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    return value;
}

void traverse(ArrayQueue *queue) {
    for (int i = queue->front; i != queue->rear; i = (i + 1) % queue->size) {
        printf("%d ", queue->elems[i]);
    }
    printf("\n");
}

void printInfo(ArrayQueue *queue) {
    traverse(queue);
    printf("isEmpty：%d ", isEmpty(queue));
    printf("isFull：%d ", isFull(queue));
    printf("length：%d ", length(queue));
    printf("getHead：%d ", getHead(queue));
    printf("\n");
}

int main() {
    
    ArrayQueue *queue = createQueue(5);
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
