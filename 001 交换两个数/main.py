#-*- encoding:utf-8 -*-


def swap(num1, num2):
    temp = num1
    num1 = num2
    num2 = temp
    return num1, num2

def swap2(num1, num2):
    num1 = num1 + num2
    num2 = num1 - num2
    num1 = num1 - num2
    return num1, num2

def swap3(num1, num2):
    num1 = num1 * num2
    num2 = num1 / num2
    num1 = num1 / num2
    return num1, num2

def swap4(num1, num2):
    num1 ^= num2
    num2 ^= num1
    num1 ^= num2
    return num1, num2

def swap5(num1, num2):
    return num2, num1

if __name__ == "__main__":
    num1 = 10
    num2 = 20
    num1, num2 = swap5(num1, num2)
    
    print(num1, num2)