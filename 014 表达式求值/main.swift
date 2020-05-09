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
    
    func isEmpty() -> Bool {
        return top == 0
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
}

enum OpCase {
    case big
    case small
    case equal
    case other
}

func precade(_ top: String, cur: String) -> OpCase {
    switch (top, cur) {
    case ("+", "*"), ("+", "/"), ("+", "("), ("-", "*"), ("-", "/"), ("-", "("), ("*", "("), ("/", "("), ("(", "+"), ("(", "-"), ("(", "*"), ("(", "/"), ("(", "("), ("#", "+"), ("#", "-"), ("#", "*"), ("#", "/"), ("#", "("):
        return .small
    case ("+", "+"), ("+", "-"), ("+", ")"), ("-", "+"), ("-", "-"), ("-", ")"), ("*", "+"), ("*", "-"), ("*", "*"), ("*", "/"), ("*", ")"), ("/", "+"), ("/", "-"), ("/", "*"), ("/", "/"), ("/", ")"), (")", "+"), (")", "-"), (")", "*"), (")", "/"), (")", ")"), ("+", "#"), ("-", "#"), ("*", "#"), ("/", "#"), (")", "#"):
        return .big
    case ("(", ")"), ("#", "#"):
        return .equal
    default:
        return .other
    }
}

func operate(_ num1: Int, _ op: String, _ num2: Int) -> Int {
    switch op {
    case "+":
        return num1 + num2
    case "-":
        return num1 - num2
    case "*":
        return num1 * num2
    default:
        return num1 / num2
    }
}

func exper(_ string: String) -> Int? {
    var opStack = Stack<String>()
    _ = opStack.push("#")
    var numStack = Stack<Int>()
    
    var subs = string.split(separator: " ")
    subs.append("#")
    
    var idx = 0
    while idx < subs.count {
        let s = String(subs[idx])
        
        switch s {
        case "+", "-", "*", "/", "(", ")", "#":
            let opcase = precade(opStack.getTop() ?? " ", cur: s)
            switch opcase {
            case .small:
                _ = opStack.push(s)
            case .big:
                if let op = opStack.pop(),
                    let num2 = numStack.pop(),
                    let num1 = numStack.pop() {
                    _ = numStack.push(operate(num1, op, num2))
                    continue
                }
            case .equal:
                _ = opStack.pop()
            default:
                return nil
            }
        default:
            if let int = Int(s) {
                _ = numStack.push(int)
            } else {
                return nil
            }
        }
        
        idx += 1
    }
    
    return numStack.pop()
}

print(exper("1 + 3 * 4 + 2 * 4 * 1"))


