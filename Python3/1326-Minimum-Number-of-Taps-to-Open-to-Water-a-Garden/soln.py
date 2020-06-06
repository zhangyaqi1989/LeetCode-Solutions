class Solution:
    def minTaps(self, n: int, A: List[int]) -> int:
        dp = [math.inf] * (n + 1)
        for i in range(0, n + 1):
            left = max(0, i - A[i])
            use = (dp[left] + 1) if i - A[i] > 0 else 1
            dp[i] = min(dp[i], use)
            for j in range(i, min(i + A[i] + 1, n + 1)):
                dp[j] = min(dp[j], use)
        # print(dp)
        return dp[-1] if dp[-1] != math.inf else -1
