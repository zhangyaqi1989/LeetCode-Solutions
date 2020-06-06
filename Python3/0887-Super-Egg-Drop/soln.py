class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        # K eggs and N floors
        # f(k, s) is the maximum floor we can check with k eggs and s steps
        # f(k, s) = 1 + f(k, s - 1) + f(k - 1, s - 1)
        dp = [0] * (K + 1)
        step = 0
        while dp[-1] < N:
            for i in range(K, 0, -1):
                dp[i] += 1 + dp[i - 1]
            step += 1
        return step
