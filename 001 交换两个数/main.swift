import Foundation

func swap1(num1: inout Int, num2: inout Int) {
    let temp = num1
    num1 = num2
    num2 = temp
}

func swap2(num1: inout Int, num2: inout Int) {
    num1 ^= num2
    num2 ^= num1
    num1 ^= num2
}

func swap3(num1: inout Int, num2: inout Int) {
    num1 = num1 + num2
    num2 = num1 - num2
    num1 = num1 - num2
}

func swap4(num1: inout Int, num2: inout Int) {
    num1 = num1 * num2
    num2 = num1 / num2
    num1 = num1 / num2
}

// 语言特性
func swap5(num1: inout Int, num2: inout Int) {
    (num1, num2) = (num2, num1)
}

var a = 10
var b = 20

swap4(num1: &a, num2: &b)

print(a, b)
