class Solution:
    def minSteps(self, n):
        """
        :type n: int
        :rtype: int
        """
        # A --> n * A with Copy and Paste
        # largest factor < n
        if n == 1:
            return 0
        else:
            factor = n - 1
            while n % factor != 0:
                factor -= 1
            return self.minSteps(factor) + n // factor