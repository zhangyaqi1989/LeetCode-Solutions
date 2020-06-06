class Leaderboard:

    def __init__(self):
        self._board = collections.Counter()

    def addScore(self, playerId: int, score: int) -> None:
        self._board[playerId] += score

    def top(self, K: int) -> int:
        return sum(cnt for _, cnt in self._board.most_common(K))

    def reset(self, playerId: int) -> None:
        self._board[playerId] = 0


# Your Leaderboard object will be instantiated and called as such:
# obj = Leaderboard()
# obj.addScore(playerId,score)
# param_2 = obj.top(K)
# obj.reset(playerId)
