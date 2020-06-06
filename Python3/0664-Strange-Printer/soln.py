from functools import lru_cache
class Solution:
    def strangePrinter(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Can not formulate this as a search problem
        @lru_cache(None)
        def helper(i, j):
            if i > j:
                return 0
            ans = helper(i + 1, j) + 1
            for k in range(i + 1, j + 1):
                if s[k] == s[i]:
                    ans = min(ans, helper(i, k - 1) + helper(k + 1, j))
            return ans
        return helper(0, len(s) - 1)
