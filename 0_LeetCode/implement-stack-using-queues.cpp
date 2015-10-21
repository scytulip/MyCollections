class Stack {
public:
    queue<int> que;
    
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int i;
        for (i=0; i<que.size()-1; i++)
        {
            que.push(que.front());
            que.pop();
        }
        que.pop();
    }

    // Get the top element.
    int top() {
        return que.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
};