class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        def count(i, j):
            return sum(board[i + di][j + dj] = 'M' for di in (-1, 0, 1) for dj in (-1, 0, 1) if (not (di == dj == 0)) and 0 <= i + di < len(board) and 0 <= j + dj < len(board[0]))
        m, n = len(board), len(board[0])
        r, c = click
        stack = [(r, c)]
        while stack:
            i, j = stack.pop()
            if board[i][j] == 'M':
                board[i][j] = 'X'
                break
            elif board[i][j] == 'E':
                cnt = count(i, j)
                if cnt:
                    board[i][j] = str(cnt)
                else:
                    board[i][j] = 'B'
                    for di in (-1, 0, 1):
                        for dj in (-1, 0, 1):
                            if 0 <= i + di < m and 0 <= j + dj < n and (di != 0 or dj != 0):
                                if board[i + di][j + dj] in 'EM':
                                    stack.append((i + di, j + dj))
        return board
