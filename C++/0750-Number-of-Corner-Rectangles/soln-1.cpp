class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        // use two long long
        int width = 32;
        const int kR = grid.size();
        const int kC = grid[0].size();
        vector<vector<unsigned int>> memo(kR, vector<unsigned int>((kC + width - 1) / width, 0LL));
        int ans = 0;
        for(int i = 0; i < kR; ++i) {
            for(int j = 0; j < kC; ++j) {
                if(grid[i][j] == 1) {
                    int r = j / width;
                    int c = j % width;
                    memo[i][r] |= (1LL << c);
                }
            }
            for(int pre = 0; pre < i; ++pre) {
                int match = 0;
                for(int j = 0; j < memo[0].size(); ++j) {
                    match += __builtin_popcount(memo[pre][j] & memo[i][j]);
                }
                if(match > 1) {
                    ans += match * (match - 1) / 2;
                }
            }
        }
        return ans;
    }
};
