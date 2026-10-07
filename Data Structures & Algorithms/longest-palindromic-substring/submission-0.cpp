class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 1;
        string final = {s[0]};
        for (int i = 0; i < s.size(); i++) {
            int curr = 1;
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 && right < s.size()) {
                if (s[left] == s[right]) {
                    curr += 2;
                    if (curr > longest) {
                        longest = curr;
                        final = s.substr(left, curr);
                    }
                } else break;
                left--;
                right++;
            }
        }
        for (int i = 1; i < s.size(); i++) {
            int curr = 0;
            if (s[i] == s[i-1]) {
                curr = 2;
                if (curr > longest) {
                    longest = curr;
                    final = s.substr(i-1, 2);
                }
                int left = i - 2;
                int right = i + 1;
                while (left >= 0 && right < s.size()) {
                    if (s[left] == s[right]) {
                        curr += 2;
                        if (curr > longest) {
                            final = s.substr(left, curr);
                            longest = curr;
                        }
                    } else break;
                    left--;
                    right++;
                }
            }
        }
        return final;
    }
};
