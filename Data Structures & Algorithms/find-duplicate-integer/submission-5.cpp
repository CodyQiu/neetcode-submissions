class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 2) return nums[0];
        int left = 1;
        int right = 2;
        while (true) {
            if (left == right) {
                right++;
                continue;
            }
            if (nums[left] == nums[right]) return nums[left];
            left++;
            left = left % nums.size();
            right = right + 2;
            right = right % nums.size();
        }
    }
};
