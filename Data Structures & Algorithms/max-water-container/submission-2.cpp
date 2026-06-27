class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxArea = (right - left) * min(heights[left], heights[right]);
        while (left < right) {
            if (heights[left] < heights[right]) left++;
            else right--;
            maxArea = max(maxArea, (right - left) * min(heights[left], heights[right]));
        }
        return maxArea;
    }
};
