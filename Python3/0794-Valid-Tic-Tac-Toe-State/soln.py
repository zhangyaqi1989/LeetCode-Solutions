class Solution:
    def validTicTacToe(self, board):
        """
        :type board: List[str]
        :rtype: bool
        """
        board = '|'.join(board)
        x, o = (any(p * 3 in board[s::d] for s in range(9) for d in (1, 3, 4, 5)) for p in 'XO')
        m = board.count('X') - board.count('O')
        return (m == 0 and not x) or (m == 1 and not o)