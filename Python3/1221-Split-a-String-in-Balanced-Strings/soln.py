class Solution:
    def balancedStringSplit(self, s: str) -> int:
        nls = 0
        cnt = 0
        for i, ch in enumerate(s):
            nls += ch == 'L'
            if i % 2 == 1 and (i + 1) // 2 == nls:
                cnt += 1
        return cnt
