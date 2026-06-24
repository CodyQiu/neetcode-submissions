class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int min = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int max = m * n - 1;

        while (max >= min) {
            int x = (max + min)/2 % n;
            int y = ((max + min)/2) / n;

            if (matrix[y][x] == target) {
                return true;
            } else if (matrix[y][x] < target) {
                max = max;
                min = (max + min) / 2 + 1;
            } else {
                max = (max + min) / 2 - 1;
                min = min;
            }
        }
        return false;
    }
};
