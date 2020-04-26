#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elems; // 存放的数据
    int length; // 当前数据长度
    int size; // 总长度
} List;

void * createList(int size) {
    if (size < 1) {
        printf("初始化失败\n，size 不能小于1\n");
        return NULL;
    } else {
        List *list = (List *)malloc(sizeof(List));
        list->size = size;
        list->length = 0;
        list->elems = malloc(sizeof(int) * size);
        return list;
    }
}

void insert(List *list, int idx, int value) {
    if (idx < 0 || list->length == list->size || idx > list->length) {
        printf("插入失败\n");
    } else {
        for (int i = list->length - 1; i >= idx; i--) {
            list->elems[i + 1] = list->elems[i];
        }
        list->elems[idx] = value;
        list->length++;
    }
}

void append(List *list, int value) {
    insert(list, list->length, value);
}

void delete(List *list, int idx) {
    if (idx < 0 || idx >= list->length) {
        printf("删除失败\n");
    } else {
        for (int i = idx; i < list->length - 1; i++) {
            list->elems[i] = list->elems[i + 1];
        }
        list->length--;
    }
}

void update(List *list, int idx, int value) {
    if (idx < 0 || idx >= list->length) {
        printf("更新失败\n");
    } else {
        list->elems[idx] = value;
    }
}

int getvalue(List *list, int idx) {
    if (idx < 0 || idx >= list->length) {
        printf("获取失败\n");
        return -1;
    } else {
        return list->elems[idx];
    }
}

int getidx(List *list, int value) {
    for (int i = 0; i < list->length; i++) {
        if (list->elems[i] == value) {
            return i;
        }
    }
    return -1;
}

int length(List *list) {
    return list->length;
}

void clean(List *list) {
    list->length = 0;
}

void destroy(List *list) {
    free(list->elems);
    free(list);
}

void traverse(List *list) {
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->elems[i]);
    }
    printf("\n");
}


int main() {
    List *list = createList( 10);
    
//    insert(list, 0, 23);
    append(list, 12);
    append(list, 14);
    append(list, 15);
    append(list, 17);
    append(list, 19);
    append(list, 30);
    insert(list, 2, 90);
    append(list, 10);
    append(list, 40);
    append(list, 50);
    
    traverse(list);
    
    delete(list, 0);
    
    traverse(list);
    
    printf("%d \n", getvalue(list, 8));
    
    printf("%d \n", getidx(list, 40));
    
    update(list, 3, 111);
    
    traverse(list);
}
