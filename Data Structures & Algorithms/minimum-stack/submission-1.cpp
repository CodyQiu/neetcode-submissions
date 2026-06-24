class MinStack {

private:
    stack<int> stk;
    stack<int> minstk;
public:
    MinStack() {
    }
    
    void push(int val) {
        if (minstk.empty()) minstk.push(val);
        else {
            if (val <= minstk.top()) minstk.push(val);
        }
        stk.push(val);
    }
    
    void pop() {
        if (stk.top() == minstk.top()) minstk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
};
