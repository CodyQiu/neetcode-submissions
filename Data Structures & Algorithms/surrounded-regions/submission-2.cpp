class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> vals(board.size(), vector<int>(board[0].size(),0));
        queue<vector<int>> q;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (i == 0 || i == board.size() - 1 || j == 0 || 
                j == board[0].size() - 1) {
                    if (board[i][j] == 'O') {
                        q.push({i,j});
                        // no need to change
                        vals[i][j] = 1;
                    }
                }
            }
        }
        vector<vector<int>> dirs = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };
        while (q.size() > 0) {
            auto temp = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = temp[0] + dirs[i][0];
                int c = temp[1] + dirs[i][1];
                
                if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) continue;
                if (vals[r][c] > 0 || board[r][c] != 'O') continue;
                vals[r][c] = 1;
                q.push({r,c});
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O' && vals[i][j] == 0) board[i][j] = 'X';
            }
        }
    }
};
