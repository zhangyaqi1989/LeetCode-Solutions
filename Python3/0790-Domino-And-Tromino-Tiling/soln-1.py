class Solution:
    def numTilings(self, N):
        """
        :type N: int
        :rtype: int
        """
        a, b, c = 0, 1, 1
        for _ in range(N - 1):
            a, b, c = b, c, (c + c + a) % (1000_000_000 + 7)
        return c
