class Solution {
public:
    bool inRange(char first, char second) {
        string s = {first, second};
        if (first == '0') return false;
        if (stoi(s) <= 26) return true;
        return false;
    }
    int numDecodings(string s) {
        vector<int> dp1 = vector<int>(s.size(), 0);
        vector<int> dp2 = vector<int>(s.size(), 0);
        if (s[0] != '0') dp1[0] = 1;
        else dp1[0] = 0;
        dp2[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != '0') dp1[i] = dp1[i-1] + dp2[i-1];
            if (i - 2 >= 0 && inRange(s[i-1], s[i])) dp2[i] = dp1[i-2] + dp2[i-2];
            if (i == 1 && inRange(s[i-1], s[i])) dp2[i] = 1;
        }
        return dp1.back() + dp2.back();
    }
};
