class Solution:
    def findDerangement(self, n):
        """
        :type n: int
        :rtype: int
        """
        # f(n) = (n - 1) * (f(n - 2) + f(n - 1))
        # f(1) = 0, f(2) = 1, f(3) = 2
        if n <= 2:
            return n - 1
        pre, cur = 0, 1
        mod = 10 ** 9 + 7
        for i in range(3, n + 1):
            pre, cur = cur, ((i - 1) * (cur + pre)) % mod
        return cur % mod
