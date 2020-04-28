import Foundation

class Node<E> {
    var value: E?
    var next: Node?
}

struct Stack<E> {
    let maxsize: Int
    var top: Node<E>?
    private(set) var length = 0
    
    init(_ maxsize: Int = 20) {
        self.maxsize = maxsize
    }
    
    mutating func clear() {
        length = 0
        top = nil
    }
    
    func isEmpty() -> Bool {
        return top == nil
    }
    
    func getTop() -> E? {
        return top?.value
    }
    
    mutating func push(_ e: E) -> Bool {
        if length >= maxsize {
            return false
        }
        let node = Node<E>()
        node.value = e
        node.next = top
        
        top = node
        length += 1
        return true
    }
    
    mutating func pop() -> E? {
        let v = top?.value
        top = top?.next
        
        if length > 0 {
            length -= 1
        }
        return v
    }
    
    func traverse() {
        var values = [E]()
        
        var n = top
        while n != nil {
            values.append(n!.value!)
            n = n?.next
        }
        for v in values.reversed() {
            print(v, terminator: " ")
        }
        print()
    }
}

var stack = Stack<Int>()

for _ in 0..<20 {
    let v = Int.random(in: 0..<100)
    print(v, terminator: " ")
    stack.push(v)
}
print()

stack.traverse()

print(stack.getTop())
print(stack.isEmpty())
print(stack.length)

print(stack.pop())
stack.traverse()
print(stack.getTop())
print(stack.isEmpty())
print(stack.length)


stack.clear()
stack.traverse()
print(stack.isEmpty())
print(stack.length)

print(stack.pop())
stack.traverse()
print(stack.getTop())
print(stack.isEmpty())
print(stack.length)

