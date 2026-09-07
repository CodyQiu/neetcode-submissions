class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> dp;
        dp[n - 1] = 1;
        dp[n] = 1;
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = dp[i + 2] + dp[i + 1];
        }
        return dp[0];
    }
};
