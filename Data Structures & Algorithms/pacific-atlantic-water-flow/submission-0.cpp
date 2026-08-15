class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<vector<int>> q;
        // Pacific
        vector<vector<int>> vals(heights.size(), vector<int>(heights[0].size(),0));
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (i == 0 || j == 0) {
                    q.push({i,j});
                    vals[i][j] = 1;
                }
            }
        }
        vector<vector<int>> dirs = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };
        while (q.size() > 0) {
            auto temp = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int r = temp[0] + dirs[i][0];
                int c = temp[1] + dirs[i][1];

                if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size()) {
                    continue;
                }
                if (vals[r][c] != 0) continue;
                if (heights[r][c] >= heights[temp[0]][temp[1]]) {
                    vals[r][c] += 1;
                    q.push({r,c});
                }
            }
        }
        // Atlantic
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (i == heights.size() - 1 || j == heights[0].size() - 1) {
                    q.push({i,j});
                    vals[i][j] += 10;
                }
            }
        }

        while (q.size() > 0) {
            auto temp = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int r = temp[0] + dirs[i][0];
                int c = temp[1] + dirs[i][1];
                                if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size()) {
                    continue;
                }
                if (vals[r][c] >= 10) {
                    continue;
                }
                if (heights[r][c] >= heights[temp[0]][temp[1]]) {
                    vals[r][c] += 10;
                    q.push({r,c});
                }
            }
        }
        // Submit
        vector<vector<int>> works;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (vals[i][j] == 11) works.push_back({i,j});
            }
        }
        return works;
    }
};
