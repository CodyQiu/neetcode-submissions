class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> final;
        int pre[nums.size()];
        int suf[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) pre[i] = 1;
            else {
                pre[i] = pre[i-1] * nums[i-1];
            }
        }
        for (int i = nums.size() - 1; i >=0; i--) {
            if (i == nums.size() - 1) suf[i] = 1;
            else {
                suf[i] = suf[i+1] * nums[i+1];
            }
        }
        // for (int i = 0; i < nums.size(); i++) {
        //     final.push_back(suf[i]);
        // }
        for (int i = 0; i < nums.size(); i++) {
            final.push_back(pre[i]*suf[i]);
        }
        return final;
    }
};
