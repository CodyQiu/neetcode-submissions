class MinStack {
public:
    stack<int> s;
    stack<int> mins;
    MinStack() {
    }
    
    void push(int val) {
        if (mins.size() == 0) mins.push(val);
        else if (mins.top() >= val) mins.push(val);
        s.push(val);
    }
    
    void pop() {
        if (s.top() == mins.top()) mins.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
