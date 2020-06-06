class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        def helper(l, r):
            "Compute longest palindrome substring centered at index (l, r)."
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            return s[l + 1:r]
        return max((helper(l, r)
                     for i in range(len(s))
                     for l, r in ((i, i), (i, i + 1))
                   ), key=len) if s else ""