class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max = 0;
        int curr = 0;
        int minHeight = 1000;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights.size() - i; j++) {
                if (heights[i+j] < minHeight) minHeight = heights[i+j];
                curr = minHeight * (j+1);
                if (curr > max) max = curr;
            }
            minHeight = 1000;
        }
        return max;
    }
};
