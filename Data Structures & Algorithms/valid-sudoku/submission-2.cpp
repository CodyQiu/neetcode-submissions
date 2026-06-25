class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> seen;
        // Check every row
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && seen.contains(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
            seen.clear();
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.' && seen.contains(board[j][i])) return false;
                seen.insert(board[j][i]);
            }
            seen.clear();
        }
        for (int k = 0; k < 3; k++) {
            for (int h = 0; h < 3; h++) {
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (board[1 + 3 * h + i][1 + 3 * k + j] != '.' && seen.contains(board[1 + 3 * h + i][1 + 3 * k + j])) return false;
                        seen.insert(board[1 + 3 * h + i][1 + 3 * k + j]);
                    }
                }
                seen.clear();
            }

        }
        return true;
    }
};
