class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;
        for(int i = 0; i < nums.size(); i++){
            mySet.insert(nums[i]);
        }
        return mySet.size() != nums.size();
    }
};