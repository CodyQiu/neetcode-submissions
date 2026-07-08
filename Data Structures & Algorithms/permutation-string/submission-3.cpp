class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        int right = s1.size() - 1;
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        for (char i = 'a'; i <= 'z'; i++) {
            freq1[i] = 0;
            freq2[i] = 0;
        }
        for (char c: s1) freq1[c]++;
        for (int i = 0; i < s1.size(); i++) freq2[s2[i]]++;
        while (right < s2.size()) {
            if (freq1 == freq2) return true;
            freq2[s2[left]]--;
            left++;
            right++;
            freq2[s2[right]]++;
        }
        return false;
    }
};
