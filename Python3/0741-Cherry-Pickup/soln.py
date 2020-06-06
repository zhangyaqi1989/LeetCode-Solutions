class Solution:
    def cherryPickup(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # 0: empty; 1 : cherry; -1 thorn;
        memo = {}
        def helper(i1, j1, i2, j2):
            if (i1, j1, i2, j2) in memo:
                return memo[i1, j1, i2, j2]
            if i1 == len(grid) or j1 == len(grid) or i2 == len(grid) or j2 == len(grid):
                return -1
            if grid[i1][j1] == -1 or grid[i2][j2] == -1:
                return -1
            if i1 == i2 == j1 == j2 == len(grid) - 1:
                return grid[-1][-1]
            n1 = helper(i1 + 1, j1, i2 + 1, j2)
            n2 = helper(i1 + 1, j1, i2, j2 + 1)
            n3 = helper(i1, j1 + 1, i2 + 1, j2)
            n4 = helper(i1, j1 + 1, i2, j2 + 1)
            ans = max(n1, n2, n3, n4)
            if ans != -1:
                if i1 == i2 and j1 == j2:
                    ans += grid[i1][j1]
                else:
                    ans += grid[i1][j1] + grid[i2][j2]
            memo[i1, j1, i2, j2] = ans
            return ans
        ans = helper(0, 0, 0, 0)
        return max(0, ans)
