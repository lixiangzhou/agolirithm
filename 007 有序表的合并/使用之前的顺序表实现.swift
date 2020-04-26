import Foundation

func merge(_ listA: List<Int>, _ listB: List<Int>) -> List<Int> {
    let lenA = listA.length()
    let lenB = listB.length()
    
    var listC = List<Int>(size: UInt(lenA + lenB))
    
    var idxA: UInt = 0
    var idxB: UInt = 0
    
    while idxA < lenA && idxB < lenB {
        let valA = listA.getValue(of: idxA)!
        let valB = listB.getValue(of: idxB)!
        
        if valA < valB {
            _ = listC.append(valA)
            idxA += 1
        } else {
            _ = listC.append(valB)
            idxB += 1
        }
    }
    
    while idxA < lenA {
        _ = listC.append(listA.getValue(of: idxA)!)
        idxA += 1
    }
    
    while idxB < lenB {
        _ = listC.append(listB.getValue(of: idxB)!)
        idxB += 1
    }
    return listC
}

// 测试数据
var listA = List<Int>(size: 6)
var listB = List<Int>(size: 9)

var arrA = [Int]()
var arrB = [Int]()

for _ in 0..<6 {
    arrA.append(Int.random(in: 0..<30))
}

for _ in 0..<9 {
    arrB.append(Int.random(in: 0..<90))
}

for v in arrA.sorted() {
    _ = listA.append(v)
}

for v in arrB.sorted() {
    _ = listB.append(v)
}

print("数组A：")
listA.traverse()
print("数组B：")
listB.traverse()

print("合并后数组：")
let listC = merge(listA, listB)
listC.traverse()
