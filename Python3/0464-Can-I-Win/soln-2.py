from functools import lru_cache
class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        cands = set(range(1, maxChoosableInteger + 1))
        if sum(cands) < desiredTotal:
            return False
        return self.helper(frozenset(cands), desiredTotal)
    
    @lru_cache(None)
    def helper(self, cands, total):
        if max(cands) >= total:
            return True
        if all(self.helper(cands - {cand}, total - cand) for cand in cands):
            return False
        return True
