#include<iostream>
using namespace std;

void reverseArray(int array[], int len) {
    for (int i = 0; i < len / 2; i++) {
        array[i] ^= array[len - i - 1];
        array[len - i - 1] ^= array[i];
        array[i] ^= array[len - i - 1];
    }
}


int main(){
    int array[] = {1, 3, 5, 6, 2, 64, 23};
    int len = sizeof(array) / sizeof(int);
    reverseArray(array, len);
    
    for (int i = 0; i < len; i++) {
        if (i != 0) {
            cout << ", ";
        }
        cout << array[i];
    }
    cout << endl;
    
    cout << endl;
    return 0;
}
