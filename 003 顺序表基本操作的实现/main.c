#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 5

typedef enum {
    false,
    true
} bool;

typedef int Status;

typedef struct{
    int *elem; // 指向基地址
    int length; // 数组长度
} SqList;

Status InitList(SqList *L) {
    L->elem = malloc(MAXSIZE);
    if (!L->elem) {
        return ERROR;
    }
    L->length = 0;
    return OK;
}

Status GetElem(SqList L, int idx, int *result) {
    if (idx < 0 || idx > L.length - 1) {
        return ERROR;
    }
    *result = L.elem[idx];
    return OK;
}

int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e) {
            return i;
        }
    }
    return 0;
}

Status ListInsert(SqList *L, int idx, int e) {
    if (idx < 0 || idx > L->length || L->length == MAXSIZE) {
        return ERROR;
    }
    for (int i = L->length; i >= idx; i--) {
        L->elem[i] = L->elem[i - 1];
    }
    L->elem[idx] = e;
    L->length += 1;
    return OK;
}

Status ListDelete(SqList *L, int idx) {
    if (idx < 0 || idx >= L->length) {
        return ERROR;
    }
    
    for (int i = idx; i < L->length - 1; i++) {
        L->elem[i] = L->elem[i + 1];
    }
    
    L->length--;
    
    return OK;
}

int ListLength(SqList L) {
    return L.length;
}

Status ClearList(SqList *L) {
    L->length = 0;
    return OK;
}

bool ListEmpty(SqList L) {
    if (L.length == 0) {
        return true;
    }
    return false;
}

Status TraverseList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
    return OK;
}


int main(int argc, char* argv[]){
    
    SqList L;
    
    InitList(&L);
    
    printf("插入元素...\n");
    
    ListInsert(&L, 0, 3);
    ListInsert(&L, 1, 4);
    ListInsert(&L, 2, 5);
    ListInsert(&L, 2, 7);
    ListInsert(&L, 4, 8);
    ListInsert(&L, 0, 8);
    
    TraverseList(L);

    
    ListDelete(&L, -1);
    
    printf("length = %d\n", ListLength(L));
    
    
    printf("遍历元素\n");
    
    TraverseList(L);
    
    printf("获取指定元素的索引 %d\n", LocateElem(L, 5));
    
    ClearList(&L);
    
    TraverseList(L);
    
    printf("\n");
    
    return 0;
}

