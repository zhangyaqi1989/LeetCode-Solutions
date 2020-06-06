class Solution:
    def numEnclaves(self, A: List[List[int]]) -> int:
        m, n = len(A), len(A[0])
        stack = []
        for i, row in enumerate(A):
            for j, val in enumerate(row):
                if val == 1 and (i == 0 or i == m - 1 or j == 0 or j == n - 1):
                    stack.append((i, j))
                    A[i][j] = 0
        while stack:
            i, j = stack.pop()
            for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if 0 <= newi < m and 0 <= newj < n and A[newi][newj] == 1:
                    A[newi][newj] = 0
                    stack.append((newi, newj))
        ans = 0
        for i, row in enumerate(A):
            for j, val in enumerate(row):
                ans += val == 1
        return ans
