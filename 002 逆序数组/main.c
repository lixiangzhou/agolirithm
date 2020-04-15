#include <stdio.h>

void reverse(int *array, int len) {
    for (int i = 0; i < len / 2; i++) {
        // 交换数据
        array[i] ^= array[len - i - 1];
        array[len - i - 1] ^= array[i];
        array[i] ^= array[len - i - 1];
    }
}

int main(int argc, char* argv[]){
    
    int arr[6] = {12, 3, 2, 42, 23, 57};
    
    reverse(arr, 6);
    
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
    return 0;
}

