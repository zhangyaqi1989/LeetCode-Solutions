from functools import lru_cache
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if collections.Counter(s1) != collections.Counter(s2):
            return False
        @lru_cache(None)
        def helper(s1, s2):
            if len(s1) != len(s2):
                return False
            if s1 == s2:
                return True
            for i in range(1, len(s1)):
                if (helper(s1[:i], s2[:i]) and helper(s1[i:], s2[i:])) or (helper(s1[:i], s2[-i:]) and helper(s1[i:], s2[:-i])):
                    return True
            return False
        return helper(s1, s2)
