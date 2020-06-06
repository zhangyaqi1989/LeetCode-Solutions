class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        # keep health > 0
        m, n = len(dungeon), len(dungeon[0])
        dp = [[math.inf] * n for _ in range(m)]
        if dungeon[-1][-1] < 0:
            dp[-1][-1] = 1 - dungeon[-1][-1]
        else:
            dp[-1][-1] = 1
        for i in range(m - 2, -1, -1):
            dp[i][-1] = max(dp[i + 1][-1] - dungeon[i][-1], 1)
        for j in range(n - 2, -1, -1):
            dp[-1][j] = max(dp[-1][j + 1] - dungeon[-1][j], 1)
        for i in range(m - 2, -1, -1):
            for j in range(n - 2, -1 , -1):
                dp[i][j] = min(max(dp[i + 1][j] - dungeon[i][j], 1), max(dp[i][j + 1] - dungeon[i][j], 1))
        return dp[0][0]
