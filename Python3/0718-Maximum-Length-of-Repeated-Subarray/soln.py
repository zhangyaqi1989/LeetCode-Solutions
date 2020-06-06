class Solution:
    def findLength(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        nA, nB = len(A), len(B)
        dp = [[0] * (nB + 1) for _ in range(nA + 1)]
        for i in range(1, nA + 1):
            for j in range(1, nB + 1):
                if A[i - 1] == B[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
        return max(max(row) for row in dp)
