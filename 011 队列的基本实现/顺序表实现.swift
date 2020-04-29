import Foundation

struct ArrayQueue<E> {
    var front = 0
    var rear = 0
    var elems: [E?]
    let size: Int
    
    init(size: Int = 6) {
        self.size = size
        self.elems = Array<E?>(repeating: nil, count: size)
    }
    
    var isEmpty: Bool {
        return front == rear
    }
    
    var isFull: Bool {
        return (rear + 1) % size == front
    }
    
    var length: Int {
        return (rear - front + size) % size
    }
    
    var head: E? {
        if isEmpty {
            return nil
        }
        return elems[front]
    }
    
    mutating func enQueue(_ e: E) {
        if !isFull {
            elems[rear] = e
            rear = (rear + 1) % size
        }
    }
    
    mutating func deQueue() -> E? {
        if !isEmpty {
            let e = elems[front]
            front = (front + 1) % size
            return e
        }
        return nil
    }
    
    func traverse() {
        if !isEmpty {
            var idx = front
            while idx != rear {
                print(elems[idx]!, terminator: " ")
                idx = (idx + 1) % size
            }
            print()
        }
    }
    
    func printInfo() {
        traverse()
        print("isEmpty: \(isEmpty)")
        print("isFull: \(isFull)")
        print("length: \(length)")
        print("head: \(head)")
    }
}

var queue = ArrayQueue<Int>()
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
