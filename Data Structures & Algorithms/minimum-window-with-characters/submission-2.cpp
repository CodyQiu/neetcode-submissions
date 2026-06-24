class Solution {
public:
    bool subMap(unordered_map<char, int>& freq1, unordered_map<char, int>& freq2, string t) {
        for (auto& [key, value]: freq1) {
            if (value > freq2[key]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        unordered_set<string> works;
        if (t.size() > s.size()) return "";
        for (char c = 'a'; c <= 'z'; c++) {
            freq1[c] = 0;
            freq2[c] = 0;
        }
        for (char c = 'A'; c <= 'Z'; c++) {
            freq1[c] = 0;
            freq2[c] = 0;
        }
        for (char c: t) {
            freq1[c]++;
        }
        int l = 0;
        int r = 0;
        while (freq1[s[r]] < 1 && r < s.size()) {
            r++;
            l++;
        }
        // if (r == s.size() && r != t) return "";
        freq2[s[r]]++;
        while (r < s.size()) {
            if (subMap(freq1, freq2, t)) {
                works.insert(s.substr(l, r - l + 1));
                freq2[s[l]]--;
                l++;
            } else {
                r++;
                if (r < s.size()) freq2[s[r]]++;
            }
        }
        string final = s;
        if (works.empty()) return "";
        for (string word: works) {
            if (word.size() < final.size()) final = word;
        }
        return final;
    }
};
