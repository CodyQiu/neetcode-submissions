class Solution {
public:

    void permute(vector<int>& nums, vector<vector<int>>& total, vector<int>& curr) {
        if (nums.size() == 0) {
            total.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            curr.push_back(val);
            nums.erase(nums.begin() + i);
            permute(nums, total, curr);
            nums.insert(nums.begin() + i, val);
            curr.pop_back();
        }
        

    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> total;
        permute(nums, total, curr);
        return total;
    }
};
