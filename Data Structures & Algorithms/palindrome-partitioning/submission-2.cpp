class Solution {
public:

    bool isPalindrome(string pal) {
        if (pal.size() == 0) return false;
        for (int i = 0; i < pal.size(); i++) {
            if (pal[i] != pal[pal.size() - i - 1]) return false;
        }
        return true;
    }


    void helper(string& s, int left, vector<vector<string>>& total, vector<string>& current, string &pal) {
        if (left >= s.size()) {
            if (pal == "") total.push_back(current);
            return;
        } 
        pal.push_back(s[left]);
        if (isPalindrome(pal)) {
            current.push_back(pal);
            string emptyPal = "";
            helper(s, left + 1, total, current, emptyPal);
            current.pop_back();
        }
            helper(s, left + 1, total, current, pal);
            pal.pop_back();
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> total;
        vector<string> current;
        string pal = "";
        helper(s, 0, total, current, pal);
        return total;
    }
};
