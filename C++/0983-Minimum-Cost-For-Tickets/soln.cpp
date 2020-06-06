auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
#define min3(a, b, c) min(a, min(b, c))

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int e = days.back();
        vector<int> dp(e + 1, INT_MAX);
        dp[0] = 0;
        int d[366] = {0};
        for(auto day : days) d[day] = 1;
        for(int i = 1; i <= e; ++i) {
            if (!d[i]) dp[i] = dp[i - 1];
            else
            dp[i] = min3(dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]);
        }
        return dp.back();
    }
};
