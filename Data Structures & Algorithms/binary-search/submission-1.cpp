class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int check = (left + right) / 2;
            if (nums[check] < target) {
                left = check + 1;
            } else if (nums[check] > target) {
                right = check - 1;
            } else {
                return check;
            }
        }
        return -1;
    }
};
