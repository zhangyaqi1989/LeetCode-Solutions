import functools
class Solution:
    def getMaxGridHappiness(self, m: int, n: int, introvertsCount: int, extrovertsCount: int) -> int:
        def compute_gain(r, c, mask_in, mask_ex, d):
            diff = 0
            up = (1 << (n - 1))
            if r > 0 and (mask_in & up): 
                diff += d - 30
            if c > 0 and (mask_in & 1):
                diff += d - 30
            if r > 0 and (mask_ex & up):
                diff += d + 20
            if c > 0 and (mask_ex & 1):
                diff += d + 20
            return diff
        @functools.lru_cache(None)
        def dp(p, n_in, n_ex, mask_in, mask_ex):
            r, c = p // n, p % n
            if r >= m:
                return 0
            new_mask_in = (mask_in << 1) & ((1 << (n)) - 1)
            new_mask_ex = (mask_ex << 1) & ((1 << (n)) - 1)
            ans = dp(p + 1, n_in, n_ex, new_mask_in, new_mask_ex)
            if n_in > 0:
                gain = compute_gain(r, c, mask_in, mask_ex, -30)
                ans = max(ans, 120 + gain + dp(p + 1, n_in - 1, n_ex, new_mask_in | 1, new_mask_ex))
            if n_ex > 0:
                gain = compute_gain(r, c, mask_in, mask_ex, 20)
                ans = max(ans, 40 + gain + dp(p + 1, n_in, n_ex - 1, new_mask_in, new_mask_ex | 1))
            return ans
        return dp(0, introvertsCount, extrovertsCount, 0, 0)
