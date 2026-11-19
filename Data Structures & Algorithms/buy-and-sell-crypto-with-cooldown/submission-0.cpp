class Solution {
public:
    int dfs(vector<int>& prices, int profit, int index, int holding, vector<vector<int>>& dp) {
        if (index >= prices.size()) return profit;
        if (dp[index][holding] != -1) return profit + dp[index][holding];
        int best = 0;
        if (holding == 0) {
            best = max(dfs(prices, profit, index + 1, 0, dp),
                dfs(prices, profit - prices[index], index + 1, 1, dp));
        } else {
            best = max(dfs(prices, profit, index + 1, 1, dp),
                dfs(prices, profit + prices[index], index + 2, 0, dp));
        }
        dp[index][holding] = best - profit;
        return best;
    }


    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp = vector(prices.size(), vector(2, -1));
        return dfs(prices, 0, 0, 0, dp);
    }
};
