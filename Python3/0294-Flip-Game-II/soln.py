from functools import lru_cache
class Solution:
    @lru_cache(None)
    def canWin(self, s):
        """
        :type s: str
        :rtype: bool
        """
        return any(s[i:i + 2] == '++' and not self.canWin(s[:i] + '--' + s[i + 2:])
                   for i in range(len(s) - 1))
