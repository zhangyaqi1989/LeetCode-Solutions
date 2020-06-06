class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        return self.rowValid(board) and self.colValid(board) and self.subValid(board)
        
    def rowValid(self, board):
        return all(self.isUnitValid(row) for row in board)
    
    def colValid(self, board):
        return all(self.isUnitValid(col) for col in zip(*board))
    
    def subValid(self, board):
        return all(self.isUnitValid([board[r+i][c+j] for i in range(3) for j in range(3)]) for r in (0, 3, 6) for c in (0, 3, 6))
        
    def isUnitValid(self, unit):
        digits = [digit for digit in unit if digit != '.']
        # print(digits)
        return len(set(digits)) == len(digits)