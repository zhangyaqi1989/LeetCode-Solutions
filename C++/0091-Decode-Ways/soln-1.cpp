class Solution {
public:
    int numDecodings(string s) {
        // DP
        // DP[i] = f(s[:i])
        // DP[0] = 1
        // DP[1] = 1 || 0
        // DP[i] = s[i - 1] == '1' - '9': DP[i] += DP[i - 1]
        //         '10' <= s[i - 2:i] <= '26': DP[i] += DP[i - 2]
        const int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for(int i = 2; i < n + 1; ++i) {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
            string last_two = s.substr(i - 2, 2);
            if ("10" <= last_two && last_two <= "26") dp[i] += dp[i - 2];
        }
        return dp.back();
    }
};
