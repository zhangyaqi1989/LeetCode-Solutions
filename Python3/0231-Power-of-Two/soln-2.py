class Solution:
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # n is integer
        if n <= 0:
            return False
        return n & (n - 1) == 0