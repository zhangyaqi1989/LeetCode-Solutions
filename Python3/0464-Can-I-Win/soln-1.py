from functools import lru_cache
class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        if sum(range(1, maxChoosableInteger + 1)) < desiredTotal:
            return False
        used = [False] * (maxChoosableInteger + 1)
        return self.helper(tuple(used), desiredTotal)
    
    @lru_cache(None)
    def helper(self, used, total):
        mx = max(i for i in range(1, len(used)) if not used[i])
        if mx >= total:
            return True
        used = list(used)
        for i in range(1, mx + 1):
            if not used[i]:
                used[i] = True
                can_win = self.helper(tuple(used), total - i)
                used[i] = False
                if can_win == False:
                    return True
        return False
