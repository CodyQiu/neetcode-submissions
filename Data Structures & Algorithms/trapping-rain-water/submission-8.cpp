class Solution {
public:
    int trap(vector<int>& height) {
        int pre[height.size()];
        int suf[height.size()];
        int index = 0;
        int area = 0;
        pre[index] = 0;
        index++;

        while (index < height.size()) {
            if (height[index] < pre[index - 1]) {
                pre[index] = pre[index - 1];
            } else {
                pre[index] = max(height[index], height[index - 1]);
            }
            index++;
        }

        int index2 = height.size() - 1;
        suf[index2] = 0;
        index2--;
        while (index2 > 0) {
            if (height[index2] < suf[index2 + 1]) {
                suf[index2] = suf[index2 + 1];
            } else {
                suf[index2] = max(height[index2], height[index2 + 1]);
            }
            index2--;
        }

        for (int i = 0; i < height.size(); i++) {
            int temp = min(pre[i], suf[i]) - height[i];;
            if (temp >= 0) area += temp;
        }
        return area;
    }
};
