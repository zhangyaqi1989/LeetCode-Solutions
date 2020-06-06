class Solution:
    def minFallingPathSum(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        n = len(A)
        dp = A[0]
        for i in range(1, n):
            temp = dp[:]
            for j in range(n):
                dp[j] = A[i][j] + min([temp[j + dj] for dj in (-1, 0, 1) if 0 <= j + dj < n])
        return min(dp)