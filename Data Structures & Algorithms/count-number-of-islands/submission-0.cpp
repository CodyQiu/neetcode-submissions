class Solution {
public:

    bool inBounds(vector<vector<char>>& grid, int x, int y) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }


    void helper(vector<vector<char>>& grid, int x, int y) {
        if (grid[x][y] == '0') return;
        grid[x][y] = '0';
        if (inBounds(grid, x+1,y)) helper(grid, x+1,y);
        if (inBounds(grid, x-1,y)) helper(grid, x-1,y);
        if (inBounds(grid, x,y+1)) helper(grid, x,y+1);
        if (inBounds(grid, x,y-1)) helper(grid, x,y-1);
    }



    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '0') continue;
                num++;
                helper(grid, i, j);
            }
        }
        return num;
    }
};
