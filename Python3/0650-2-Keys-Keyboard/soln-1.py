from functools import lru_cache
class Solution:
    def minSteps(self, n: int) -> int:
        @lru_cache(None)
        def helper(n):
            if n == 1:
                return 0
            else:
                res = n
                for x in range(n - 1, 0, -1):
                    factor = n - x
                    if n % factor == 0:
                        temp = helper(factor) + n // factor
                        res = min(temp, res)
                return res
        return helper(n)
        
