import Foundation

class Node<E: Equatable>: Equatable {
    static func == (lhs: Node<E>, rhs: Node<E>) -> Bool {
        return lhs.value == rhs.value && rhs.next === lhs.next
    }
    
    var value: E?
    var next: Node?
}

struct LinkQueue<E: Equatable> {
    var front: Node<E>?
    var rear: Node<E>?
    
    private(set) var length: Int = 0
    
    init() {
        front = Node<E>()
        rear = front
    }
    
    var isEmpty: Bool {
        return front == rear
    }
    
    var head: E? {
        return front?.next?.value
    }
    
    mutating func enQueue(_ e: E) {
        let node = Node<E>()
        node.value = e
        rear?.next = node
        rear = node
        length += 1
    }
    
    mutating func deQueue() -> E? {
        if !isEmpty {
            let p = front?.next
            let e = p?.value
            front?.next = p?.next
            if p == rear {
                rear = front
            }
            length -= 1
            return e
        }
        return nil
    }
    
    func traverse() {
        var p = front?.next
        while p != nil {
            print(p!.value!, terminator: " ")
            p = p?.next
        }
        print()
    }
    
    func printInfo() {
        traverse()
        print("isEmpty: \(isEmpty)")
        print("length: \(length)")
        print("head: \(head)")
    }
}

var queue = LinkQueue<Int>()
queue.printInfo()

queue.enQueue(12)
queue.enQueue(34)
queue.enQueue(3)
queue.printInfo()

queue.enQueue(19)
queue.enQueue(20)
queue.printInfo()

queue.enQueue(440)
queue.printInfo()

print(queue.deQueue())
queue.printInfo()
