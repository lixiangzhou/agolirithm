import Foundation

/// 把十进制数转换成特定进制数
/// - Parameters:
///   - decimal: 待转换的十进制数
///   - radix: 目的进制数
/// - Returns: 转换成的进制数
func convertDecimal(_ decimal: Int, to radix: Int) -> String {
    let index = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    var result = ""
    
    var decimal = decimal
    if decimal < 0 {
        result.append("-")
        decimal = -decimal
    }
    
    var array = [String]()
    let startIdx = index.startIndex
    while decimal != 0 {
        let reminder = decimal % radix
        decimal /= radix
        let c = index[index.index(startIdx, offsetBy: reminder)..<index.index(startIdx, offsetBy: reminder + 1)]
        array.append(String(c))
    }
    
    let count = array.count
    for i in 0..<count {
        result += array[count - i - 1]
    }
    return result
}


/// 将任意进制数转成十进制
/// - Parameters:
///   - num: 要转换的数
///   - radix: 转换数的进制
/// - Returns: 返回的十进制值
func convertToDecimal(_ num: String, radix: Int) -> Int {
    let index = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    
    let count = num.count
    let startIdx = index.startIndex
    var result = 0
    for (i, c) in num.enumerated() {
        let idx = index.firstIndex(of: c)!
        let distance = index.distance(from: startIdx, to: idx)
        
        result += distance * Int(pow(Double(radix), Double(count - i - 1)))
    }
    return result
}

print(convertDecimal(-100, to: 8))
print(convertToDecimal("64", radix: 16))
