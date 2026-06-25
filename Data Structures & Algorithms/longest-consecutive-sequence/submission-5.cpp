class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> total;
        unordered_map<int, int> above;
        for (int i: nums) total.insert(i);
        int maxRun = 0;

        for (int i: nums) {
            if (above.contains(i)) continue;
            int curr = 1;
            // Count all the above
            int j = i + 1;
            while (total.contains(j)) {
                if (above.contains(j)) {
                    curr += above[j];
                    break;
                }
                above[j] = 1;
                j++;
                curr++;
            }
            above[i] = curr;
            maxRun = max(maxRun, curr);
        }
        return maxRun;
    }
};