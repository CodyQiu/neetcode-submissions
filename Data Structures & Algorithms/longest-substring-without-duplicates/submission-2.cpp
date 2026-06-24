class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        unordered_set<char> letters;
        int longest = 0;
        while (r < s.size()) {
            if (letters.find(s[r]) == letters.end()) {
                letters.insert(s[r]);
                r++;
            } else {
                while (letters.find(s[r]) != letters.end()) {
                    letters.erase(s[l]);
                    l++;
                }
                letters.insert(s[r]);
                r++;
            }
            longest = max(longest, (int) letters.size());
        }
        return longest;
    }
};
