class Solution {
public:
    int trap(vector<int>& height) {
        vector<pair<int, int>> intervals;;
        int area = 0;
        int left = 0;
        while (height[left] == 0) {
            left++;
            if (left >= height.size()) break;
        }
        int right = left + 1;
        if (right >= height.size()) return 0;
        pair<int, int> maxTemp = {height[right], right};
        while (left <= height.size() - 1) {
            if (right >= height.size()) {
                area += (maxTemp.second - left - 1) * min(height[left], maxTemp.first);
                intervals.push_back({left, maxTemp.second});
                left = maxTemp.second;
                right = left + 1;
                if (right >= height.size()) break;
                maxTemp = {height[right], right};
                continue;
            }
            maxTemp = max(maxTemp, {height[right], right});
            if (height[left] > height[right]) {
                right++;
            } else {
                area += (right - left - 1) * min(height[left], height[right]);
                intervals.push_back({left, right});
                left = right;
                right++;
                if (right == height.size()) {
                    maxTemp = max(maxTemp, {height[right - 1], right - 1});
                    break;
                }
                maxTemp = {height[right], right};
            }
        }
        for (auto& x: intervals) {
            for (int i = x.first + 1; i < x.second; i++) {
                area -= height[i];
            }
        }
        return area;
    }
};
