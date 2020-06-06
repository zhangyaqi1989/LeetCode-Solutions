class Solution:
    def findSubstringInWraproundString(self, p):
        """
        :type p: str
        :rtype: int
        """
        dp = {ch : 1 for ch in p}
        length = 1
        for i in range(len(p) - 1):
            a, b = p[i], p[i + 1]
            if (ord(b) - ord(a)) % 26 == 1:
                length += 1
            else:
                length = 1
            dp[b] = max(dp[b], length)
        return sum(dp.values())
