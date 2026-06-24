class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min = 0;
        int max = nums.size() - 1;

        while (max >= min) {
            if (nums[(max + min)/2] == target) {
                return (max + min)/2;
            }
            else if (nums[(max + min)/2] < target) {
                max = max;
                min = (max + min)/2 + 1;
            } else if (nums[(max + min)/2] > target) {
                max = (max + min)/2 - 1;
                min = min;
            }
        }
        return -1;
    }
};
