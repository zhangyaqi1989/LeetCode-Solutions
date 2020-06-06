const int kN = 70;
int memo[kN][kN][kN];

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(memo, -1, sizeof(memo));
        int cols = grid[0].size();
        return Helper(grid, 0, 0, cols - 1);
    }
    
private:
    int Helper(const vector<vector<int>> & grid, int r, int c1, int c2) {
        if(memo[r][c1][c2] != -1) return memo[r][c1][c2];
        int rows = grid.size(), cols = grid[0].size();
        if (r == rows - 1) {
            return grid[r][c1] + (c1 == c2 ? 0 : grid[r][c2]);
        }
        int ans = -1;
        
        for(int dc1 = -1; dc1 <= 1; ++dc1) {
            if(c1 + dc1 >= 0 && c1 + dc1 < cols) {
                for(int dc2 = -1; dc2 <= 1; ++dc2) {
                    if(c2 + dc2 >= 0 && c2 + dc2 < cols) {
                        ans = max(ans, Helper(grid, r + 1, c1 + dc1, c2 + dc2));
                    }
                }                
            }
        }
        ans += c1 == c2 ? grid[r][c1] : (grid[r][c1] + grid[r][c2]);
        return memo[r][c1][c2] = ans;
    }
};
