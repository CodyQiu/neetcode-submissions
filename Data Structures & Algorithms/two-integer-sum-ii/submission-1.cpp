class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0;
        int index2 = numbers.size() - 1;
        int currSum;
        while (currSum != target) {
            currSum = numbers[index1] + numbers[index2];
            if (currSum < target) index1++;
            else if (currSum > target) index2--;
        }
        index1++;
        index2++;
        return {index1, index2};
    }
};
