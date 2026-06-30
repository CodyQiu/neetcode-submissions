class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> ops;
        for (string s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int first = stoi(ops.top());
                ops.pop();
                int second = stoi(ops.top());
                ops.pop();
                if (s == "+") ops.push(to_string(first + second));
                else if (s == "-") ops.push(to_string(second - first));
                else if (s == "*") ops.push(to_string(first * second));
                else ops.push(to_string(second / first));
            } else {
                ops.push(s);
            }
        }
        return stoi(ops.top());
    }
};
