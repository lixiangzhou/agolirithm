import Foundation

class Node {
    var coef: Int = 0
    var expn: Int = 0
    var next: Node?
}

/// 创建多项式
func createPolyn() -> Node {
    let header = Node()
    
    for _ in 0..<8 {
        // 生成一项数据
        let coef = Int.random(in: 0..<20)
        let expn = Int.random(in: 0..<30)
        
        // 找到要插入的节点
        var p: Node? = header
        var n = p?.next
        while n != nil && expn > n!.expn {
            p = n
            n = p?.next
        }
        
        // 如果要插入的下一个节点和本身指数相同，不必插入，常数相加，否则插入
        if let next = n, next.expn == expn {
            next.coef += coef
        } else {
            let node = Node()
            node.expn = expn
            node.coef = coef
            
            p?.next = node
            node.next = n
        }
    }
    
    return header
}

/// 打印多项式
func printPolyn(_ header: Node) {
    var string = [String]()
    
    var p = header.next
    while p != nil {
        string.append("\(p!.coef)^\(p!.expn)")
        p = p?.next
    }
    
    print(string.joined(separator: " + "))
}

/// 多项式相加
func addPolyn(_ p1: Node, _ p2: Node) -> Node {
    let header = Node()
    var p: Node? = header
    
    var pA = p1.next
    var pB = p2.next
    
    while pA != nil, pB != nil {
        let eA = pA!.expn
        let eB = pB!.expn
        
        if eA < eB {
            p?.next = pA
            pA = pA?.next
        } else if eA == eB {
            pA!.coef += pB!.coef

            p?.next = pA
            pA = pA?.next
            pB = pB?.next
        } else {
            p?.next = pB
            pB = pB?.next
        }
        p = p?.next
    }
    
    p?.next = pA ?? pB
    
    return header
}

let p1 = createPolyn()
let p2 = createPolyn()

printPolyn(p1)
printPolyn(p2)

let result = addPolyn(p1, p2)
printPolyn(result)
