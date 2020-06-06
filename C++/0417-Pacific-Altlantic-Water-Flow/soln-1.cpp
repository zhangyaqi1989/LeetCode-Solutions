class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        // equal or lower
        if (matrix.empty() || matrix[0].empty()) return {};
        const int kR = matrix.size(), kC = matrix[0].size();
        vector<vector<bool>> pacific(kR, vector<bool>(kC, false));
        vector<vector<bool>> atlantic(kR, vector<bool>(kC, false));
        for(int j = 0; j < kC; ++j) dfs(0, j, matrix, &pacific);
        for(int i = 1; i < kR; ++i) dfs(i, 0, matrix, &pacific);
        for(int i = 0; i < kR; ++i) dfs(i, kC - 1, matrix, &atlantic);
        for(int j = 0; j < kC - 1; ++j) dfs(kR - 1, j, matrix, &atlantic);
        vector<vector<int>> ans;
        for(int i = 0; i < kR; ++i) {
            for(int j = 0; j < kC; ++j) {
                if (pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
    
private:
    void dfs(int r, int c, const vector<vector<int>>& matrix, vector<vector<bool>> * visited) {
        const int kR = matrix.size(), kC = matrix[0].size();
        int dirs[5] = {0, 1, 0, -1, 0};
        (*visited)[r][c] = true;
        for(int k = 0; k < 4; ++k) {
            int dr = dirs[k], dc = dirs[k + 1];
            int new_r = r + dr, new_c = c + dc;
            if (0 <= new_r && new_r < kR && 0 <= new_c && new_c < kC && !(*visited)[new_r][new_c] && matrix[new_r][new_c] >= matrix[r][c]) {
                dfs(new_r, new_c, matrix, visited);
            }
        }
    }
};
