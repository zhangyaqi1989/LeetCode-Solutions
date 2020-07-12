class Solution:
    def numSub(self, s: str) -> int:
        ans = 0
        for ch, g in itertools.groupby(s):
            if ch == '1':
                cnt = len(list(g))
                ans += (1 + cnt) * cnt // 2
        return ans % 1000000007
