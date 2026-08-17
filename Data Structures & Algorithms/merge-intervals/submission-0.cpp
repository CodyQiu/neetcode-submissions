class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;

        int i = 1;
        while (i < intervals.size()) {
            if (intervals[i - 1][1] < intervals[i][0]) {
                result.push_back(intervals[i - 1]);
            } else {
                intervals[i] = {min(intervals[i-1][0],intervals[i][0]), max(intervals[i-1][1], intervals[i][1])};
            }
            i++;
        }
        result.push_back(intervals[intervals.size() - 1]);

        return result;
    }
};
