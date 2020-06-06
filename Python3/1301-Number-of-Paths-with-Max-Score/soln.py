class Record:
    def __init__(self, val, paths):
        self.val = val
        self.paths = paths

class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        n = len(board)
        dp = [[Record(-1, 0) for _ in range(n + 1)] for _ in range(n + 1)]
        dp[n - 1][n - 1] = Record(0, 1)
        MOD = 1000000007
        for i in reversed(range(n)):
            for j in reversed(range(n)):
                if board[i][j] in 'XS':
                    continue
                for ni, nj in (i + 1, j), (i, j + 1), (i + 1, j + 1):
                    if dp[ni][nj].val > dp[i][j].val:
                        dp[i][j].val = dp[ni][nj].val
                        dp[i][j].paths = dp[ni][nj].paths
                    elif dp[ni][nj].val == dp[i][j].val:
                        dp[i][j].paths = (dp[i][j].paths + dp[ni][nj].paths) % MOD
                if dp[i][j].val != -1:
                    dp[i][j].val += int(board[i][j]) if (i or j) else 0
        return [max(0, dp[0][0].val), dp[0][0].paths]
