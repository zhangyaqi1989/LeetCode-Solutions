class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.length();
        int N = (1 << n);
        vector<int> dp(N, -1);
        dp[0] = 0;
        for(int i = 0; i < N; ++i) {
            if (dp[i] == -1) continue;
            for(auto & s : stickers) {
                int now = i;
                for(auto ch : s) {
                    for(int j = 0; j < n; ++j) {
                        if (target[j] == ch && !(now & (1 << j))) {
                            now |= (1 << j);
                            break;
                        }
                    }
                }
                if (dp[now] == -1) dp[now] = dp[i] + 1;
                else dp[now] = min(dp[now], dp[i] + 1);
            }
        }
        return dp.back();
    }
};
