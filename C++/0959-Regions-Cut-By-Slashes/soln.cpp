class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = 3 * n;
        vector<vector<int>> matrix(m, vector<int>(m, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    matrix[3 * i][3 * j + 2] = 1;
                    matrix[3 * i + 1][3 * j + 1] = 1;
                    matrix[3 * i + 2][3 * j] = 1;
                } else if (grid[i][j] == '\\') {
                    matrix[3 * i][3 * j] = 1;
                    matrix[3 * i + 1][3 * j + 1] = 1;
                    matrix[3 * i + 2][3 * j + 2] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    dfs(i, j, matrix);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
    
    void dfs(int i, int j, vector<vector<int>> & matrix) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == 1) return;
        matrix[i][j] = 1;
        dfs(i - 1, j, matrix);
        dfs(i + 1, j, matrix);
        dfs(i, j - 1, matrix);
        dfs(i, j + 1, matrix);
    }
};
