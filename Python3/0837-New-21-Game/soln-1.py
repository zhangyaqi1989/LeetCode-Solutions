class Solution:
    def new21Game(self, N: int, K: int, W: int) -> float:
        # starts with 0
        # draws numbers while she has less than K points
        # [1, W]
        if K == 0 or N >= K + W: return 1
        dp = [1.0] + [0.0] * N
        window = 1.0
        for i in range(1, N + 1):
            dp[i] = window / W
            if i < K:
                window += dp[i]
            if i - W >= 0:
                window -= dp[i - W]
        return sum(dp[K:])
