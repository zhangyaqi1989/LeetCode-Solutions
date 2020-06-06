class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        # traverse all possible positions, for each possible position, return its longest palindrome
        if len(s) < 2 or s == s[::-1]:
            return s
        n = len(s)
        def palin(l, r):
            while l >= 0 and r < n and s[l] == s[r]:
                l, r = l - 1, r + 1
            return s[l + 1:r]
        ans = ''
        for i in range(n):
            for l, r in ((i, i), (i, i + 1)):
                temp = palin(l, r)
                if len(temp) > len(ans):
                    ans = temp
        return ans