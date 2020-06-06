class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int h = matrix.size(), w = matrix[0].size();
        int cnt = 0;
        vector<vector<int>> dp(2, vector<int>(w + 1, 0));
        for(int i = 0; i < h; ++i) {
            int cur = i & 1, pre = 1 - cur;
            for(int j = 0; j < w; ++j) {
                if (matrix[i][j] == 1) {
                    dp[cur][j + 1] = min(dp[pre][j], min(dp[cur][j], dp[pre][j + 1])) + 1;
                    cnt += dp[cur][j + 1];
                } else {
                    dp[cur][j + 1] = 0;
                }
            }
        }
        return cnt;
    }
};
