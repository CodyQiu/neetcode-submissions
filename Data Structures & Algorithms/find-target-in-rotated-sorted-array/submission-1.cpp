class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (r >= l) {
            int med = (l+r)/2;
            if (nums[l] == target) return l;
            if (nums[r] == target) return r;
            if (nums[med] == target) return med;

            if (nums[l] < nums[med] && (target > nums[l] && target < nums[med])) {
                l = l;
                r = med - 1;
            } else if (nums[l] < nums[med]) {
                l = med + 1;
                r = r;
            } else if (nums[med] < nums[r] && (target < nums[med] || target > nums[r])) {
                l = l;
                r = med - 1;
            } else if (nums[med] < nums[r]) {
                l = med + 1;
                r = r;
            } else {
                r--;
            }
        }
        return -1;
    }
};
