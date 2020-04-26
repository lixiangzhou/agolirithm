import Foundation

func merge(_ listA: LinkList<Int>, from listB: LinkList<Int>) {
    var pA: Node<Int>? = listA.header
    let pB: Node<Int>? = listB.header
    
    var nA = pA?.next
    var nB = pB?.next
    
    while nA != nil && nB != nil {
        if nA!.value! < nB!.value! {
            pA = nA
            nA = pA?.next
        } else {
            pB?.next = nB?.next
            
            pA?.next = nB
            nB?.next = nA
            pA = nB
            
            nB = pB?.next
        }
    }
    
    if let nB = nB {
        pA?.next = nB
    }
}

func merge(_ listA: LinkList<Int>, _ listB: LinkList<Int>) -> LinkList<Int> {
    var pA: Node<Int>? = listA.header.next
    var pB: Node<Int>? = listB.header.next
    
    let listC = LinkList<Int>()
    var pC: Node<Int>? = listC.header
    
    while pA != nil && pB != nil {
        if pA!.value! < pB!.value! {
            pC?.next = pA
            pA = pA?.next
        } else {
            pC?.next = pB
            pB = pB?.next
        }
        pC = pC?.next
    }
    
    if let pB = pB {
        pC?.next = pB
    }
    
    return listC
}

// 测试数据
var arrA = [Int]()
var arrB = [Int]()

for _ in 0..<6 {
    arrA.append(Int.random(in: 0..<40))
}

for _ in 0..<9 {
    arrB.append(Int.random(in: 0..<90))
}

let listA = LinkList<Int>()
let listB = LinkList<Int>()

for v in arrA.sorted() {
    listA.append(v)
}

for v in arrB.sorted() {
    listB.append(v)
}


print("数组A：")
listA.traverse()
print("数组B：")
listB.traverse()

//print("合并后数组：")
//merge(listA, from: listB)
//listA.traverse()

print("合并后数组：")
let listC = merge(listA, listB)
listC.traverse()
