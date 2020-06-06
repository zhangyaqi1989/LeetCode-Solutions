class Solution:
    def candyCrush(self, board: List[List[int]]) -> List[List[int]]:
        def process(board):
            crushes = set()
            m, n = len(board), len(board[0])
            for i in range(m):
                for j in range(n):
                    if j + 2 < n and board[i][j] == board[i][j + 1] == board[i][j + 2] != 0:
                        crushes.update({(i, j), (i, j + 1), (i, j + 2)})
                    if i + 2 < m and board[i][j] == board[i + 1][j] == board[i + 2][j] != 0:
                        crushes.update({(i, j), (i + 1, j), (i + 2, j)})
            for i, j in crushes:
                board[i][j] = 0
            for j in range(n):
                wi = m - 1
                for i in reversed(range(m)):
                    if board[i][j] != 0:
                        board[wi][j] = board[i][j]
                        wi -= 1
                for i in range(wi, -1, -1):
                    board[i][j] = 0
            return len(crushes) != 0
        while process(board):
            pass
        return board
