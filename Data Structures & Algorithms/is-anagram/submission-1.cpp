class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m1;
        map<char, int> m2;
        for (char c: s) {
            m1[c]++;
        }
        for (char c: t) {
            m2[c]++;
        }
        for (char c: s + t) {
            if (m1[c] != m2[c]) return false;
        }
        return true;
    }
};
