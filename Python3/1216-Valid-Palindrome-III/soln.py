class Solution:
    def isValidPalindrome(self, s: str, k: int) -> bool:
        # longest palindrome subsequence
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for L in range(1, n + 1):
            for lo in range(n):
                if lo + L > n:
                    break
                hi = lo + L - 1
                if lo == hi:
                    dp[lo][hi] = 1
                else:
                    if s[lo] == s[hi]:
                        dp[lo][hi] = dp[lo + 1][hi - 1] + 2
                    else:
                        dp[lo][hi] = max(dp[lo + 1][hi], dp[lo][hi - 1])
        m = dp[0][n - 1]
        return m + k >= n
