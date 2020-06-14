class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans(grid);
        int h = grid.size(), w = grid[0].size();
        int hw = h * w;
        k %= hw;
        if(k == 0) return ans;
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                int idx = i * w + j;
                idx = (idx + k) % hw;
                ans[idx / w][idx % w] = grid[i][j];
            }
        }
        return ans;
    }
};
