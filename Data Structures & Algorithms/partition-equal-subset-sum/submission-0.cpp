class Solution {
public:

    bool recurse(unordered_map<int, unordered_map<int, bool>>& dp, vector<int>& nums, int curr, int total, int index) {
        if (curr > total) {
            return false;
        } else if (curr == total) return true;
        if (dp.contains(index) && dp[index].contains(curr)) return dp[index][curr];

        bool able = false;
        for (int i = index + 1; i < nums.size(); i++) {
            able = able || recurse(dp, nums, curr + nums[i], total, i);
        }
        dp[index][curr] = able;
        return able;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (auto num: nums) total += num;
        if (total % 2 != 0) return false;
        unordered_map<int, unordered_map<int, bool>> dp;
        return recurse(dp, nums, 0, total/2, -1);
    }
};
