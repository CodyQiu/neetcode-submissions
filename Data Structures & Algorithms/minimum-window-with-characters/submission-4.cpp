class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> freqt;
        unordered_map<char, int> freqs;
        // for (char c = 'a'; c <= 'z'; c++) {
        //     freq1[c] = 0;
        //     freq2[c] = 0;
        // }
        // for (char c = 'A'; c <= 'Z'; c++) {
        //     freq1[c] = 0;
        //     freq2[c] = 0;
        // }
        for (char c: t) freqt[c]++;
        freqs[s[left]]++;
        // freqs[s[right]]++;
        string shortest = s + 'a';

        while (right < s.size()) {
            bool validSubstring = true;
            while (validSubstring) {
                for (char c: t) {
                    if (freqt[c] > freqs[c]) {
                        validSubstring = false;
                    }
                }
                if (validSubstring) {
                    string sub = s.substr(left, right - left + 1);
                    if (sub.size() < shortest.size()) shortest = sub;
                    freqs[s[left]]--;
                    left++;
                }
            }
            right++;
            freqs[s[right]]++;
        }
        if (shortest == s + 'a') return "";
        else return shortest;
    }
};
