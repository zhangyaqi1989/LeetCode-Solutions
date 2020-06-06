class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    i0, j0 = i, j
                    break
        cnt = 0
        for j in range(j0 + 1, 8):
            if board[i0][j] == 'B':
                break
            if board[i0][j] == 'p':
                cnt += 1
                break
        for j in reversed(range(j0)):
            if board[i0][j] == 'B':
                break
            if board[i0][j] == 'p':
                cnt += 1
                break
        for i in range(i0 + 1, 8):
            if board[i][j0] == 'B':
                break
            if board[i][j0] == 'p':
                cnt += 1
                break
        for i in reversed(range(i0)):
            if board[i][j0] == 'B':
                break
            if board[i][j0] == 'p':
                cnt += 1
                break
        return cnt
