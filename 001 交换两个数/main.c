#include <stdio.h>

// 使用临时变量
void swap1(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// 不使用临时变量，使用位运算，速度快
void swap2(int *num1, int *num2) {
    *num1 ^= *num2;
    *num2 ^= *num1;
    *num1 ^= *num2;
}

// 注意：*num1 + *num2 的大小不能确定，有可能超出类型范围
void swap3(int *num1, int *num2) {
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}

// 注意：*num1 * *num2 的大小不能确定，有可能超出类型范围
void swap4(int *num1, int *num2) {
    *num1 = *num1 * *num2;
    *num2 = *num1 / *num2;
    *num1 = *num1 / *num2;
}

int main(int argc, char* argv[]){
    
    int a = 10;
    int b = 20;
    
    swap4(&a, &b);
    
    printf("a = %d, b = %d \n", a, b);
    
    return 0;
}

