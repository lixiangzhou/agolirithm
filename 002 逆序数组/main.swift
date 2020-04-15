import Foundation

func reverse(_ array: inout [Int]) {
    let count = array.count
    let mid = count / 2
    for i in 0..<mid {
        // 交换数据
        array[i] ^= array[count - 1 - i]
        array[count - 1 - i] ^= array[i]
        array[i] ^= array[count - 1 - i]
    }
}

var array = [1, 3, 5, 2, 6, 8, 9]

reverse(&array)

print(array)
