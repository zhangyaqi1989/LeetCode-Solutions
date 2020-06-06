class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // n = 5000
        // DP[n][6][15]
        const int kFaces = 6;
        const long long kMod = 1000000007LL;
        vector<vector<int>> dp(6, vector<int>(16, 0));
        for(int i = 0; i < kFaces; ++i) {
            dp[i][1] = 1;
        }
        for(int k = 1; k < n; ++k) {
            vector<vector<int>> temp(6, vector<int>(16, 0));
            for(int i = 0; i < kFaces; ++i) {
                for(int times = 1; times <= rollMax[i]; ++times) {
                    long long cnt = 0LL;
                    for(int j = 0; j < kFaces; ++j) {
                        for(int t = 1; t <= rollMax[j]; ++t) {
                            if (times == 1) {
                                if (j == i) continue;
                                cnt = (cnt + dp[j][t]) % kMod;
                            } else {
                                if (j != i || t + 1 != times) continue;
                                cnt = (cnt + dp[j][t]) % kMod;
                            }
                        }
                    }
                    temp[i][times] = cnt;
                }
            }
            swap(temp, dp);
        }
        long long ans = 0LL;
        for(int i = 0; i < kFaces; ++i) {
            for(int t = 1; t < 16; ++t) {
                ans = (ans + dp[i][t]) % kMod;
            }
        }
        return static_cast<int>(ans);
    }
};
