class Solution:
    def new21Game(self, N, K, W):
        """
        :type N: int
        :type K: int
        :type W: int
        :rtype: float
        """
        if K == 0 or N >= K + W: return 1
        dp = [1.0] + [0.0] * N
        Wsum = 1.0
        for i in range(1, N + 1):
            dp[i] = Wsum / W
            if i < K: Wsum += dp[i]
            if i >= W: Wsum -= dp[i - W]
        return sum(dp[K:])
    
# In a word,
# dp[i]: probability of get points i
# dp[i] = sum(last W dp values) / W


# starts with 0, if points < K, draw from [1, W], ask the possibility of points less than N