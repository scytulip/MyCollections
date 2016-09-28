class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        val_stk.push(x);
        if (min_stk.empty() || min_stk.top()>x) {
            min_stk.push(x);
        } else {
            min_stk.push(min_stk.top());
        }
    }
    
    void pop() {
        val_stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return val_stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
    
private:
    stack<int> val_stk;
    stack<int> min_stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */