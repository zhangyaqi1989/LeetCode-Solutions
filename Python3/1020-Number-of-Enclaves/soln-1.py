class Solution:
    def numEnclaves(self, A: List[List[int]]) -> int:
        def dfs(r, c):
            if 0 <= r < len(A) and 0 <= c < len(A[0]) and A[r][c] == 1:
                A[r][c] = 0
                for newr, newc in (r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1):
                    dfs(newr, newc)
        m, n = len(A), len(A[0])
        for j in range(n):
            dfs(0, j)
            dfs(m - 1, j)
        for i in range(m):
            dfs(i, 0)
            dfs(i, n - 1)
        return sum(val == 1 for row in A for val in row)
