import Foundation

struct MyArray<T: Equatable> {
    private var array: Array<T>
    private var _length = 0;
    
    init(_ initialValue: T, count: Int) {
        array = Array<T>(repeating: initialValue, count: count);
    }
    
    func get(at idx: Int) -> (isSuccess: Bool, result: T?) {
        if idx < 0 || idx >= _length {
            return (false, nil)
        }
        return (true, array[idx])
    }
    
    func index(of value: T) -> Int? {
        for (idx, e) in array.enumerated() {
            if e == value {
                return idx
            }
        }
        return nil
    }
    
    mutating func insert(_ value: T, at idx: Int) -> Bool {
        if idx < 0 || idx > _length || _length == array.count {
            return false
        }
        
//        swift 方法
//        array.insert(value, at: idx)
        
        let range = idx..<_length
        
        for i in range.reversed() {
            array[i + 1] = array[i]
        }
        
        array[idx] = value
        _length += 1
        
        return true
    }
    
    mutating func remove(at idx: Int) -> Bool {
        if idx < 0 || idx >= _length {
            return false
        }
        
        for i in idx..<_length {
            array[i] = array[i + 1]
        }
        
        _length -= 1
        
        return true
    }
    
    func length() -> Int {
        return _length
    }
    
    func isEmpty() -> Bool {
        return _length == 0
    }
    
    func traverse() {
        for v in array[0..<_length] {
            print(v)
        }
    }
    
    mutating func clear() {
        _length = 0
    }
}

var array = MyArray(0, count: 5)

print(array.get(at: 0))

array.insert(9, at: 0)
array.insert(4, at: 0)
array.insert(1, at: 0)
array.insert(93, at: 0)
array.insert(23, at: 0)
array.insert(43, at: 5)

array.traverse()

print(array.index(of: 1))
print(array.get(at: 4).result)
