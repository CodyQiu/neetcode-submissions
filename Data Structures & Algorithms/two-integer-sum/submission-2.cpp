class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> other;
        for (int i = 0; i < nums.size(); i++) {
            other.insert(target - nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (other.contains(target - nums[i])) {
                int right = 0;
                for (int j = 0; j < nums.size(); j++) {
                    if (nums[j] == target - nums[i] && j != i) return {i, j};
                }
            }
        }
    }
};
