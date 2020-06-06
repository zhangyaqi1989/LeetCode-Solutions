class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        const int kInf = n + 100;
        vector<int> dp (n + 1, kInf);
        for(int i = 0; i < n + 1; ++i) {
            int left = max(0, i - ranges[i]);
            int best = (i - ranges[i] > 0) ? (dp[left] + 1) : 1;
            for(int j = i; j < min(i + ranges[i] + 1, n + 1); ++j) {
                dp[j] = min(dp[j], best);
            }
        }
        return dp.back() == kInf ? -1 : dp.back();
    }
};
