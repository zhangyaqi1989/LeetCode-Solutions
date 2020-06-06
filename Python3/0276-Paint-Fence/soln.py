class Solution:
    def numWays(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        if n == 0: return 0
        if k == 1 and n <= 2: return 1
        same, dif = 0, k
        for _ in range(1, n):
            same, dif = dif, (same + dif) * (k - 1)
        return dif + same