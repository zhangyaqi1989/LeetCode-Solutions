class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        # s[i:j]
        n = len(s)
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        for L in range(1, n + 1):
            for lo in range(n):
                hi = lo + L - 1
                if hi < n:
                    if lo == hi:
                        dp[lo][hi] = 1
                    else:
                        if s[lo] == s[hi]:
                            dp[lo][hi] = dp[lo + 1][hi - 1] + 2
                        else:
                            dp[lo][hi] = max(dp[lo + 1][hi], dp[lo][hi - 1])
                else:
                    break
        return dp[0][n - 1]
