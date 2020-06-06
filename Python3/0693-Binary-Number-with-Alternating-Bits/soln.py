class Solution(object):
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        s = bin(n)[2:]
        return all(s[i] != s[i + 1] for i in range(len(s) - 1))