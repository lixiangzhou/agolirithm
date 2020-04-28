#include <stdio.h>
#include <stdlib.h>

/**
 (1 )将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来两个链表
 的存储空间，不另外占用其他的存储空间。表中不允许有重复的数据。
 
 (2)将两个非递减的有序链表合并为一个非递增的有序链表。要求结果链表仍使用原来两个
 链表的存储空间，不另外占用其他的存储空间。表中允许有重复的数据。
 
 (3)已知两个链表A和B分别表示两个集合，其元素递增排列。请设计一个算法，用于求出
 A与B的交集，并存放在A链表中。
 
 (4)巳知两个链表 A和 B分别表示两个集合，其元素递增排列。请设计算法 求出两个集合 A
 和B 的差集（即仅由在A中出现而不在B中出现的元素所构成的集合），并以同样的形式存储，
 同时返回该集合的元素个数。
 
 (5)设计算法将一个带头结点的单链表A分解为两个具有相同结构的链表B和C, 其中B
 表的结点为 A 表中值小于零的结点，而 C 表的结点为 A 表中值大于零的结点（链表 A中的元素
 为非零整数，要求 B 、 C表利用 A 表的结点）。
 
 (6)设计一个算法，通过一趟遍历确定长度为 n的单链表中值最大的结点。
 
 (7)设计一个算法，将链表中所有结点的链接方向 “原地” 逆转，即要求仅利用原表的存储
 空间，换句话说，要求算法的空间复杂度为 0(1)。
 
 (8)设计一个算法，删除递增有序链表中值大于mink且小于maxk:的所有元素(mink和 maxk
 是给定的两个参数，其值可以和表中的元素相同，也可以不同）。
 
 (9)巳知 p指向双向循环链表中的一个结点，其结点结构为data、prior、next三个域，写出
 算法change(p), 交换p所指向的结点及其前驱结点的顺序。
 
 (10)已知长度为 n的线性表A采用顺序存储结构，请写一个时间复杂度为O(n)、空间复杂
 度为0(1)的算法，该算法可删除线性表中所有值为 item的数据元素。
 */

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node * createNode(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

Node * createList(int size, int min, int max, int sorted, int repeated) {
    Node *header = createNode(0);
    
    int ABSMAX = abs(max) > abs(min) ? abs(max) : abs(min);
    
    for (int i = 0; i < size; ) {
        int v = rand() % ABSMAX;
        
        if (v >= min && v <= max) {
            Node *p = header;
            Node *n = p->next;
            
            if (sorted) {
                while (n != NULL && v > n->value) {
                    p = n;
                    n = p->next;
                }
                
                if (!repeated && n != NULL && n->value == v) { // 有重复
                    
                } else {
                    Node *node = createNode(v);
                    node->next = p->next;
                    p->next = node;
                    i++;
                }
            } else {
                int findRepeat = 0;
                while (n != NULL) {
                    if (!repeated && v == n->value) { // 不允许重复，但是找到了重复值
                        findRepeat = 1;
                        break;
                    }
                    p = n;
                    n = p->next;
                }
                
                if (!findRepeat) {
                    Node *node = createNode(v);
                    
                    p->next = node;
                    i++;
                }
            }
        }
    }
    return header;
}

void printList(Node *header) {
    Node *p = header->next;
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

Node * mergeNoRepeat(Node *listA, Node *listB);
void test1() {
    Node *list1 = createList(10, 0, 30, 1, 1);
    Node *list2 = createList(10, 0, 30, 1, 1);
    
    printList(list1);
    printList(list2);
    
    Node *list = mergeNoRepeat(list1, list2);
    printList(list);
}

Node * mergeRepeat(Node *listA, Node *listB);
void test2() {
    Node *list1 = createList(10, 0, 30, 1, 1);
    Node *list2 = createList(10, 0, 30, 1, 1);
    
    printList(list1);
    printList(list2);
    
    Node *list = mergeRepeat(list1, list2);
    printList(list);
}

void intersection(Node *listA, Node *listB);
void test3() {
    Node *list1 = createList(10, 0, 30, 1, 1);
    Node *list2 = createList(10, 0, 30, 1, 1);

    printList(list1);
    printList(list2);

    intersection(list1, list2);
    printList(list1);
}

Node *difference(Node *listA, Node *listB, int *count);
void test4() {
    Node *list1 = createList(10, 0, 30, 1, 1);
    Node *list2 = createList(10, 0, 30, 1, 1);

    printList(list1);
    printList(list2);

    int count = 0;
    Node *list = difference(list1, list2, &count);
    printList(list);
    printf("%d \n", count);
}

void separate(Node *list, Node *listA, Node *listB);
void test5() { }

int getmax(Node *list);
void test6() { }

void reverse(Node *list);
void test7() {
    Node *list = createList(10, 0, 30, 1, 1);
    printList(list);
    reverse(list);
    printList(list);
}

void deleteBetween(Node *list, int min, int max);
void test8() {
    Node *list = createList(10, 0, 30, 1, 1);
    printList(list);
    deleteBetween(list, 10, 20);
    printList(list);
}

void removeValue(int *array, int count, int value);
void test10() {
    int arr[10] = {};
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 5;
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    removeValue(arr, 10, 4);
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");    printf("\n");
}

int main() {
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6();
//    test7();
//    test8();
    test10();
    return 0;
}

Node * mergeNoRepeat(Node *listA, Node *listB) {
    Node *header = createNode(0);
    
    Node *pA = listA->next;
    Node *pB = listB->next;
    Node *p = header;
    
    int lastValue = -10000;
    
    while (pA != NULL && pB != NULL) {
        int vA = pA->value;
        int vB = pB->value;
        
        if (vA < vB) {
            p->next = pA;
            pA = pA->next;
        } else if (vA == vB) {
            p->next = pA;
            pA = pA->next;
            pB = pB->next;
        } else {
            p->next = pB;
            pB = pB->next;
        }
        if (lastValue == p->next->value) {
            p->next = NULL;
        } else {
            p = p->next;
            lastValue = p->value;
        }
    }
    p->next = pA ?: pB;
    return header;
}

Node * mergeRepeat(Node *listA, Node *listB) {
    Node *header = createNode(0);
    
    Node *pA = listA->next;
    Node *pB = listB->next;
    Node *p = header;
    
    while (pA != NULL && pB != NULL) {
        int vA = pA->value;
        int vB = pB->value;
        
        if (vA < vB) {
            p->next = pA;
            pA = pA->next;
        } else {
            p->next = pB;
            pB = pB->next;
        }
        p = p->next;
    }
    p->next = pA ?: pB;
    return header;
}

void intersection(Node *listA, Node *listB) {
    Node *pA = listA;
    Node *pB = listB;
    
    Node *nA = pA->next;
    Node *nB = pB->next;
    
    int lastValue = -10000;
    while (nA != NULL && nB != NULL) {
        int vA = nA->value;
        int vB = nB->value;
        
        if (vA < vB) {
            pA->next = nA->next;
            nA = pA->next;
        } else if (vA == vB) {
            if (lastValue != vA) {
                pA = nA;
                nA = pA->next;
                lastValue = vA;
            }
            pB = nB;
            nB = pB->next;
        } else {
            pB = nB;
            nB = pB->next;
        }
    }
    pA->next = NULL;
}

Node *difference(Node *listA, Node *listB, int *count) {
    Node *header = createNode(0);
    Node *p = header;
    
    Node *pA = listA->next;
    Node *pB = listB->next;
    
    int repeatValue = -10000;
    int lastValue = -10000;
    while (pA != NULL && pB != NULL) {
        int vA = pA->value;
        int vB = pB->value;
        
        if (vA < vB) {
            if (repeatValue == vA || lastValue == vA) {
                pA = pA->next;
            } else {
                p->next = pA;
                pA = pA->next;
                p = p->next;
                *count += 1;
                lastValue = vA;
            }
        } else if (vA == vB) {
            pA = pA->next;
            pB = pB->next;
            repeatValue = vA;
        } else {
            pB = pB->next;
        }
    }
    
    while (pA != NULL) {
        pA = pA->next;
        *count += 1;
    }
    
    return header;
}

void separate(Node *list, Node *listA, Node *listB) {
    Node *p = list->next;
    
    Node *pA = listA;
    Node *pB = listB;
    
    while (p != NULL) {
        int v = p->value;
        if (v < 0) {
            pA->next = p;
            pA = pA->next;
        } else if (v == 0) {
        } else {
            pB->next = p;
            pB = pB->next;
        }
        p = p->next;
    }
    pA->next = NULL;
    pB->next = NULL;
}

int getmax(Node *list) {
    Node *p = list->next;
    
    int result = -10000;
    while (p != NULL) {
        if (p->value > result) {
            result = p->value;
        }
    }
    return result;
}

void reverse(Node *list) {
    Node *p = list->next;
    list->next = NULL;
    while (p != NULL) {
        Node *n = p->next;
        p->next = list->next;
        list->next = p;
        p = n;
    }
}

void deleteBetween(Node *list, int min, int max) {
    Node *p = list;
    Node *n = p->next;
    
    while (n != NULL) {
        if (n->value >= min && n->value <= max) {
            p->next = n->next;
        } else {
            p = p->next;
        }
        n = p->next;
    }
}

void removeValue(int *array, int count, int value) {
    int idx = 0;
    while (idx < count && array[idx] != value) {
        idx++;
    }
    
    int find = idx != count ? 1 : 0;
    
    while (idx < count - find) {
        if (array[idx + find] == value) {
            find++;
        } else {
            array[idx] = array[idx + find];
            idx++;
        }
    }
    
    while (idx < count) {
        array[idx] = 0;
        idx++;
    }
}
