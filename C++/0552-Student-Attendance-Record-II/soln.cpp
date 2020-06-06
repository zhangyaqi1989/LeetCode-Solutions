class Solution {
public:
    int checkRecord(int n) {
        const long mod = 1000000007;
        vector<long> P(n + 1, 0);
        vector<long> PorL(n + 1, 0);
        P[0] = PorL[0] = 1;
        P[1] = 1;
        PorL[1] = 2;
        for(int i = 2; i <= n; ++i) {
            P[i] = PorL[i - 1];
            PorL[i] = (P[i] + P[i - 1] + P[i - 2]) % mod;
        }
        long ans = PorL[n];
        for(int i = 0; i < n; ++i) {
            ans = (ans + PorL[i] * PorL[n - i - 1] % mod) % mod;
        }
        return (int) ans;
    }
};
