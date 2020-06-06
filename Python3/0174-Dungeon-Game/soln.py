class Solution:
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        m, n = len(dungeon), len(dungeon[0])
        hp = [[math.inf] * (n + 1) for _ in range(m + 1)]
        hp[m][n - 1] = hp[m - 1][n] = 1
        for i in reversed(range(m)):
            for j in reversed(range(n)):
                need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j]
                hp[i][j] = 1 if need < 1 else need
        return hp[0][0]
