class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int,int> dp;
        dp[cost.size() - 1] = cost[cost.size() - 1];
        dp[cost.size()] = 0;
        for (int i = cost.size() - 2; i >= 0; i--) {
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
};
