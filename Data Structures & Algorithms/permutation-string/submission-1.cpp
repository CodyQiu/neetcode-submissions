class Solution {
public:

    bool equal(unordered_map<char, int>& freq1, unordered_map<char, int>& freq2) {
        bool bruh = true;
        for (auto& pair: freq1) {
            if (pair.second > 0) {
                if (freq2[pair.first] != pair.second) bruh = false;
            }
        }
        return bruh;
    }

    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int r = s1.size() - 1;
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        for (char c: s1) {
            freq1[c]++;
        }
        for (int i = 0; i < s1.size(); i++) {
            freq2[s2[i]]++;
        }
        if (equal(freq1, freq2)) return true;
        while (r < s2.size()) {
            r++;
            freq2[s2[r]]++;
            freq2[s2[l]]--;
            l++;
            if (equal(freq1, freq2)) return true;
        }
        return false;
    }
};
