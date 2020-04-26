#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
    struct Node *previous;
} Node, LinkList;

void * createList() {
    LinkList *list = (LinkList *)malloc(sizeof(LinkList));
    list->next = NULL;
    list->previous = NULL;
    list->value = 0;
    return list;
}

void insert(LinkList *list, int idx, int value) {
    if (idx < 0) {
        printf("插入失败\n");
    } else {
        Node *p = list;
        int i = 0;
        while (p != NULL && i < idx) {
            p = p->next;
            i++;
        }
        
        if (p != NULL && i == idx) {
            Node *next = p->next;
            
            Node *n = (Node *)malloc(sizeof(Node));
            n->value = value;
            n->next = next;
            n->previous = p;
            
            p->next = n;
            if (next != NULL) {
                next->previous = n;
            }
            list->value++;
        } else {
            printf("插入失败\n");
        }
    }
}

void append(LinkList *list, int value) {
    insert(list, list->value, value);
}

void delete(LinkList *list, int idx) {
    if (idx < 0) {
        printf("删除失败\n");
    } else {
        Node *p = list;
        int i = 0;
        while (p != NULL && i < idx) {
            p = p->next;
            i++;
        }
        Node *n = p->next;
        if (n != NULL && i == idx) {
            Node *next = n->next;
            
            p->next = next;
            
            if (next != NULL) {            
                next->previous = p;
            }
            
            free(n);
            list->value--;
        } else {
            printf("删除失败\n");
        }
    }
}

void update(LinkList *list, int idx, int value) {
    if (idx < 0) {
        printf("更新失败\n");
    } else {
        Node *p = list->next;
        int i = 0;
        while (p != NULL && i < idx) {
            p = p->next;
            i++;
        }
        
        if (p != NULL && i == idx) {
            p->value = value;
        } else {
            printf("更新失败\n");
        }
    }
}

void getValue(LinkList *list, int idx, int *value) {
    if (idx < 0) {
        printf("获取失败\n");
    } else {
        Node *p = list->next;
        int i = 0;
        while (p != NULL && i < idx) {
            p = p->next;
            i++;
        }
        if (p != NULL && i == idx) {
            *value = p->value;
        } else {
            printf("获取失败\n");
        }
    }
}

void getIndex(LinkList *list, int value, int *idx) {
    Node *p = list->next;
    int i = 0;
    while (p != NULL) {
        if (p->value == value) {
            *idx = i;
            break;
        }
        p = p->next;
        i++;
    }
}

void length(LinkList *list) {
    return list->value;
}

void clean(LinkList *list) {
    Node *p = list->next;
    list->next = NULL;
    list->value = 0;
    
    while (p != NULL) {
        Node *next = p->next;
        free(p);
        p = next;
    }
}

void destroy(LinkList *list) {
    clean(list);
    free(list);
}

void traverse(LinkList *list) {
    Node *p = list->next;
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

/**
 双向链表和单向链表的基本实现基本一致，区别在于插入和删除的时候有点不一样
 双向链表在插入和删除的时候需要设置每个Node的前驱节点和后继节点的值，而单向链表只需设置后继节点的值
 */

int main() {
    LinkList *list = createList();
    traverse(list);
    
    for (int i = 0; i < 10; i++) {
        int value = random() % 20;
        printf("%d ", value);
        append(list, value);
    }
    printf("\n");
    traverse(list);
    
    insert(list, 5, 100);
    traverse(list);
    
    delete(list, 10);
    traverse(list);
    
    update(list, 5, 200);
    traverse(list);
    
    int result = -1;
    getValue(list, 7, &result);
    printf("%d \n", result);

    int idx = -1;
    getIndex(list, 6, &idx);
    printf("%d \n", idx);
    
    
    return 0;
}
