/**
 *  记住stack都是单调的
 * 例如最小值是 5,3,3,1,1  一旦到达了小的水位，后来的值都要<=这个水位，这是单调栈的特性
 * 这里用一个辅助栈来构建单调栈
 * 首先是一个栈，还得保存最小值
O(1) 这个题目属于比较难，不适合面试
treemap 就不是O(1), insert O(logN)
getmin() => O(1)
我的思路是，如果要O(1)，那么必定不能用treemap, priorityqueue等等，就是我一定要直接保存着当前的最小值(也不可能是hashmap)，要么是变量，要么就是O(1)的函数操作，例如stack.top()
但带来的问题是，用双栈的话，如果stack.top()是当前最小值，那么pop出去之后下一个必定是下一个最小值，这里怎么把次小值排在第二位置我想不通

=>
你卡住的那个点——“为什么弹出了当前最小值，底下紧挨着的一定是次小值，而不是一个普通的较大数？”——其实是因为你把辅助栈当成了“全局排序栈”，而没有利用栈“后进先出（LIFO）”的时间线特性。
下面帮你彻底打通这个逻辑盲区。

核心破局点：辅助栈存的不是“全局次小值”，而是“历史快照”

你之所以想不通，是因为你在思考：“如果依次压入 3, 1, 2，栈里本来是 [3, 1, 2]，怎么把 3 挪到 1 的下面？”
答案是：根本不需要挪动，因为在 1 出现之后进来的 2，永远比 1 先死（先被 pop）！

 */


import java.util.Stack;
class MinStack {
    private Stack<Integer> helper = new Stack<>();
    private Stack<Integer> stack = new Stack<>();

    public MinStack() {
        
    }
    
    public void push(int value) {
        stack.push(value);
        if (!helper.empty() && value > helper.peek()) {
            helper.push(helper.peek());
        } else {
            helper.push(value);
        }
    }
    
    public void pop() {
        if (!stack.empty()) {
            stack.pop();
            helper.pop();
        }
    }
    
    public int top() {
        return stack.peek();        
    }
    
    public int getMin() {
        return helper.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */