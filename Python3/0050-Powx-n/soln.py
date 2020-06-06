class Solution:
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n < 0:
            return 1. / self.helper(x, -n)
        return self.helper(x, n)
        
    def helper(self, x, n):
        if n == 0:
            return 1
        half = self.helper(x, n//2)
        return half * half * x if n & 1 else half * half