class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // int i = 0, j = 0;
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int cnt = 1;
        while (cnt <= n * n) {
            for(int j = left; j <= right; ++j) {
                matrix[top][j] = cnt++;
            }
            ++top;
            for(int i = top; i <= bottom; ++i) {
                matrix[i][right] = cnt++;
            }
            --right;
            for(int j = right; j >= left; --j) {
                matrix[bottom][j] = cnt++;
            }
            --bottom;
            for(int i = bottom; i >= top; --i) {
                matrix[i][left] = cnt++;
            }
            ++left;
        }
        return matrix;
    }
};
