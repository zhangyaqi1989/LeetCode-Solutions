class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        zero = ord('a')
        dp = [0] * 26
        for ch in p:
            dp[ord(ch) - zero] = 1
        n = len(p)
        length = 1
        for i in range(n - 1):
            a, b = p[i], p[i + 1]
            if (ord(b) - ord(a)) % 26 == 1:
                length += 1
            else:
                length = 1
            dp[ord(b) - zero] = max(dp[ord(b) - zero], length)
        return sum(dp)
