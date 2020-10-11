class Solution:
    def maxDepth(self, s: str) -> int:
        ans = 0
        nopens = 0
        for ch in s:
            if ch == '(':
                nopens += 1
                ans = max(ans, nopens)
            elif ch == ')':
                nopens -= 1
        return ans
