class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        size_t h = grid.size(), w = grid[0].size();
        vector<bitset<200>> memo(h);
        int ans = 0;
        for(size_t i = 0; i < h; ++i) {
            for(size_t j = 0; j < w; ++j) {
                if(grid[i][j] == 1) memo[i][j] = 1;
            }
            for(size_t r = 0; r < i; ++r) {
                int match = (memo[i] & memo[r]).count();
                if(match >= 2) {
                    ans += match * (match - 1) / 2;
                }
            }
        }
        return ans;
    }
};
