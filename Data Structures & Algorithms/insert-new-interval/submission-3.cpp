class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return {newInterval};

        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[0] > intervals[i][1]) {
                result.push_back(intervals[i]);
            }
            else if (newInterval[1] < intervals[i][0]) {
                result.push_back(newInterval);
                for (int j = i; j < intervals.size(); j++) result.push_back(intervals[j]);
                return result;
            }
            else {
                newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            }
        }
        if (newInterval[1] >= intervals[intervals.size() - 1][1]) result.push_back(newInterval);
        return result;
    }
};
