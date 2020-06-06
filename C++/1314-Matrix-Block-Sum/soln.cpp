class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        const int kR = mat.size(), kC = mat[0].size();
        vector<vector<int>> dp(kR + 1, vector<int>(kC + 1, 0));
        for(int i = 0; i < kR; ++i) {
            for(int j = 0; j < kC; ++j) {
                dp[i + 1][j + 1] = mat[i][j] + dp[i + 1][j] + dp[i][j + 1] - dp[i][j];
            }
        }
        vector<vector<int>> ans(kR, vector<int>(kC, 0));
        for(int r = 0; r < kR; ++r) {
            for(int c = 0; c < kC; ++c) {
                int r0 = max(0, r - K);
                int c0 = max(0, c - K);
                int r1 = min(kR - 1, r + K);
                int c1 = min(kC - 1, c + K);
                ans[r][c] = dp[r1 + 1][c1 + 1] + dp[r0][c0] - dp[r1 + 1][c0] - dp[r0][c1 + 1];
            }
        }
        return ans;
    }
};
