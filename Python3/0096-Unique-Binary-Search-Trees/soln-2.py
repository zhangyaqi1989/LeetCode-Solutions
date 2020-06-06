from functools import lru_cache
class Solution:
    def numTrees(self, n: int) -> int:
        @lru_cache(None)
        def helper(n):
            if n <= 1:
                return 1
            else:
                ans = 0
                for root in range(1, n + 1):
                    ans += helper(root - 1) * helper(n - root)
            return ans
        return helper(n)
