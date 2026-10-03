class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp = {nums[0], max(nums[0],nums[1])};
        for (int i = 2; i < nums.size(); i++) {
            int temp = max(dp[i-1], nums[i] + dp[i-2]);
            dp.push_back(temp);
        }
        return max(dp[dp.size()-1], dp[dp.size() - 2]);
    }
};
