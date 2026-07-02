class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> width(heights.size(), {0,0});
        stack<pair<int, int>> mono;
        int largest = 0;
        // index of left smaller than current
        for (int i = 0; i < heights.size(); i++) {
            if (mono.size() == 0) {
                mono.push({i, heights[i]});
                width[i].first = -1;
            }
            else {
                if (heights[i] > mono.top().second) {
                    width[i].first = mono.top().first;
                    mono.push({i, heights[i]});
                }
                else {
                    while (mono.size() != 0 && heights[i] <= mono.top().second) {
                        mono.pop();
                    }
                    if (mono.size() != 0) width[i].first = mono.top().first;
                    else width[i].first = -1;
                    mono.push({i, heights[i]});
                }
            }
        }
        while (mono.size() != 0) mono.pop();
        // index of right smaller than current 
        for (int i = heights.size() - 1; i >= 0; i--) {
            if (mono.size() == 0) {
                mono.push({i, heights[i]});
                width[i].second = heights.size();
            }
            else {
                if (heights[i] > mono.top().second) {
                    width[i].second = mono.top().first;
                    mono.push({i, heights[i]});
                }
                else {
                    while (!mono.empty() && heights[i] <= mono.top().second) {
                        mono.pop();
                    }
                    if (mono.size() != 0) width[i].second = mono.top().first;
                    else width[i].second = heights.size();
                    mono.push({i, heights[i]});
                }
            }
        }
        for (int i = 0; i < heights.size(); i++) {
            largest = max(largest, (width[i].second - width[i].first - 1) * heights[i]);
        }
        return largest; 
    }
};
