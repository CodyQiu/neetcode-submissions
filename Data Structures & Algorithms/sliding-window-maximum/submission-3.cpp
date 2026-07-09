class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> freq;
        vector<int> final;
        int largest = INT_MIN;
        for (int i = 0; i < k; i++) {
            largest = max(largest, nums[i]);
            freq[nums[i]]++;
        }
        final.push_back(largest);
        int left = 0;
        int right = k - 1;
        while (right < nums.size() - 1) {
            right++;
            freq[nums[right]]++;
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) freq.erase(nums[left]);
            left++;
            if (nums[right] > largest) largest = nums[right];
            else {
                largest = freq.rbegin() -> first;
            }

            final.push_back(largest);
        }
        return final;
    }
};
