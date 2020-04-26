#include <stdio.h>

void merge(int *arrA, int lenA, int *arrB, int lenB, int *arrC) {
    int idxA = 0;
    int idxB = 0;
    
    while (idxA < lenA && idxB < lenB) {
        int valA = arrA[idxA];
        int valB = arrB[idxB];
        
        if (valA < valB) {
            arrC[idxA + idxB] = valA;
            idxA++;
        } else {
            arrC[idxA + idxB] = valB;
            idxB++;
        }
    }
    
    while (idxA < lenA) {
        arrC[idxA + idxB] = arrA[idxA];
        idxA++;
    }
    while (idxB < lenB) {
        arrC[idxA + idxB] = arrB[idxB];
        idxB++;
    }
}

void traverse(int *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int arrA[4] = {21, 32, 36, 88};
    int arrB[7] = {2, 15, 37, 99, 123, 345, 432};
    int arrC[11] = {};
    
    
    printf("数组A：");
    traverse(arrA, 4);
    printf("数组B：");
    traverse(arrB, 7);
    
    
    merge(arrA, 4, arrB, 7, arrC);
    printf("合并后数组：");
    traverse(arrC, 11);
    
    return 0;
}
