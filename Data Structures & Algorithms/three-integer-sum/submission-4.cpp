class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> total;
        for (int i = 0; i < nums.size(); i++) {
            int left = 0;
            int right = nums.size() - 1;
            while (left < right) {
                if (left == i) {
                    left++;
                    continue;
                }
                if (right == i) {
                    right--;
                    continue;
                }
                if (nums[i] + nums[left] + nums[right] < 0) left++;
                else if (nums[i] + nums[left] + nums[right] > 0) right--;
                else {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    sort(temp.begin(), temp.end());
                    total.insert(temp);
                    left++;
                }
            }
        }
        vector<vector<int>> final;
        for (auto& x: total) {
            final.push_back(x);
        }
        return final;
    }
};
