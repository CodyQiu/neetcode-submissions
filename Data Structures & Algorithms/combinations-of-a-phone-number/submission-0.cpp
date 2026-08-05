class Solution {
public:
unordered_map<char, string> key = {
    {'2', "abc"},
    {'3', "edf"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};
    void helper(string& digits, int depth, vector<string>& total, string& current) {
        if (depth >= digits.size() && current.size() > 0) {
            total.push_back(current);
            return;
        }
        for (char c: key[digits[depth]]) {
            current.push_back(c);
            helper(digits, depth + 1, total, current);
            current.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        vector<string> total;
        string current = "";
        helper(digits, 0, total, current);
        return total;
    }
};
