class Solution {
public:

    int dfs(vector<int>& nums, int target, int curr, int index, unordered_map<int, unordered_map<int, int>>& dp) {
        if (index >= nums.size()) {
            if (curr == target) return 1;
            else return 0;
        }
        if (dp.contains(curr) && dp[curr].contains(index)) return dp[curr][index];

        int count = 0;
        count += dfs(nums, target, curr + nums[index], index + 1, dp);
        count += dfs(nums, target, curr - nums[index], index + 1, dp);
        dp[curr][index] = count;
        return count;
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, unordered_map<int, int>> dp;
        return dfs(nums, target, 0, 0, dp);
    }
};
