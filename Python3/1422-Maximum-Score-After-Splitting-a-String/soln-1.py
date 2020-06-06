class Solution:
    def maxScore(self, s: str) -> int:
        n = len(s)
        ones = s.count('1')
        ans = -1
        zeros = 0
        for i in range(n - 1):
            zeros += s[i] == '0'
            ones -= s[i] == '1'
            ans = max(ans, zeros + ones)
        return ans
