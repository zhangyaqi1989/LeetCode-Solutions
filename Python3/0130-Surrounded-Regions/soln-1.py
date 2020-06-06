class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not any(board): return
        m, n = len(board), len(board[0])
        for i, row in enumerate(board):
            for j, val in enumerate(row):
                if val == 'O' and (i == 0 or j == 0 or i == m - 1 or j == n - 1):
                    self.dfs(board, i, j)
        for i, row in enumerate(board):
            for j, val in enumerate(row):
                if val == 'F':
                    board[i][j] = 'O'
                elif val == 'O':
                    board[i][j] = 'X'
        
    def dfs(self, board, i, j):
        if 0 <= i < len(board) and 0 <= j < len(board[0]) and board[i][j] == 'O':
            board[i][j] = 'F'
            for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                self.dfs(board, newi, newj)
