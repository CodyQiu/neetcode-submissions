class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;
        if (nums.size() <= 1) return true;
        while (pos < nums.size() - 1) {
            int range = nums[pos];
            int next = pos;
            if (next + nums[next] >= nums.size() - 1) return true;
            for (int i = pos; i <= pos + nums[pos]; i++) {
                if (i + nums[i] >= next + nums[next]) next = i;
            }
            if (pos == next) pos = next + nums[next];
            if (next + nums[next] >= nums.size() - 1) return true;
            if (next == pos) return false;
            pos = next;
        }
        return false;
    }
};
