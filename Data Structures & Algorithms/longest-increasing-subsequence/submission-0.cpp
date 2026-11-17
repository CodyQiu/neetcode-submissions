class Solution {
public:
    int dfs(vector<int>& nums, int index, unordered_map<int,int>& m) {
        if (index >= nums.size()) return 0;
        if (m.contains(index)) return m[index];
        int best = 1;
        
        for (int i = 0; i < index; i++) {
            if (nums[i] < nums[index]) {
                best = max(best, dfs(nums, i, m) + 1);
            }
        }
        m[index] = best;
        return best;
    }

    int lengthOfLIS(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans,dfs(nums, i, m));
        }
        return ans;
    }
};
