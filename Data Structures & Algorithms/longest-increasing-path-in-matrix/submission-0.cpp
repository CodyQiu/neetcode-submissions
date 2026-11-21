class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int x, int y, int curr, unordered_set<int>& visited, vector<vector<int>>& dp) {
        if (visited.contains(x * matrix[0].size() + y)) return curr;
        if (dp[x][y] != -1) return curr + dp[x][y];
        visited.insert(x * matrix[0].size() + y);
        vector<vector<int>> pos = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };
        int largest = curr;
        for (auto dir: pos) {
            if (x + dir[0] < matrix.size() && x + dir[0] >= 0 && y + dir[1] < matrix[0].size() && y + dir[1] >= 0) {
                if (matrix[x][y] < matrix[x + dir[0]][y + dir[1]]) largest = max(largest, dfs(matrix, x + dir[0], y + dir[1], curr + 1, visited, dp));
            }
        }
        visited.erase(x * matrix[0].size() + y);
        dp[x][y] = largest - curr;
        return largest;
    }


    int longestIncreasingPath(vector<vector<int>>& matrix) {
        unordered_set<int> visited;
        int largest = 0;
        vector<vector<int>> dp = vector(matrix.size(), vector(matrix[0].size(), -1));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                largest = max(largest, dfs(matrix, i, j, 1, visited, dp));
            }
        }
        return largest;
    }
};
