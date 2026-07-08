class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int left = 0;
        int right = 1;
        freq[s[left]]++;
        freq[s[right]]++;
        int maxfreq = 1;
        int length = 0;
        while (right < s.size()) {
            for (auto& [one, two]: freq) maxfreq = max(maxfreq, two);
            while (right - left + 1 - maxfreq > k) {
                freq[s[left]]--;
                left++;
                for (auto& [one, two]: freq) maxfreq = max(maxfreq, two);
            }
            length = max(length, right - left + 1);
            right++;
            freq[s[right]]++;
        }
        return length;
    }
};
