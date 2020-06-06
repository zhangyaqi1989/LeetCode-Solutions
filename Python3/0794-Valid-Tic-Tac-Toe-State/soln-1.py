class Solution:
    def validTicTacToe(self, board: List[str]) -> bool:
        # "X" first
        # number of "X" >= "O"
        game = collections.defaultdict(collections.Counter)
        xs, os = 0, 0
        for i, row in enumerate(board):
            for j, val in enumerate(row):
                if val in "XO":
                    if val == 'X':
                        player = 0
                        xs += 1
                    else:
                        player = 1
                        os += 1
                    game[player][0, i] += 1
                    game[player][1, j] += 1
                    game[player][2, i + j] += 1
                    game[player][3, i - j] += 1
        xwin = 3 in game[0].values()
        owin = 3 in game[1].values()
        if xwin or owin:
            if xwin:
                return xs == os + 1 and not owin
            else:
                return xs == os
        else:
            return xs == os or os + 1 == xs
