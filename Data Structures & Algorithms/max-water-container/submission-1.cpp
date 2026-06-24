class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int index1 = 0;
        int index2 = heights.size() - 1;
        while (index1 < index2) {
            int height = min(heights[index1], heights[index2]);
            int currArea = height*(index2 - index1);
            if (currArea > maxArea) maxArea = currArea;
            if (heights[index1] > heights[index2]) index2--;
            else index1++;
        }
        return maxArea;
    }
};
