class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int l = 0;
        int r = 0;
        char m = s[0];
        int longest = 0;
        while (r < s.size()) {
            freq[s[r]]++;
            if (freq[m] < freq[s[r]]+1) {
                m = s[r];
            }
            if (r-l+1 - freq[m] <= k) {
                longest = max(longest, r-l+1);
                r++;
            } else {
                freq[s[l]]--;
                freq[s[r]]--;
                l++;
            }
        }
        return longest;
    }
};
