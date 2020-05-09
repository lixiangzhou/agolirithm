import Foundation

/*
(1)将编号为0和1的两个栈存放于一个数组空间V[m]中，栈底分别处千数组的两端。
 当第0号栈的栈顶指针 top[0]等于-1时该栈为空；当第1号栈的栈顶指针top[l]等于m时，该栈为空。
 两个栈均从两端向中间增长。试编写双栈初始化，判断栈空、栈满、进栈和出栈等算法的函数。双栈数据结构的定义如下：
 typedef struct {
    int top[2], bot[2];
    SElemType *V;
    int m;
 } DblStack;
(2)回文是指正读反读均相同的字符序列，如"abba"和"abdba"均是回文，但"good"不是回文。试写一个算法判定给定的字符序列是否为回文。（提示：将一半字符入栈）
(3)设从键盘输入一整数的序列：a1,a2,a3,... an , 试编写算法实现：用栈结构存储输入的整数， 当a != -1时，将a进栈；当a == -1时，输出栈顶整数并出栈。算法应对异常情况（入栈满等）给出相应的信息。
(4)从键盘上输入一个后缀表达式，试编写算法计算表达式的值。规定：逆波兰表达式的长度不超过一行，以 "$"作为输入结束，操作数之间用空格分隔，操作符只可能有＋、—、＊、／四种运算。例如： 23434 + 2*$。
(5)假设以1 和0 分别表示入栈和出栈操作。栈的初态和终态均为空，入栈和出栈的操作序
列可表示为仅由1 和0 组成的序列，称可以操作的序列为合法序列，否则称为非法序列。
心 下面所示的序列中哪些是合法的？
A. IOIIOIOO B. 10010110 C. IIIOIOIO D. IIIOOIOO
＠通过对心的分析，写出一个算法，判定所给的操作序列是否合法。若合法，返回 true, 否
则返回 false (假定被判定的操作序列巳存入一维数组中）。
(6) 假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点 （注意：不
设头指针）， 试编写相应的置空队列、判断队列是否为空、入队和出队等算法。
(7) 假设以数组Q[m]存放循环队列中的元素，同时设置一个标志ta$, 以tag= 0 和tag= 1
来区别在队头指针 (front) 和队尾指针 (rear) 相等时，队列状态为 “空” 还是 “满 ＂。试编写与
此结构相应的插入 (enqueue) 和删除 (dequeue) 算法。
(8)如果允许在循环队列的两端都可以进行插入和删除操作。要求：
* 写出循环队列的类型定义；
* 写出 “从队尾删除“ 和 “从队头插入＂ 的算法。
(9) 已知Ackermann 函数定义如下：
                n+l                         当m == 0时
Ack(m, n) =    Ack(m - 1, 1)               当m != 0, n == 0时
                Ack(m - 1, Ack(m, n - 1))   当m != 0, n != 0时
* 写出计算Ack(m,n)的递归算法，并根据此算法给出Ack(2, 1)的计算过程。
* 写出计算Ack(m,n)的非递归算法。
(10)已知f为单链表的表头指针，链表中存储的都是整型数据，试写出实现下列运算的递归算法：
* 求链表中的最大整数；
* 求链表的结点个数；
* 求所有整数的平均值。
*/

func test1() {
    struct Stack {
        enum Direct {
            case left, right
        }
        var topLeft: Int
        var topRight: Int
        let size: Int
        var values: [Int]
        
        init(size: Int) {
            topLeft = -1
            topRight = size
            self.size = size
            values = Array<Int>(repeating: 0, count: size)
        }
        
        func isEmpty(direct: Direct) -> Bool {
            switch direct {
            case .left:
                return topLeft == -1
            case .right:
                return topRight == size
            }
        }
        
        func isFull() -> Bool {
            return topRight - topLeft == 1
        }
        
        mutating func push(from direct: Direct, value: Int) {
            if isFull() {
                print("push 失败")
            } else {
                switch direct {
                case .left:
                    topLeft += 1
                    values[topLeft] = value
                case .right:
                    topRight -= 1
                    values[topRight] = value
                }
            }
        }
        
        mutating func pop(from direct: Direct) -> Int? {
            if isEmpty(direct: direct) {
                switch direct {
                case .left:
                    let v = values[topLeft]
                    topLeft -= 1
                    return v
                case .right:
                    let v = values[topRight]
                    topRight += 1
                    return v
                }
            } else {
                return nil
            }
        }
    }
}

func test2() {
    func isHuiwen(string: String) -> Bool {
        let len = string.count
        let mid = len / 2
        for i in 0..<mid {
            let leftIdx = string.index(string.startIndex, offsetBy: i)
            let rightIdx = string.index(string.startIndex, offsetBy: len - i - 1)
            let leftC = string[leftIdx...leftIdx]
            let rightC = string[rightIdx...rightIdx]
            if leftC != rightC {
                return false
            }
        }
        return true
    }
        
    print(isHuiwen(string: "abba"))
}
//test2()

func test3() {
}

func test4() {
}

func test5() {
    
}
