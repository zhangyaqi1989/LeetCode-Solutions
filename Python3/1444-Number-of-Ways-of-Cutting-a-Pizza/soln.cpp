from functools import lru_cache
MOD = 1000000007
class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        # need to know a XXX
        h, w = len(pizza), len(pizza[0])
        pres = [[0] * (w + 1) for _ in range(h + 1)]
        for r, row in enumerate(pizza):
            for c, val in enumerate(row):
                pres[r + 1][c + 1] = (val == 'A') + pres[r + 1][c] + pres[r][c + 1] - pres[r][c]
        def count(r0, c0, r1, c1):
            return pres[r1 + 1][c1 + 1] + pres[r0][c0] - pres[r1 + 1][c0] - pres[r0][c1 + 1]
        @lru_cache(None)
        def dp(r0, c0, r1, c1, k):
            total = count(r0, c0, r1, c1)
            # print(r0, c0, r1, c1, k, total)
            if k > total:
                return 0
            if k == 1:
                return 1 if total > 0 else 0
            ans = 0
            for r_cut in range(r0, r1):
                up = count(r0, c0, r_cut, c1)
                if up > 0 and up < total:
                    ans = (ans + dp(r_cut + 1, c0, r1, c1, k - 1)) % MOD
                if up == total:
                    break
            for c_cut in range(c0, c1):
                left = count(r0, c0, r1, c_cut)
                if 0 < left < total:
                    ans = (ans + dp(r0, c_cut + 1, r1, c1, k - 1)) % MOD
                if left == total:
                    break
            # print(r0, c0, r1, c1, k, ans)
            return ans
        # return dp(1, 0, 2, 2, 2)
        return dp(0, 0, h - 1, w - 1, k)
        
        
