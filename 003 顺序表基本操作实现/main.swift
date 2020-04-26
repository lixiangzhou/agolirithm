import Foundation

struct List<E: Equatable> {
    var list: [E?]
    var _length: Int
    
    init(size: UInt) {
        list = Array<E?>(repeating: nil, count: Int(size))
        _length = 0
    }
    
    mutating func insert(at idx: UInt, value: E) -> Bool {
        if idx > _length || _length == list.count {
            return false
        } else {
            let range = (Int(idx)..<_length).reversed()
            for i in range {
                list[i + 1] = list[i]
            }
            list[Int(idx)] = value
            _length += 1
            return true
        }
    }
    
    mutating func append(_ value: E) -> Bool {
        return insert(at: UInt(_length), value: value)
    }
    
    mutating func delete(at idx: UInt) -> Bool {
        if idx >= _length {
            return false
        } else {
            let range = Int(idx)..<_length - 1
            for i in range {
                list[i] = list[i + 1]
            }
            _length -= 1
            return true
        }
    }
    
    mutating func update(at idx: UInt, value: E) -> Bool {
        if idx >= _length {
            return false
        } else {
            list[Int(idx)] = value
            return true
        }
    }
    
    func getIndex(of value: E) -> Int? {
        
        for (idx, val) in list[..<_length].enumerated() {
            if value == val {
                return idx
            }
        }
        return nil
    }
    
    func getValue(of idx: UInt) -> E? {
        if idx >= _length {
            return nil
        } else {
            return list[Int(idx)]
        }
    }
    
    func length() -> Int {
        return _length;
    }
    
    mutating func clear() {
        _length = 0
    }
    
    func traverse() {
        for v in list[..<_length] {
            print(v!, terminator: " ")
        }
        print()
    }
}

var list = List<Int>(size: 10)

for _ in 0..<5 {
    list.append(Int.random(in: 0..<20))
}

list.traverse()

list.insert(at: 5, value: 30)
list.traverse()

list.delete(at: 2)
list.traverse()

list.update(at: 1, value: 100)
list.traverse()

print(list.getIndex(of: 100))
print(list.getValue(of: 3))
