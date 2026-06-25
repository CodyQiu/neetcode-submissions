class Solution {
public:
    bool isPalindrome(string s) {
        string filtered = "";
        for (char c: s) {
            if (c >= 'a' && c <= 'z') filtered += c;
            else if (c >= 'A' && c <= 'Z') filtered += c + 'a' - 'A';
            else if(c >= '0' && c <= '9') filtered += c;
        }
        int left = 0;
        int right = filtered.size() - 1;
        while (left < right) {
            if (filtered[left] != filtered[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
