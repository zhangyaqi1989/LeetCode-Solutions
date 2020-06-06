class Solution:
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        def lefts(row, col):
            # return posssible numbers that could be put on (row, col) of board
            r, c = row - row % 3, col - col % 3
            return list(set(map(str, range(1, 10))) - ({ch for ch in board[row] if ch != '.'} | {board[i][col] for i in range(len(board)) if board[i][col] != '.'} | {board[r + i][c + j] for i in range(3) for j in range(3) if board[r + i][c + j] != '.'}))
        def solve():
            for i in range(len(board)):
                for j in range(len(board[0])):
                    if board[i][j] == '.':
                        for ch in lefts(i, j):
                            board[i][j] = ch
                            if solve():
                                return True
                            else:
                                board[i][j] = '.'
                        return False
            return True
        solve()