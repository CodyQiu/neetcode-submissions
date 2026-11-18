class Solution {
public:

    int dfs(int m, int n, int x, int y, unordered_map<int, unordered_map<int, int>>& dp) {
        if (x == m - 1|| y == n - 1) return 1;
        if (x >= m || y >= n) return 0;
        if (dp.contains(x) && dp[x].contains(y)) return dp[x][y];
        dp[x][y] = dfs(m, n, x + 1, y, dp) + dfs(m, n, x, y + 1, dp);
        return dp[x][y];
    }

    int uniquePaths(int m, int n) {
        unordered_map<int, unordered_map<int, int>> dp;
        return dfs(m, n, 0, 0, dp);
    }
};
