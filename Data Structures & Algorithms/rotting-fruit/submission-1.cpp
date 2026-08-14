class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int goodLeft = 0;
        int time = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) q.push({i,j});
                else if (grid[i][j] == 1) goodLeft++;
            }
        }
        if (goodLeft == 0) return 0;
        vector<vector<int>> dirs = { 
            {-1,0}, {1,0}, {0,1}, {0,-1}
        };
        while (q.size() > 0) {
            auto temp = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int r = temp[0] + dirs[i][0];
                int c = temp[1] + dirs[i][1];

                if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
                    continue;
                }
                if (grid[r][c] != 1) continue;
                grid[r][c] = grid[temp[0]][temp[1]] + 1;
                time = max(time, grid[r][c]);
                goodLeft--;
                q.push({r,c});
            }
        }
        if (goodLeft > 0) return -1;
        else {
            return time - 2;
        }
    }
};
