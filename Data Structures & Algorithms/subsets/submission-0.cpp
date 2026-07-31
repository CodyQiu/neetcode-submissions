class Solution {
public:

    void subsets(vector<int>& nums, vector<vector<int>>& total, vector<int> curr, int index) {
        if (index == nums.size()) {
            total.push_back(curr);
            return;
        }
        int temp = nums[index];
        subsets(nums, total, curr, index + 1);
        curr.push_back(temp);
        subsets(nums, total, curr, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> total;
        vector<int> curr;
        subsets(nums, total, curr, 0);
        return total;
    }
};
