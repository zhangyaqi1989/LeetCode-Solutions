class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        n = len(A)
        dp = [collections.Counter() for _ in range(n)]
        ans = 0
        for i in range(n):
            for j in range(i - 1, -1, -1):
                dp[i][A[i] - A[j]] = max(dp[i][A[i] - A[j]], dp[j][A[i] - A[j]] + 1)
                ans = max(ans, dp[i][A[i] - A[j]])
        return ans + 1
