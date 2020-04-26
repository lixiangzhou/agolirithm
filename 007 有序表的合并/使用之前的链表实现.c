#include <stdio.h>
#include <stdlib.h>

void * merge(LinkList *listA, LinkList *listB) {
    int lenA = length(listA);
    int lenB = length(listB);
    
    LinkList *listC = createList();
    
    int idxA = 0;
    int idxB = 0;
    
    while (idxA < lenA && idxB < lenB) {
        int valA, valB;
        getValue(listA, idxA, &valA);
        getValue(listB, idxB, &valB);
        if (valA <= valB) {
            append(listC, valA);
            idxA++;
        } else {
            append(listC, valB);
            idxB++;
        }
    }
    
    while (idxA < lenA) {
        int val;
        getValue(listA, idxA, &val);
        append(listC, val);
        idxA++;
    }
    
    while (idxB < lenB) {
        int val;
        getValue(listB, idxB, &val);
        append(listC, val);
        idxB++;
    }
    return listC;
}

int main() {
    LinkList *listA = createList();
    LinkList *listB = createList();
    
    int arrA[4] = {21, 32, 36, 88};
    int arrB[7] = {2, 15, 37, 99, 123, 345, 432};
    
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
    
    LinkList *listC = merge(listA, listB);
    printf("合并后数组：");
    traverse(listC);
    
    return 0;
}
