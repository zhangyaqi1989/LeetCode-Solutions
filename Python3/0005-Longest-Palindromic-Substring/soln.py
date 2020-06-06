class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        def palin(l, r):
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l, r = l - 1, r + 1
            return s[l+1:r]
        n = len(s)
        res = ''
        for i in range(n):
            for l, r in ((i, i), (i, i + 1)):
                temp = palin(l, r)
                if len(temp) > len(res):
                    res = temp
        return res