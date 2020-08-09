class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        const int kH = grid.size(), kW = grid[0].size();
        for(int r = 0; r < kH; ++r) {
            for(int c = 0; c < kW; ++c) {
                if(r * c == 0 || r == kH - 1 || c == kW - 1) {
                    Fill(r, c, 0, 1, grid);
                }
            }
        }
        int ans = 0;
        for(int r = 0; r < kH; ++r) {
            for(int c = 0; c < kW; ++c) {
                if(grid[r][c] == 0) {
                    ++ans;
                    Fill(r, c, 0, 1, grid);
                }
            }
        }
        return ans;
    }
    
private:
    void Fill(int r, int c, int old_val, int new_val, vector<vector<int>> & grid) {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != old_val) return;
        grid[r][c] = new_val;
        Fill(r - 1, c, old_val, new_val, grid);
        Fill(r + 1, c, old_val, new_val, grid);
        Fill(r, c - 1, old_val, new_val, grid);
        Fill(r, c + 1, old_val, new_val, grid);
    }
};
