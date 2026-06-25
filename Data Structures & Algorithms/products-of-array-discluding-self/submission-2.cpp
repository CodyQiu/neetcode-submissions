class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 0);
        vector<int> suffix(nums.size(), 0);
        int temp1 = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) prefix[i] = 1;
            else {
                temp1 *= nums[i - 1];
                prefix[i] = temp1;
            }
        }
        int temp2 = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) suffix[i] = 1;
            else {
                temp2 *= nums[i + 1];
                suffix[i] = temp2;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            prefix[i] = prefix[i] * suffix[i];
        }
        return prefix;
    }
};
