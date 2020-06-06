class Solution:
    def longestRepeatingSubstring(self, S: str) -> int:
        n = len(S)
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        ans = 0
        for i in range(1, n + 1):
            for j in range(i + 1, n + 1):
                if S[i - 1] == S[j - 1]:
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j])
                    ans = max(ans, dp[i][j])
        return ans
