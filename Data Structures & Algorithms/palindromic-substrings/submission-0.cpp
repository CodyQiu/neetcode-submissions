class Solution {
public:
    int countSubstrings(string s) {
        // Odd Center
        int total = 0;
        for (int i = 0; i < s.size(); i++) {
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size()) {
                if (s[left] == s[right]) {
                    total++;
                    left--;
                    right++;
                } else {
                    break;
                }
            }
        }
        for (int i = 1; i < s.size(); i++) {
            int left = i - 1;
            int right = i;
            while (left >= 0 && right < s.size()) {
                if (s[left] == s[right]) {
                    total++;
                    left--;
                    right++;
                } else {
                    break;
                }
            }
        }
        return total;
    }
};
