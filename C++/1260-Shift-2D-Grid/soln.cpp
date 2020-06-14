class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int kR = grid.size(), kC = grid[0].size();
        const int kRC = kR * kC;
        vector<vector<int>> new_grid(kR, vector<int>(kC, 0));
        k %= kR * kC;
        for(int r = 0; r < kR; ++r) {
            for(int c = 0; c < kC; ++c) {
                int pos = r * kC + c;
                int new_pos = (pos + k) % kRC;
                new_grid[new_pos / kC][new_pos % kC] = grid[r][c];
            }
        }
        return new_grid;
    }
};
