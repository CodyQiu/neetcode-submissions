class Solution {
public:

    void recurse(vector<int>& nums, vector<vector<int>>& total, vector<int>& curr, int depth) {
        if (depth >= nums.size()) {
            total.push_back(curr);
            return;
        }
        int val = nums[depth];
        curr.push_back(val);
        recurse(nums, total, curr, depth + 1);
        curr.pop_back();
        while (depth + 1 < nums.size() && val == nums[depth + 1]) depth++;
        recurse(nums, total, curr, depth + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> total;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        recurse(nums, total, curr, 0);
        return total;
    }
};
