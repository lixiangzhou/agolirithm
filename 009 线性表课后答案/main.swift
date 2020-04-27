import Foundation

/**
 (1 )将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来两个链表
 的存储空间，不另外占用其他的存储空间。表中不允许有重复的数据。
 
 (2)将两个非递减的有序链表合并为一个非递增的有序链表。要求结果链表仍使用原来两个
 链表的存储空间，不另外占用其他的存储空间。表中允许有重复的数据。
 
 (3)已知两个链表A和B分别表示两个集合，其元素递增排列。请设计一个算法，用千求出
 A与B的交集，并存放在A链表中。
 
 (4)巳知两个链表 A和 B分别表示两个集合，其元素递增排列。请设计算法 求出两个集合 A
 和B 的差集（即仅由在A中出现而不在B中出现的元素所构成的集合），并以同样的形式存储，
 同时返回该集合的元素个数。
 
 (5)设计算法将一个带头结点的单链表A分解为两个具有相同结构的链表B和C, 其中B
 表的结点为 A 表中值小于零的结点，而 C 表的结点为 A 表中值大于零的结点（链表 A中的元素
 为非零整数，要求 B 、 C表利用 A 表的结点）。
 
 (6)设计一个算法，通过一趟遍历确定长度为 n的单链表中值最大的结点。
 
 (7)设计一个算法，将链表中所有结点的链接方向 “原地” 逆转，即要求仅利用原表的存储
 空间，换句话说，要求算法的空间复杂度为 0(1)。
 
 (8)设计一个算法，删除递增有序链表中值大于mink且小于maxk:的所有元素(mink和 maxk
 是给定的两个参数，其值可以和表中的元素相同，也可以不同）。
 
 (9)巳知 p指向双向循环链表中的一个结点，其结点结构为data、prior、next三个域，写出
 算法change(p), 交换p所指向的结点及其前驱结点的顺序。
 
 (10)已知长度为 n的线性表A采用顺序存储结构，请写一个时间复杂度为O(n)、空间复杂
 度为0(1)的算法，该算法可删除线性表中所有值为 item的数据元素。
 */

class Node {
    var value: Int = 0
    var next: Node?
}

func createList(_ size: Int, min: Int = 0, max: Int = 100, sorted: Bool = true, repeated: Bool = true) -> Node {
    let header = Node()
    
    var p: Node? = header
    for _ in 0..<size {
        let node = Node()
        node.value = Int.random(in: min..<max)
        
        if sorted {
            p = header
            var n = p?.next
            while n != nil && node.value > n!.value {
                p = n
                n = p?.next
            }
            
            if !repeated, let next = n, next.value == node.value {
                
            } else {
                p?.next = node
                node.next = n
            }
        } else {
            if !repeated {
                var p: Node? = header.next
                while p != nil, p!.value != node.value {
                    p = p?.next
                }
                if p == nil {
                    p?.next = node
                    p = p?.next
                }
            } else {
                p?.next = node
                p = p?.next
            }
        }
    }
    return header
}

func printList(_ header: Node) {
    var p = header.next
    while p != nil {
        print("\(p!.value) ", terminator: " ")
        p = p?.next
    }
    print()
}


/// 第一题和第二题
func test1_2() {
    let isFirst = true
    func merge(_ listA: Node, _ listB: Node) -> Node {
        let header = Node()
        
        var pA = listA.next
        var pB = listB.next
        
        var p: Node? = header
        
        while pA != nil && pB != nil {
            let vA = pA!.value
            let vB = pB!.value
            
            // 第一题和第二题的差异在这里
            if isFirst { // 第一题
                if vA < vB {
                    p?.next = pA
                    pA = pA?.next
                } else if vA == vB {
                    p?.next = pA
                    pA = pA?.next
                    pB = pB?.next
                } else {
                    p?.next = pB
                    pB = pB?.next
                }
            } else { // 第二题
                if vA < vB {
                    p?.next = pA
                    pA = pA?.next
                } else {
                    p?.next = pB
                    pB = pB?.next
                }
            }
            p = p?.next
        }
        p?.next = pA ?? pB
        return header
    }
    
    // 创建两个有序列表
    let list1 = createList(10)
    let list2 = createList(10)
    
    printList(list1)
    printList(list2)
    
    let result = merge(list1, list2)
    printList(result)
}
//test1_2()


/// 第三题
func test3() {
    func intersection(_ listA: Node, _ listB: Node) -> Node {
        let header = Node()
        
        var pA = listA.next
        var pB = listB.next
        var p: Node? = header
        
        while pA != nil && pB != nil {
            let vA = pA!.value
            let vB = pB!.value
            
            if vA < vB {
                pA = pA?.next
            } else if vA == vB {
                p?.next = pA
                pA = pA?.next
                pB = pB?.next
                
                p = p?.next
            } else {
                pB = pB?.next
            }
        }
        p?.next = nil
        return header
    }
    
    // 创建两个有序列表
    let list1 = createList(10, max: 10, repeated: false)
    let list2 = createList(10, max: 10, repeated: false)
    
    printList(list1)
    printList(list2)
    
    let result = intersection(list1, list2)
    printList(result)
}
//test3()

/// 第四题
func test4() {
    func difference(_ listA: Node, _ listB: Node) -> (Node, Int) {
        let header = Node()
        
        var pA = listA.next
        var pB = listB.next
        var p: Node? = header
        
        var count = 0
        while pA != nil && pB != nil {
            let vA = pA!.value
            let vB = pB!.value
            
            if vA < vB {
                p?.next = pA
                pA = pA?.next
                
                p = p?.next
                count += 1
            } else if vA == vB {
                pA = pA?.next
                pB = pB?.next
            } else {
                pB = pB?.next
            }
        }
        while pA != nil {
            p?.next = pA
            pA = pA?.next
            p = p?.next
            count += 1
        }
        return (header, count)
    }
    
    // 创建两个有序列表
    let list1 = createList(10, max: 20, repeated: false)
    let list2 = createList(10, max: 10, repeated: false)
    
    printList(list1)
    printList(list2)
    
    let result = difference(list1, list2)
    printList(result.0)
    print(result.1)
}
//test4()

/// 第五题
func test5() {
    func separate(_ list: Node) -> (Node, Node) {
        let listA = Node()
        let listB = Node()
        
        var pA: Node? = listA
        var pB: Node? = listB
        var p = list.next
        
        while p != nil {
            let value = p!.value
            if value < 0 {
                pA?.next = p
                p = p?.next
                pA = pA?.next
            } else if value == 0 {
                p = p?.next
            } else {
                pB?.next = p
                p = p?.next
                pB = pB?.next
            }
        }
        pA?.next = nil
        pB?.next = nil
        
        return (listA, listB)
    }
    
    let list = createList(20, min: -100, max: 100, sorted: false, repeated: true)
    printList(list)
    
    let (list1, list2) = separate(list)
    printList(list1)
    printList(list2)
}
//test5()

/// 第六题
func test6() {
    func max(_ list: Node) -> Int {
        var result = 0
        var p: Node? = list.next
        
        while p != nil {
            if p!.value > result {
                result = p!.value
            }
            p = p?.next
        }
        return result
    }
    
    let list = createList(30, min: 0, max: 100, sorted: false, repeated: true)
    printList(list)
    
    print(max(list))
}
//test6()

/// 第七题
func test7() {
    func reverse(_ list: Node) {
        var p = list.next
        list.next = nil
        
        while p != nil {
            let pNext = p?.next
            p?.next = list.next
            list.next = p
            p = pNext
        }
    }
    
    let list = createList(10, max: 20, sorted: true, repeated: false)
    printList(list)
    
    reverse(list)
    printList(list)
}
//test7()

/// 第八题
func test8() {
    func deleteBetween(min: Int, max: Int, in list: Node) {
        var p: Node? = list
        var n = p?.next
        
        while n != nil {
            let v = n!.value
            if v > min && v < max {
                p?.next = n?.next
                n = p?.next
            } else {
                p = n
                n = p?.next
            }
        }
    }
    
    let list = createList(10, max: 50, sorted: true, repeated: false)
    printList(list)
    
    deleteBetween(min: 20, max: 40, in: list)
    printList(list)
}
//test8()

func test9() {
    
}
//test9()

func test10() {
    func delete(_ value: Int, in list: inout [Int]) {
        let count = list.count
        var i = 0
        while i < count && list[i] != value {
            i += 1
        }
        var find = i < count - 1 ? 1 : 0
        
        while i < count - find {
            if list[i + find] == value {
                find += 1
            } else {
                list[i] = list[i + find]
                i += 1
            }
        }
        
        
        list.removeLast(find)
    }
    
    var array = [Int]()
    for _ in 0..<10 {
        let v = Int.random(in: 0..<5)
        array.append(v)
        print(v, terminator: " ")
    }
    print()

    print()
    delete(3, in: &array)
    for v in array {
        print(v, terminator: " ")
    }
    print()
}
test10()
