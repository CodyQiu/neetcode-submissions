class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> final;
        int index1;
        int index2;
        int index3;
        int currSum;
        sort(nums.begin(), nums.end());

        for (int index1 = 0; index1 < nums.size() - 2; index1++) {
            if (index1 > 0 && nums[index1] == nums[index1 - 1]) continue;
            index2 = index1 + 1;
            index3 = nums.size() - 1;
            while (index2 < index3) {
                currSum = nums[index1] + nums[index2] + nums[index3];
                if (currSum < 0) index2++;
                if (currSum > 0) index3--;
                if (currSum == 0) {
                    if (final.size() == 0) final.push_back({nums[index1], nums[index2], nums[index3]});
                    if (vector<int>{nums[index1], nums[index2], nums[index3]} != final[final.size() - 1]){
                        final.push_back({nums[index1], nums[index2], nums[index3]});
                    }
                    index2++;
                    index3--;
                }
            }


        }
        return final;
    }
};
