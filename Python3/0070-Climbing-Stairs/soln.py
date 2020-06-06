class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Fib
        if n <= 2:
            return n
        first, second = 1, 2
        for _ in range(n - 2):
            first, second = second, first + second
        return second