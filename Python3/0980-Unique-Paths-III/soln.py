class Solution:
    def uniquePathsIII(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # backtrack
        def helper(i, j, cur_step, steps):
            if 0 <= i < len(grid) and 0 <= j < len(grid[0]) and grid[i][j] != -1:
                if grid[i][j] == 2 and steps == cur_step:
                    self.ans += 1
                elif grid[i][j] == 0:
                    grid[i][j] = 1
                    helper(i - 1, j, cur_step + 1, steps)
                    helper(i + 1, j, cur_step + 1, steps)
                    helper(i, j - 1, cur_step + 1, steps)
                    helper(i, j + 1, cur_step + 1, steps)
                    grid[i][j] = 0
        steps = 1
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    r0, c0 = i, j
                elif val == 0:
                    steps += 1
        self.ans = 0
        grid[r0][c0] = 0
        helper(r0, c0, 0, steps)
        return self.ans
