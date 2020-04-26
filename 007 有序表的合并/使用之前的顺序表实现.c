#include <stdio.h>
#include <stdlib.h>

void * merge(List *listA, List *listB) {
    int lenA = length(listA);
    int lenB = length(listB);
    
    List *listC = createList(length(listA) + length(listB));
    
    int idxA = 0;
    int idxB = 0;
    
    while (idxA < lenA && idxB < lenB) {
        int valA = getvalue(listA, idxA);
        int valB = getvalue(listB, idxB);
        if (valA <= valB) {
            append(listC, valA);
            idxA++;
        } else {
            append(listC, valB);
            idxB++;
        }
    }
    
    while (idxA < lenA) {
        append(listC, getvalue(listA, idxA));
        idxA++;
    }
    
    while (idxB < lenB) {
        append(listC, getvalue(listB, idxB));
        idxB++;
    }
    return listC;
}

int main() {
    List *listA = createList(100);
    List *listB = createList(100);
    
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
    
    List *listC = merge(listA, listB);
    printf("合并后数组：");
    traverse(listC);
    
    return 0;
}
