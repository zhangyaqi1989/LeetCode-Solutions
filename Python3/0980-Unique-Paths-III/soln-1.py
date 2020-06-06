class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        start = target = None
        cnt = 0
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    start = (i, j)
                elif val == 2:
                    target = (i, j)
                elif val == 0:
                    cnt += 1
        def dfs(path, i, j, cnt):
            if 0 <= i < len(grid) and 0 <= j < len(grid[0]) and grid[i][j] != -1 and (i, j) not in path:
                if (i, j) == target and len(path) == cnt + 1:
                    self.ans += 1
                else:
                    path.add((i, j))
                    dfs(path, i - 1, j, cnt)
                    dfs(path, i + 1, j, cnt)
                    dfs(path, i, j - 1, cnt)
                    dfs(path, i, j + 1, cnt)
                    path.remove((i, j))
        self.ans = 0
        dfs(set(), start[0], start[1], cnt)
        return self.ans
