class Solution {
public:
    int maxProduct(vector<int>& nums) {
        unordered_map<int, int> prod;
        int largest = 0;
        int index = 0;
        int start = 0;
        if (nums.size() == 1) return nums[0];
        bool hasOne = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) hasOne = true;
            if (nums[i] < 0) {
                start = i + 1;
                break;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                largest = max({largest, prod[0], prod[1]});
                prod[0] = 0;
                prod[1] = 0;
            } else {
                if (prod[0] == 0) prod[0] = nums[i];
                else prod[0] *= nums[i];

                if (i >= start) {
                    if (prod[1] == 0) prod[1] = nums[i];
                    else prod[1] *= nums[i];
                }
                largest = max({largest, prod[0], prod[1]});
            }
        }
        // if (largest == 1 && !hasOne) return 0;
        // else return largest;
        return largest;
    }
};
