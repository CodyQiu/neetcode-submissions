class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        vector<int> answer;
        int zeroCount = 0;
        for (int i: nums) {
            if (i == 0) zeroCount++;
            if (i != 0) product *= i;
        }
        if (zeroCount == 0) {
            for (int i: nums) {
                answer.push_back(product / i);
            }
            return answer;
        }
        else if (zeroCount == 1) {
            for (int i: nums) {
                if (i == 0) {
                    answer.push_back(product);
                } else {
                    answer.push_back(0);
                }
            }
            return answer;
        } else {
            return vector<int>(nums.size(),0);
        }
    }
};
