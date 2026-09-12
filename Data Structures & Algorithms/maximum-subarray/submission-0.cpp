class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int largest = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (curr >= 0 && nums[i] >= 0) curr += nums[i];
            else if (curr >= 0 && nums[i] < 0) curr += nums[i];
            else if (curr < 0 && nums[i] >= 0) curr = nums[i];
            else if (curr < 0 && nums[i] < 0) curr = nums[i];
            largest = max(largest, curr);
        }
        return largest;
    }
};
