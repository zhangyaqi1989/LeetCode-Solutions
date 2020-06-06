class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int ans = 0;
        for(int i = 1; i < m + 1; ++i) {
            for(int j = 1; j < n + 1; ++j) {
                if (matrix[i - 1][j - 1] == '0') dp[i][j] = 0;
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    ans = max(dp[i][j] * dp[i][j], ans);
                }
            }
        }
        return ans;
    }
};
