class Solution:
    def numWays(self, s: str) -> int:
        nones = s.count('1')
        MOD = 1000000007
        n = len(s)
        if nones % 3 != 0:
            return 0
        if nones == 0:
            ans = 0
            for i in range(n - 2):
                ans += (n - i - 1 - 1)
            return ans % MOD
        else:
            m = nones // 3
            l = 0
            cnt = 0
            while l < n:
                if s[l] == '1':
                    cnt += 1
                    if cnt == m:
                        break
                l += 1
            r = n - 1
            cnt = 0
            while r >= 0:
                if s[r] == '1':
                    cnt += 1
                    if cnt == m:
                        break
                r -= 1
            lcnt = 1
            l = l + 1
            while l < n and s[l] == '0':
                lcnt += 1
                l += 1
            rcnt = 1
            r = r - 1
            while r >= 0 and s[r] == '0':
                rcnt += 1
                r -= 1
            return lcnt * rcnt % MOD
