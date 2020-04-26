import Foundation

class LinkList<T: Equatable> {
    class Node<T> {
        var value: T? = nil
        var next: Node<T>? = nil
    }

    private let header = Node<T>()
    private var length = 0
    
    func insert(_ value: T, at idx: UInt) {
        var p: Node<T>? = header
        var i: UInt = 0
        while p != nil && i < idx {
            p = p?.next
            i += 1
        }
        
        if p != nil && i == idx {
            let n = Node<T>()
            n.next = p?.next
            n.value = value
            
            p?.next = n
            length += 1
        } else {
            print("插入失败")
        }
    }
    
    func append(_ value: T) {
        insert(value, at: UInt(length))
    }
    
    func delete(at idx: UInt) {
        var p: Node<T>? = header
        var i: UInt = 0
        while p != nil && i < idx {
            p = p?.next
            i += 1
        }
        let next = p?.next
        if next != nil && i == idx {
            p?.next = next?.next
            length -= 1
        } else {
            print("删除失败")
        }
    }
    
    func update(value: T, at idx: UInt) {
        var p: Node<T>? = header.next
        var i: UInt = 0
        while p != nil && i < idx {
            p = p?.next
            i += 1
        }
        if p != nil && i == idx {
            p?.value = value
        } else {
            print("更新失败")
        }
    }
    
    func getValue(of idx: UInt) -> T? {
        var p: Node<T>? = header.next
        var i: UInt = 0
        while p != nil && i < idx {
            p = p?.next
            i += 1
        }
        if p != nil && i == idx {
            return p?.value
        } else {
            return nil
        }
    }
    
    func getIndex(of value: T) -> UInt? {
        var p: Node<T>? = header.next
        var i: UInt = 0
        while p != nil {
            if p?.value == value {
                return i
            }
            p = p?.next
            i += 1
        }
        return nil
    }
    
    func clear() {
        header.next = nil
        length = 0
    }
    
    func traverse() {
        var p = header.next
        while p != nil {
            print(p!.value!, terminator: " ")
            p = p?.next
        }
        print()
    }
}

let list = LinkList<Int>()
list.traverse()

for _ in 0..<10 {
    let value = Int.random(in: 1...20)
    print(value, terminator: " ")
    list.append(value)
}
print()
list.traverse()

list.delete(at: 3)
list.traverse()

list.update(value: 100, at: 7)
list.traverse()

print(list.getValue(of: 7))

print(list.getIndex(of: 100))
