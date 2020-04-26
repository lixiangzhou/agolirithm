import Foundation

func merge(_ listA: [Int], _ listB: [Int]) -> [Int] {
    let lenA = listA.count
    let lenB = listB.count
    
    var listC = Array<Int>(repeating: 0, count: lenA + lenB)
    
    var idxA = 0
    var idxB = 0
    
    while idxA < lenA && idxB < lenB {
        let valA = listA[idxA]
        let valB = listB[idxB]
        
        if valA < valB {
            listC[idxA + idxB] = valA
            idxA += 1
        } else {
            listC[idxA + idxB] = valB
            idxB += 1
        }
    }
    
    while idxA < lenA {
        listC[idxA + idxB] = listA[idxA]
        idxA += 1
    }
    
    while idxB < lenB {
        listC[idxA + idxB] = listB[idxB]
        idxB += 1
    }
    
    return listC
}

func traverse(_ array: [Int]) {
    for v in array {
        print(v, terminator: " ")
    }
    print()
}

// 测试数据
var arrA = [Int]()
var arrB = [Int]()

for _ in 0..<6 {
    arrA.append(Int.random(in: 0..<30))
}

for _ in 0..<9 {
    arrB.append(Int.random(in: 0..<90))
}

let listA = arrA.sorted()
let listB = arrB.sorted()

print("数组A：")
traverse(listA)
print("数组B：")
traverse(listB)

print("合并后数组：")
let listC = merge(listA, listB)
traverse(listC)
