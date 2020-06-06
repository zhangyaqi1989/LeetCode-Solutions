class Solution:
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        return sum(val == 'X' for i, row in enumerate(board) for j, val in enumerate(row) if (j == 0 or board[i][j - 1] == '.') and (i == 0 or board[i - 1][j] == '.'))