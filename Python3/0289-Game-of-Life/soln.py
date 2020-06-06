class Solution:
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        # live (1), dead (0)
        # 1. less than two live neighbors dies
        # 2. with two or three, coninue
        # 3. more than three, dies
        # 4. any die with eact three lives
        # better to solve it in-place
        m, n = len(board), len(board[0])
        for i, row in enumerate(board):
            for j, val in enumerate(row):
                count = sum(board[i + di][j + dj] >= 1 for di in (-1, 0, 1) for dj in (-1, 0, 1) if (di != 0 or dj != 0) and 0 <= i + di < m and 0 <= j + dj < n)
                if val == 0:
                    if count == 3:
                        board[i][j] = -2
                else:
                    if count < 2 or count > 3: # go die
                        board[i][j] = 2
                    else:
                        board[i][j] = 1
        for i, row in enumerate(board):
            for j, val in enumerate(row):
                if val == -2:
                    board[i][j] = 1
                elif val == 2:
                    board[i][j] = 0