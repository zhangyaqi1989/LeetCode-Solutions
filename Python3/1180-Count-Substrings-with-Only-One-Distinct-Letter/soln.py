class Solution:
    def countLetters(self, S: str) -> int:
        ans = 0
        for _, g in itertools.groupby(S):
            cnt = len(list(g))
            ans += (1 + cnt) * cnt // 2
        return ans
