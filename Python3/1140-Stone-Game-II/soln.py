from functools import lru_cache
class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        # print(len(piles))
        accs = [0]
        for p in piles:
            accs.append(p + accs[-1])
        n = len(piles)
        @lru_cache(None)
        def helper(lo, M):
            if lo == n:
                return 0
            ans = 0
            for i in range(lo + 1, min(lo + 2 * M + 1, n + 1)):
                # pick lo:i
                x = i - lo
                M = max(M, x)
                temp = accs[n] - accs[lo] - helper(i, M)
                ans = max(temp, ans)
            return ans
        return helper(0, 1)
