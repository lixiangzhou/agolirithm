#-*- encoding:utf-8 -*-

def reverseValue(array):
    length = len(array)
    mid = length // 2
    for i in range(mid):
        array[i] ^= array[length - 1 - i]
        array[length - 1 - i] ^= array[i]
        array[i] ^= array[length - 1 - i]

if __name__ == "__main__":
    
    arr = [1, 3, 5, 6, 2, 64, 23]
    
    reverseValue(arr)
    
    print(arr)