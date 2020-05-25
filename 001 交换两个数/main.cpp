#include<iostream>
using namespace std;

void swapValue(int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void swapValue2(int& num1, int& num2) {
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
}

void swapValue3(int& num1, int& num2) {
    num1 = num1 * num2;
    num2 = num1 / num2;
    num1 = num1 / num2;
}

void swapValue4(int& num1, int& num2) {
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
}



int main(){
    int a = 10;
    int b = 20;
    
    swapValue3(a, b);
    
    cout << a << ", " << b << endl;
    
    cout << endl;
    return 0;
}
