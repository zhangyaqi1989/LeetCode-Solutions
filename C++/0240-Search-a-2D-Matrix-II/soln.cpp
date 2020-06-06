class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
        int row = m - 1, col = 0;
        while (row >= 0 && col < n)
        {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                col += 1;
            else
                row -= 1;
        }
        return false;
    }
};