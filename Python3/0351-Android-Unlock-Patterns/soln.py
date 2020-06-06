class Solution:
    def numberOfPatterns(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        skip = [[0] * 10 for _ in range(10)]
        skip[1][3] = skip[3][1] = 2
        skip[1][7] = skip[7][1] = 4
        skip[3][9] = skip[9][3] = 6
        skip[7][9] = skip[9][7] = 8
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5
        visited = [False] * 10
        def dfs(i, left):
            if left == 0:
                return 1
            res = 0
            visited[i] = True
            for j in range(1, 10):
                if not visited[j] and (skip[i][j] == 0 or visited[skip[i][j]]):
                    res += dfs(j, left - 1)
            visited[i] = False
            return res
        res = 0
        for left in range(m, n + 1):
            res += dfs(1, left - 1) * 4
            res += dfs(2, left - 1) * 4
            res += dfs(5, left - 1)
        return res
