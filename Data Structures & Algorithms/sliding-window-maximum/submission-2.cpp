class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        vector<int> final;
        int l = 0;
        int r = k - 1;
        for (int i = 0; i < k - 1; i++) {
            q.push({nums[i], i});
        }
        while (r < nums.size()) {
            q.push({nums[r], r});
            while (q.top().second > r || q.top().second < l) {
                q.pop();
            }
            final.push_back(q.top().first);
            l++;
            r++;
        }
        return final;
    }
};
