from functools import lru_cache
sys.setrecursionlimit(1000000000)
class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        # exact target neighborhoods
        @lru_cache(None)
        def helper(idx, target, last):
            if idx == len(houses):
                return 0 if target == 0 else math.inf
            if target < 0:
                return math.inf
            ans = math.inf
            if houses[idx] != 0: # painted before
                new_target = target
                if houses[idx] != last:
                    new_target -= 1
                temp = helper(idx + 1, new_target, houses[idx])
                ans = min(ans, temp)
            else:
                for color in range(1, n + 1):
                    if color == last:
                        temp = cost[idx][color - 1] + helper(idx + 1, target, color)
                    else:
                        temp = cost[idx][color - 1] + helper(idx + 1, target - 1, color)
                    ans = min(ans, temp)
            return ans
        ans = helper(0, target, -1)
        return ans if ans != math.inf else -1
