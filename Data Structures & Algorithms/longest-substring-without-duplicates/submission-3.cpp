class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        else if (s.size() == 1) return 1;
        int left = 0;
        int right = 1;
        unordered_set<char> hash;
        hash.insert(s[left]);
        int longest = 1;
        while (right < s.size()) {
            if (hash.contains(s[right])) {
                while (hash.contains(s[right])) {
                    hash.erase(s[left]);
                    left++;
                }
                hash.insert(s[right]);
            } else {
                hash.insert(s[right]);
                longest = max(longest, (int)hash.size());
            }
            right++;
        }
        return longest;
    }
};
