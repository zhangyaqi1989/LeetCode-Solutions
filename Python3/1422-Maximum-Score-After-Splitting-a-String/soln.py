class Solution:
    def maxScore(self, s: str) -> int:
        n = len(s)
        return max(s[:i].count('0') + s[i:].count('1') for i in range(1, n))
