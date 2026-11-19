class Solution {
public:

    int dfs(int amount, vector<int>& coins, int curr, int index, vector<vector<int>>& dp) {
        if (curr == amount) return 1;
        if (curr > amount) return 0;
        if (dp[curr][index] != -1) return dp[curr][index];
        int count = 0;
        for (int i = index; i < coins.size(); i++) {
            count += dfs(amount, coins, curr + coins[i], i, dp);
        }
        dp[curr][index] = count;
        return count;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp = vector(amount, vector(coins.size(), -1));
        return dfs(amount, coins, 0, 0, dp);
    }
};
