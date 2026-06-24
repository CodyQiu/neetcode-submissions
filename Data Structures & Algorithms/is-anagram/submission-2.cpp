class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;

        for (char c: s) {
            freq1[c]++;
        }
        for (char c: t) {
            freq2[c]++;
        }
        for (const auto& [c, v]: freq1) {
            if (freq1[c] != freq2[c]) return false;
        }
        if (freq1.size() != freq2.size()) return false;
        return true;
    }
};
