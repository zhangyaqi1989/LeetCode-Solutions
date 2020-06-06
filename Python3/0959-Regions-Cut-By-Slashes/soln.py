class Solution:
    def regionsBySlashes(self, grid):
        """
        :type grid: List[str]
        :rtype: int
        """
        n = len(grid)
        N = 3 * n
        board = [[0] * N for _ in range(N)]
        for i in range(n):
            for j in range(n):
                if grid[i][j] == '/':
                    i3, j3 = i * 3, j * 3
                    board[i3][j3 + 2] = board[i3 + 1][j3 + 1] = board[i3 + 2][j3] = 1
                elif grid[i][j] == '\\':
                    i3, j3 = i * 3, j * 3
                    board[i3][j3] = board[i3 + 1][j3 + 1] = board[i3 + 2][j3 + 2] = 1
        def dfs(r, c):
            if 0 <= r < N and 0 <= c < N and board[r][c] == 0:
                board[r][c] = 1
                dfs(r - 1, c)
                dfs(r + 1, c)
                dfs(r, c - 1)
                dfs(r, c + 1)
        cnt = 0
        for i in range(N):
            for j in range(N):
                if board[i][j] == 0:
                    dfs(i, j)
                    cnt += 1
        return cnt
