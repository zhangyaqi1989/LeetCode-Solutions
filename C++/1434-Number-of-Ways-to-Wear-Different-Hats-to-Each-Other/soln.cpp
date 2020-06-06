class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<int> dp(1 << n, 0);
        dp[0] = 1;
        vector<vector<int>> people(41);
        for(int i = 0; i < n; ++i) {
            for(int h : hats[i]) {
                people[h].push_back(i);
            }
        }
        const int MOD = 1000000007;
        for(int hat = 1; hat <= 40; ++hat) {
            vector<int> new_dp(1 << n);
            new_dp = dp;
            for(int state = 0; state < (1 << n); ++state) {
                for(int p : people[hat]) {
                    if(!(state & (1 << p))) {
                        int new_state = state | (1 << p);
                        new_dp[new_state] += dp[state];
                        if(new_dp[new_state] >= MOD) new_dp[new_state] -= MOD;
                    }
                }
            }
            swap(dp, new_dp);
        }
        return dp[(1 << n) - 1];
    }
};
