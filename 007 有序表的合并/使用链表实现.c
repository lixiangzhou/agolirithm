#include <stdio.h>
#include <stdlib.h>

// 合并到一个新的链表中
void merge(LinkList *listA, LinkList *listB, LinkList *listC) {
    Node *pA = listA->next;
    Node *pB = listB->next;
    Node *pC = listC;
    
    while (pA != NULL && pB != NULL) {
        if (pA->value < pB->value) {
            pC->next = pA;
            pA = pA->next;
        } else {
            pC->next = pB;
            pB = pB->next;
        }
        pC = pC->next;
    }
    
    if (pA != NULL) {
        pC->next = pA;
    }
    
    if (pB != NULL) {
        pC->next = pB;
    }
}

// 合并到一个链表 listA 中
void merge2(LinkList *listA, LinkList *listB) {
    Node *pA = listA;
    Node *pB = listB;
    
    Node *nA = pA->next;
    Node *nB = pB->next;
    
    while (nA != NULL && nB != NULL) {
        
        if (nA->value < nB->value) {
            pA = nA;
            nA = pA->next;
        } else {
            pB->next = nB->next;
            
            pA->next = nB;
            nB->next = nA;
            pA = nB;
            
            nB = pB->next;
        }
    }
    
    if (nB != NULL) {
        pA->next = nB;
    }
}

int main() {
    int arrA[4] = {21, 32, 36, 88};
    int arrB[7] = {2, 15, 37, 99, 123, 345, 432};
    
    
    LinkList *listA = createList();
    LinkList *listB = createList();
    LinkList *listC = createList();
    
    for (int i = 0; i < 4; i++) {
        append(listA, arrA[i]);
    }
    
    for (int i = 0; i < 7; i++) {
        append(listB, arrB[i]);
    }
    
    printf("数组A：");
    traverse(listA);
    printf("数组B：");
    traverse(listB);
    
    merge(listA, listB, listC);
    printf("合并后数组：");
    traverse(listC);
    
//    merge2(listA, listB);
//    printf("合并后数组：");
//    traverse(listA);
    
    return 0;
}
