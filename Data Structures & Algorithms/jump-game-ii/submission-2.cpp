class Solution {
public:
    int jump(vector<int>& nums) {
        int curr = 0;
        int steps = 0;
        while (curr < nums.size() - 1) {
            int next = curr;
            for (int i = curr; i <= curr + nums[curr]; i++) {
                if (i >= nums.size() - 1) return steps + 1;
                if (i + nums[i] >= next + nums[next]) {
                    next = i;
                }
            }
            if (curr == next) curr = curr + nums[curr];
            else curr = next;
            steps++;
        }
        return steps;
    }
};
