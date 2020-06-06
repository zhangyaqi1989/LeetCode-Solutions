class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int dp[26] = {0};
        for (char ch : p) {
            dp[ch - 'a'] = 1;
        }
        int len = 1, n = p.length();
        for(int i = 0; i < n - 1; ++i) {
            char a = p[i], b = p[i + 1];
            if (b - a == 1 || (a == 'z' && b == 'a')) {
                ++len;
            } else {
                len = 1;
            }
            dp[b - 'a'] = max(dp[b - 'a'], len);
        }
        return accumulate(dp, dp + 26, 0);
    }
};
