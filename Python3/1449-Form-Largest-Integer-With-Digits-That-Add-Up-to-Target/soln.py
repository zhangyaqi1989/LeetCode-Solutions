from functools import lru_cache
class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:
        def larger(cand, ans):
            if len(cand) == len(ans):
                return cand > ans
            else:
                return len(cand) > len(ans)
            
        @lru_cache(None)
        def dp(target):
            if target == 0:
                return ""
            ans = "0"
            for ch, c in enumerate(cost, 1):
                if target - c >= 0:
                    cand = str(ch) + dp(target - c)
                    if cand[-1] != "0":
                        if ans == "0":
                            ans = cand
                        else:
                            if larger(cand, ans):
                                ans = cand
            return ans
        return dp(target)
