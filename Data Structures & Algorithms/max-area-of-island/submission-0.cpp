class Solution {
public:


    void recurse(vector<vector<int>>& grid, int i, int j, int& size, int& maxSize) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] == 0) return;
        grid[i][j] = 0;
        size++;
        recurse(grid, i + 1, j, size, maxSize);
        recurse(grid, i - 1, j, size, maxSize);
        recurse(grid, i, j + 1, size, maxSize);
        recurse(grid, i, j - 1, size, maxSize);


    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int size = 0;
                recurse(grid, i, j, size, maxSize);
                maxSize = max(maxSize, size);
            }
        }
        return maxSize;
    }
};
