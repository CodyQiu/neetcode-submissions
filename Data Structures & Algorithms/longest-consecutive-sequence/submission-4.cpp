class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> visited;
        unordered_set<int> total;
        unordered_map<int, int> above;
        for (int i: nums) total.insert(i);
        int maxRun = 0;

        for (int i: nums) {
            if (visited.contains(i)) continue;
            int curr = 1;
            visited.insert(i);
            // Count all the above
            int j = i + 1;
            while (total.contains(j)) {
                if (visited.contains(j)) {
                    curr += above[j];
                    break;
                }
                visited.insert(j);
                j++;
                curr++;
            }
            above[i] = curr;
            maxRun = max(maxRun, curr);
        }
        return maxRun;
    }
};
