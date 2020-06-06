from functools import lru_cache
sys.setrecursionlimit(100000000)
class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        MOD = 1000000007
        @lru_cache(None)
        def dp(idx):
            if idx == len(s):
                return 1
            num = 0
            ans = 0
            for nxt in range(idx, len(s)):
                num = num * 10 + int(s[nxt])
                if num > k or (nxt > idx and s[idx] == '0') or num <= 0:
                    break
                ans = (ans + dp(nxt + 1)) % MOD
            return ans
        return dp(0) % MOD
