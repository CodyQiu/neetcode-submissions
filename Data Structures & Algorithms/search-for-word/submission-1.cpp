class Solution {
public:

    bool recurse(vector<vector<char>>& board, string word, vector<vector<bool>> visited, int i, int j, string curr) {
        if (word == curr) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if (visited[i][j] || curr.size() > word.size()) return false;
        visited[i][j] = true;
        curr.push_back(board[i][j]);
        bool u = recurse(board, word, visited, i + 1, j, curr);
        bool r = recurse(board, word, visited, i, j + 1, curr);
        bool d = recurse(board, word, visited, i - 1, j, curr);
        bool l = recurse(board, word, visited, i, j - 1, curr);
        curr.pop_back();
        visited[i][j] = false;
        return u || r || d || l;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                string curr = "";
                if (recurse(board, word, visited, i, j, curr)) return true;
            }
        }
        return false;
    }
};
