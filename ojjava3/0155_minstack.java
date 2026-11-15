/**
 *  记住stack都是单调的
 * 例如最小值是 5,3,3,1,1  一旦到达了小的水位，后来的值都要<=这个水位，这是单调栈的特性
 * 这里用一个辅助栈来构建单调栈
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