class Solution:
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        def helper(x, n):
            if n == 0: return 1
            half = helper(x, n // 2)
            return half * half if n % 2 == 0 else half * half * x
        return helper(x, n) if n >= 0 else 1. / helper(x, -n)