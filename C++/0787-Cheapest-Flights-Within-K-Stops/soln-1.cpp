class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        const int kInf = 10000000;
        vector<vector<int>> dp(2, vector<int>(n, kInf));
        dp[1][src] = dp[0][src] = 0;
        K = min(K, n - 1);
        for(int i = 0; i < K + 1; ++i) {
            int cur = (i & 1), pre = (i + 1) & 1;
            for(const auto & flight : flights) {
                int u = flight[0], v = flight[1], w = flight[2];
                dp[cur][v] = min(dp[pre][u] + w, dp[cur][v]);
            }
        }
        int cur = K & 1;
        return dp[cur][dst] == kInf ? -1 : dp[cur][dst];
    }
};
