class Solution {
public:
    int numberOfWays(int n) {
        // even
        // compute number of handshake of n person that does not cross
        // n = 2, 1
        // n = 4, 2
        // n = 6, guess who is shaking hands with 1
        // 1-2:
        // 1-4:
        // 1-6:
        
        // n person
        // f(i) = number of ways of i person
        // f(n) = f(0) * f(n - 2) + f(2) * f(n - 4) + ... + f(n - 2) * f(0)
        // int 32, 2**31 - 1, 2 * 10^9 
        // %, (a + b) % c = (a % c + b % c) % c
        const int kMod = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 2; i <= n; i += 2) {
            for(int j = 0; j <= i - 2; ++j) {
                dp[i] = (dp[i] + (long long) dp[j] * dp[i - 2 - j] % kMod) % kMod;
            }
        }
        return dp.back();
    }
};
