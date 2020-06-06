class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1
        for i, ch in enumerate(s):
            if ch != '0':
                dp[i + 1] += dp[i]
            if i >= 1 and "09" < s[i - 1:i + 1] < "27":
                dp[i + 1] += dp[i - 1]
        return dp[-1]
