from functools import lru_cache
class Solution:
    @lru_cache(None)
    def divisorGame(self, N: int) -> bool:
        if N == 1:
            return False
        if N == 2:
            return True
        if all(self.divisorGame(N - factor) for factor in range(1, int(math.sqrt(N)) + 1) if N % factor == 0):
            return False
        return True
