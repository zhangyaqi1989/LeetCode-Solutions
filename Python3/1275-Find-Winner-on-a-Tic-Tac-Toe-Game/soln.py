class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        board = [collections.Counter() for _ in range(2)]
        for i, (r, c) in enumerate(moves):
            player = i % 2
            board[player][0, r] += 1
            board[player][1, c] += 1
            board[player][2, r + c] += 1
            board[player][3, r - c] += 1
            if 3 in board[player].values():
                return "A" if player == 0 else "B"
        return "Draw" if len(moves) == 9 else "Pending"
