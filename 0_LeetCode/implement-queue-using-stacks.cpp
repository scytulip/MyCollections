class Queue {
public:
    stack<int> stk;

    // Push element x to the back of queue.
    void push(int x) {
        stack<int> tmp;
        while(!stk.empty())
        {
            tmp.push(stk.top());
            stk.pop();
        }
        stk.push(x);
        while(!tmp.empty())
        {
            stk.push(tmp.top());
            tmp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stk.pop();
    }

    // Get the front element.
    int peek(void) {
        return stk.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk.empty();
    }
};