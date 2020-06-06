class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int acc = 0;
        for(int j = 1; j < n + 1; ++j)
        {
            acc += s2[j - 1];
            dp[0][j] = acc;
        }
        acc = 0;
        for(int i = 1; i < m + 1; ++i)
        {
            acc += s1[i - 1];
            dp[i][0] = acc;
        }
        for(int i = 1; i < m + 1; ++i)
            for(int j = 1; j < n + 1; ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(s1[i - 1] + s2[j - 1] + dp[i - 1][j - 1], min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]));
            }
        return dp[m][n];
        
    }
};