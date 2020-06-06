class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp = {0};
        while (dp.size() <= n) {
            int m = dp.size();
            int val = m;
            int j = 1;
            while (j * j <= m) {
                val = min(val, dp[m - j * j] + 1);
                ++j;
            }
            dp.push_back(val);
        }
        return dp[n];
        
    }
};
