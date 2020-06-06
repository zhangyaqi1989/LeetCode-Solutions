class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        def valid(sub):
            nums = [item for item in sub if item.isdigit()]
            return len(set(nums)) == len(nums)
        
        def check_row():
            return all(valid(row) for row in board)
        
        def check_col():
            return all(valid(col) for col in zip(*board))
        
        def check_sub():
            return all(valid([board[r + dr][c + dc]
                        for dr in range(3) for dc in range(3)])
                        for r, c in itertools.product((0, 3, 6), repeat=2))
        return check_row() and check_col() and check_sub()