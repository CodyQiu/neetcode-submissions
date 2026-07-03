class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return min(nums[0], nums[1]);

        int left = 0;
        int right = nums.size() - 1;
        int debug = 0;
        while (left <= right) {
            int center = (left + right) / 2;
            if (center - left <= 1 && right - center <= 1) return min({nums[left], nums[right], nums[center]});
            if (max({nums[left], nums[right], nums[center]}) == nums[right]) return nums[left];
            else if (max({nums[left], nums[right], nums[center]}) == nums[center]) {
                left = center;
            } else if (max({nums[left], nums[right], nums[center]}) == nums[left]) {
                right = center;
            }
        }
    }
};
