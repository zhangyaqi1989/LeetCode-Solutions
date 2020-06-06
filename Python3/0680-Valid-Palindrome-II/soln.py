class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        lo, hi = 0, len(s) - 1
        while lo < hi:
            if s[lo] != s[hi]:
                cand1, cand2 = s[lo:hi], s[lo + 1:hi + 1]
                return cand1 == cand1[::-1] or cand2 == cand2[::-1]
            lo, hi = lo + 1, hi - 1
        return True
