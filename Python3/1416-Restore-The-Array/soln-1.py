class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        MOD = 1000000007
        memo = [-1] * (len(s) + 1)
        def dp(idx):
            if idx == len(s):
                return 1
            if memo[idx] != -1:
                return memo[idx]
            num = 0
            ans = 0
            for nxt in range(idx, len(s)):
                num = num * 10 + int(s[nxt])
                if num > k or (nxt > idx and s[idx] == '0') or num <= 0:
                    break
                ans = (ans + dp(nxt + 1)) % MOD
            memo[idx] = ans
            return ans
        return dp(0) % MOD
