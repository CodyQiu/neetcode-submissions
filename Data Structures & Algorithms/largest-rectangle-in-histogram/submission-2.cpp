class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n = heights.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);

        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i] ) {
                stk.pop();
            }
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if (!stk.empty()) right[i] = stk.top();
            stk.push(i);
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            left[i]++;
            right[i]--;
            int curr = heights[i] * (right[i] - left[i] + 1);
            if (max < curr) max = curr;
        }
        return max;

    }
};
