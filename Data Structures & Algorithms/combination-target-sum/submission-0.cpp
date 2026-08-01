class Solution {
public:

    void combinationSums(vector<int>& nums, int target, vector<vector<int>>& total, vector<int>& curr, int index) {
        if (target < 0) {
            return;
        }
        else if (target == 0) {
            total.push_back(curr);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            combinationSums(nums, target - nums[i], total, curr, i);
            curr.pop_back();
        }
    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        vector<int> curr;
        combinationSums(nums, target, total, curr, 0);
        return total;
    }
};