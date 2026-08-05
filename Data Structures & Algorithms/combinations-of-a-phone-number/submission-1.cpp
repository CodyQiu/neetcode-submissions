class Solution {
public:
    vector<string> key = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
    void helper(string& digits, int depth, vector<string>& total, string& current) {
        if (depth >= digits.size() && current.size() > 0) {
            total.push_back(current);
            return;
        }
        for (char c: key[digits[depth] - '0']) {
            current.push_back(c);
            helper(digits, depth + 1, total, current);
            current.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        vector<string> total;
        string current = "";
        if (digits.size() == 0) return {};
        helper(digits, 0, total, current);
        return total;
    }
};
