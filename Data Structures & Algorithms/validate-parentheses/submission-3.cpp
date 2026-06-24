class Solution {
public:
    bool isValid(string s) {
        vector<char> open = {'(', '{', '['};
        vector<char> close = {')', '}', ']'};

        stack<char> stk;
        if (find(open.begin(), open.end(), s[0]) == open.end()) return false;

        for (char c: s) {
            if (find(open.begin(), open.end(), c) != open.end()) {
                stk.push(c);
            } else {
                if (stk.empty()) return false;
                if (c == ')') {
                    if (stk.top() != '(') return false;
                } else if (c == '}') {
                    if (stk.top() != '{') return false;
                }
                else if (c == ']') {
                    if (stk.top() != '[') return false;
                }
                stk.pop();
            }
        }
        if (!stk.empty()) return false;
        return true;
    }
};
