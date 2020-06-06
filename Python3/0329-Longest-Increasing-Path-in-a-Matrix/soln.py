class Solution:
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        # use dfs check every point
        if not any(matrix):
            return 0
        m, n = len(matrix), len(matrix[0])
        def dfs(i, j):
            if not dp[i][j]:
                dp[i][j] = 1 + max(
                    dfs(i - 1, j) if i > 0 and matrix[i][j] < matrix[i - 1][j] else 0,
                    dfs(i + 1, j) if i < m - 1 and matrix[i][j] < matrix[i + 1][j] else 0,
                    dfs(i, j - 1) if j > 0 and matrix[i][j] < matrix[i][j - 1] else 0,
                    dfs(i, j + 1) if j < n - 1 and matrix[i][j] < matrix[i][j + 1] else 0,
                )
            return dp[i][j]
        dp = [[0] * n for _ in range(m)]
        return max(dfs(i, j) for i in range(m) for j in range(n))