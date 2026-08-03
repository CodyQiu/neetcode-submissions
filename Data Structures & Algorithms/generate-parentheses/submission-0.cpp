class Solution {
public:

    void recurse(int n, int open, int close, vector<string>& total, string& curr) {
        if (curr.size() == 2 * n) {
            total.push_back(curr);
            return;
        }
        if (open == close) {
            curr.push_back('(');
            recurse(n, open + 1, close, total, curr);
            curr.pop_back();
        } else {
            if (open < n) {
                curr.push_back('(');
                recurse(n, open + 1, close, total, curr);
                curr.pop_back();
            }
            curr.push_back(')');
            recurse(n, open, close + 1, total, curr);
            curr.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> total;
        string curr = "";
        recurse(n, 0, 0, total, curr);
        return total;
    }
};
