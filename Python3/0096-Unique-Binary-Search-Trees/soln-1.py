class Solution:
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        # n = 0: 1
        # n = 1: 1
        # n = 2: 2
        # n = 3: 5, f(0) * f(2) + f(1) * f(2 - 1) + f(2) * f(0)
        # f(n) =
        # use bottom up
        fs = [1, 1, 2] + [0] * (n - 2)
        for i in range(3, n + 1):
            fs[i] = sum(fs[j] * fs[i - 1 - j] for j in range(0, i))
        return fs[n]