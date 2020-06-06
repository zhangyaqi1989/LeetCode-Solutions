class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    i0, j0 = i, j
        cnt = 0
        for di, dj in (-1, 0), (1, 0), (0, 1), (0, -1):
            i, j = i0 + di, j0 + dj
            while 0 <= i < 8 and 0 <= j < 8:
                if board[i][j] == 'p':
                    cnt += 1
                    break
                elif board[i][j] == 'B':
                    break
                i += di
                j += dj
        return cnt
