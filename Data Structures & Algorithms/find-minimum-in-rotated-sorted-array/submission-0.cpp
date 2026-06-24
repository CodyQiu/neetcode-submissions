class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mini = nums[0];

        while (right >= left) {
            mini = min(mini, nums[left]);
            mini = min(mini, nums[right]);
            mini = min(mini, nums[(left+right)/2]);
            if (nums[left] < nums[(left+right)/2]) {
                left = (right+left)/2 + 1;
            } else if (nums[(left+right)/2] < nums[right]) {
                right = (right + left)/2 -1;
            } else right--;
        }
        return mini;



    }
};
