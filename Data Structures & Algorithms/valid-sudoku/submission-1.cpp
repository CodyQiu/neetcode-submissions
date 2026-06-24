class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> freq;
        for (vector<char> v: board) {
            for (char c: v) {
                if (c != '.') freq[c]++;
            }
            for (auto& [key, value]: freq) {
                if (value > 1) return false;
            }
            freq.clear();
        }

        for (int i = 0; i < 9; i++) {
            for (vector<char> v: board) {
                if (v[i] != '.') freq[v[i]]++;
            }
            for (auto& [key, value]: freq) {
                if (value > 1) return false;
            }
            freq.clear();
        }

        for (int a = 0; a <= 6; a +=3) {
            for (int b = 0; b <= 6; b += 3) {
                for (int c = 0; c < 3; c++) {
                    for (int d = 0; d < 3; d++) {
                        if (board[a + c][b + d] != '.') freq[board[a + c][b + d]]++;
                    }
                }
                for (auto& [key, value]: freq) {
                    if (value > 1) return false;
                }
                freq.clear();
            }
        }
        return true;
    }
};
