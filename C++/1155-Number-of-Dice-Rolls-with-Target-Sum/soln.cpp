class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        // 1,2,...,f
        // d dice, f faces, target
        // subproblem dp(i, j) number of ways to use i dices to get j
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
        const int kMod = 1000000007;
        dp[0][0] = 1;
        for(int i = 1; i <= d; ++i) {
            for(int j = 1; j <= target; ++j) {
                for(int pick = 1; pick <= min(j, f); ++pick) dp[i][j] = (dp[i][j] + dp[i - 1][j - pick]) % kMod;
            }
        }
        return dp[d][target];
    }
};
