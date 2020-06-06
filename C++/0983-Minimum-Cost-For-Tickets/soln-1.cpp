class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int mx = days[n - 1];
        vector<int> dp(mx + 1, INT_MAX);
        dp[0] = 0;
        int i = 0;
        int c1 = costs[0], c7 = costs[1], c30 = costs[2];
        for(int day = 1; day <= mx; ++day) {
            if (day != days[i]) {
                dp[day] = dp[day - 1];
            } else {
                dp[day] = min(c1 + dp[day - 1], min(c7 + dp[max(0, day - 7)], c30 + dp[max(0, day - 30)]));
                ++i;
            }
        }
        return dp[mx];
    }
};
