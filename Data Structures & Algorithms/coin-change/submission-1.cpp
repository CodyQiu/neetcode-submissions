class Solution {
public:

    int dfs(vector<int>& coins, int amountLeft, unordered_map<int, int>& dp) {
        if (amountLeft == 0) return 0;
        if (dp.contains(amountLeft)) return dp[amountLeft];
        int curr = INT_MAX;
        for (int coin: coins) {
            int temp;
            if (amountLeft - coin >= 0) temp = dfs(coins, amountLeft - coin, dp);
            else continue;
            if (temp == INT_MAX) curr = min(temp, curr);
            else curr = min(temp + 1, curr);
        }
        dp[amountLeft] = curr;
        return curr;
    }


    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> dp;
        int final = dfs(coins, amount, dp);
        if (final == INT_MAX) return -1;
        else return final;
    }
};
