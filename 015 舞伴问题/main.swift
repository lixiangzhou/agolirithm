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
}


var mQueue = ArrayQueue<Int>(size: 25)
var fQueue = ArrayQueue<Int>(size: 25)

// 随机生成20个数，偶数代表男性，计数代表女性
for _ in 0..<20 {
    let v = Int.random(in: 0..<100)
    if v % 2 == 0 {
        mQueue.enQueue(v)
    } else {
        fQueue.enQueue(v)
    }
}

print("男性：")
mQueue.traverse()
print("女性：")
fQueue.traverse()

//var partner = [(Int, Int)]()
while mQueue.head != nil, fQueue.head != nil {
    print(mQueue.deQueue()!, fQueue.deQueue()!)
//    partner.append((mQueue.deQueue()!, fQueue.deQueue()!))
}


if let m = mQueue.head {
    print("男性等着呢：", m)
}

if let f = fQueue.head {
    print("女性等着呢：", f)
}
