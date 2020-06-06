from functools import lru_cache
class Solution:
    def minDifficulty(self, jobs: List[int], d: int) -> int:
        pres = [0]
        for job in jobs:
            pres.append(pres[-1] + job)
        n = len(jobs)
        @lru_cache(None)
        def dp(idx, d):
            if n - idx < d:
                return math.inf
            elif n - idx == d:
                return pres[n] - pres[idx]
            else:
                if d == 0 and idx < n:
                    return math.inf
                mx = -math.inf
                ans = math.inf
                for j in range(idx, n - (d - 1)):
                    mx = max(mx, jobs[j])
                    ans = min(ans, mx + dp(j + 1, d - 1))
                return ans
        ans = dp(0, d)
        return ans if ans != math.inf else -1
