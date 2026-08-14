class Solution {
public:
    int INT = 2147483647;
    void pushNeighbors(vector<vector<int>>& grid, int m, int n, queue<vector<int>>& q, int depth) {
        if (m - 1 >= 0 && m - 1 < grid.size()) q.push({m-1,n,depth+1});
        if (m + 1 >= 0 && m + 1 < grid.size()) q.push({m+1,n,depth+1});
        if (n - 1 >= 0 && n - 1 < grid[0].size()) q.push({m,n-1,depth+1});
        if (n + 1 >= 0 && n + 1 < grid[0].size()) q.push({m,n+1,depth+1});
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<vector<int>> q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) q.push({i,j});
            }
        }

        while (q.size() > 0) {
            auto temp = q.front();
            q.pop();
            int m = temp[0];
            int n = temp[1];

            if (m + 1 < grid.size() && grid[m+1][n] == INT) {
                grid[m+1][n] = grid[m][n] + 1;
                q.push({m+1,n});
            }
            if (m - 1 >= 0 && grid[m-1][n] == INT) {
                grid[m-1][n] = grid[m][n] + 1;
                q.push({m-1,n});
            }
            if (n + 1 < grid[0].size() && grid[m][n+1] == INT) {
                grid[m][n+1] = grid[m][n] + 1;
                q.push({m,n+1});
            }
            if (n - 1 >= 0 && grid[m][n - 1] == INT) {
                grid[m][n-1] = grid[m][n] + 1;
                q.push({m,n-1});
            }

        }
    }
};
