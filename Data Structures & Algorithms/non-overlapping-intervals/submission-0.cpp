class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); 
        int num = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i - 1][1] > intervals[i][0]) {
                if (intervals[i - 1][1] < intervals[i][1]) intervals[i] = intervals[i - 1];
                num++;
            }
        }
        return num;
    }
};
