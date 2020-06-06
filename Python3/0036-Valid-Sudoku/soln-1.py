class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        return self.row_valid(board) and self.col_valid(board) and self.sub_valid(board)
        
    def row_valid(self, board):
        return all(self.valid(row) for row in board)
    
    def col_valid(self, board):
        return all(self.valid(col) for col in zip(*board))
    
    def sub_valid(self, board):
        return all(self.valid(board[r + i][c + j] for i in range(3) for j in range(3)) for r in (0, 3, 6) for c in (0, 3, 6))  
        
    def valid(self, unit):
        unit = [x for x in unit if x != '.']
        return len(set(unit)) == len(unit)