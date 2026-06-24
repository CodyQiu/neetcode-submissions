#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        string final;
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                final += tolower(s[i]);
            }
        }


        int left = 0;
        int right = final.size() - 1;
        while (left < right) {
            if (final[left] == final[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
};
