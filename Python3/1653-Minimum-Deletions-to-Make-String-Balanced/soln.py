class Solution:
    def minimumDeletions(self, s: str) -> int:
        # no b is front of a
        cnt_a = s.count('a')
        ans = cnt_a
        a = 0
        for i, ch in enumerate(s):
            a += (ch == 'a')
            ndeletes = (i + 1) - a + (cnt_a - a)
            ans = min(ans, ndeletes)
        return ans
