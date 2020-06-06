from functools import lru_cache
class Solution:
    def numMusicPlaylists(self, N, L, K):
        """
        :type N: int
        :type L: int
        :type K: int
        :rtype: int
        """
        @lru_cache(None)
        def dp(i, j):
            if i == 0:
                return j == 0
            ans = dp(i - 1, j - 1) * (N - j + 1) + dp(i - 1, j) * max(0, j - K)
            return ans % (10 ** 9 + 7)
        return dp(L, N)