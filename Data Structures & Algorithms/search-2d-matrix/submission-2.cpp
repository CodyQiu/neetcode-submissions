class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m*n - 1;
        while (left <= right) {
            int center = (left + right) / 2;
            int i = 0;
            int j = 0;
            i = center / n;
            j = center % n;

            if (matrix[i][j] < target) {
                left = center + 1;
            } else if (matrix[i][j] > target) {
                right = center - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
