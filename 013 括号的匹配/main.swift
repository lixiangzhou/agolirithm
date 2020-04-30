import Foundation

struct Stack<E> {
    var top: Int
    var maxsize: Int
    var elems: [E?]
    
    init(_ maxsize: Int = 20) {
        self.maxsize = maxsize
        self.elems = Array<E?>(repeating: nil, count: maxsize)
        self.top = 0
    }
    
    mutating func clear() {
        top = 0
    }
    
    func isEmpty() -> Bool {
        return top == 0
    }
    
    func length() -> Int {
        return top
    }
    
    func getTop() -> E? {
        return top > 0 ? elems[top - 1] : nil
    }
    
    mutating func push(_ e: E) -> Bool {
        if top >= maxsize {
            return false
        }
        elems[top] = e
        top += 1
        return true
    }
    
    mutating func pop() -> E? {
        if top > 0 {
            let e = elems[top - 1]
            top -= 1
            return e
        }
        return nil
    }
    
    func traverse() {
        for i in 0..<top {
            print(elems[i]!, terminator: " ")
        }
        print()
    }
}

func match(_ string: String) -> Bool {
    let map: [Character: Character] = [")": "(", "]": "[", "}": "{"]
    
    var stack = Stack<Character>()
    
    for c in string {
        switch c {
        case "(", "[", "{":
            _ = stack.push(c)
        case ")", "]", "}":
            if stack.getTop() == map[c] {
                _ = stack.pop()
            } else {
                return false
            }
        default:
            break
        }
    }
    return stack.isEmpty()
}

print(match("[((({))})]"))


