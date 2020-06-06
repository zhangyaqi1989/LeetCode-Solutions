class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) return 1;
        vector<double> dp(K, 0);
        dp[0] = 1.0;
        const double kP = 1.0 / W;
        double acc = 1.0;
        for(int i = 1; i < K; ++i) {
            if (i - W - 1 >= 0) acc -= dp[i - W - 1];
            dp[i] = acc * kP;
            acc += dp[i];
        }
        double ans = 0.0;
        acc = 0;
        N = min(N, K - 1 + W);
        for(int j = max(N - W, 0); j < K; ++j) {
            acc += dp[j];
        }
        for(int i = N; i >= K; --i) {
            ans += acc * kP;
            if (i - W - 1 >= 0) acc += dp[i - W - 1];
        }
        return ans;
    }
};
