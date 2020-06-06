class Solution:
    def maxSumAfterPartitioning(self, A: List[int], K: int) -> int:
        n = len(A)
        dp = [0] * (n + 1)
        for i in range(n):
            temp = A[i] + dp[i]
            for j in range(i - 1, max(-1, i - K), -1):
                cur = dp[j] + max(A[j:i + 1]) * (i - j + 1)
                if cur > temp:
                    temp = cur
            dp[i + 1] = temp
        return dp[-1]
