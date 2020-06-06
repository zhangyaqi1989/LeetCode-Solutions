class Solution:
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        # get maximum 
        if n == 2: return 1
        if n == 3: return 2
        prod = 1
        while n > 4:
            prod *= 3
            n -= 3
        return prod * n