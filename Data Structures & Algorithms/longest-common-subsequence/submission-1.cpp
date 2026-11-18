class Solution {
public:

    int dfs(string text1, string text2, int i, int j, vector<vector<int>>& dp) {
        if (i >= text1.size() || j >= text2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + dfs(text1, text2, i + 1, j + 1, dp);
        }
        else {
            dp[i][j] = max(dfs(text1, text2, i + 1, j, dp), dfs(text1, text2, i, j + 1, dp));
        }
        return dp[i][j];
    }


    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp = vector(text1.size(), vector(text2.size(), -1));
        return dfs(text1, text2, 0, 0, dp);
    }
};
