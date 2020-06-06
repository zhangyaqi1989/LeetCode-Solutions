from functools import lru_cache
class Solution:
    def numMusicPlaylists(self, N: int, L: int, K: int) -> int:
        @lru_cache(None)
        def helper(N, L):
            if L == N or N == K + 1:
                return math.factorial(N) % 1000000007
            if N > L:
                return 0
            else:
                return (helper(N - 1, L - 1) * N + helper(N, L - 1) * (N - K)) % 1000000007
        return helper(N, L) % 1000000007
