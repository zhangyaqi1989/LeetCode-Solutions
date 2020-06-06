# follow up: get all the paths
class Solution:
    def uniquePathsIII(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # backtrack
        def helper(i, j, cur_step, steps, path, ans):
            if 0 <= i < len(grid) and 0 <= j < len(grid[0]) and grid[i][j] != -1:
                if grid[i][j] == 2 and steps == cur_step:
                    ans.append(path + [(i, j)])
                elif grid[i][j] == 0:
                    grid[i][j] = 1
                    path.append((i, j))
                    helper(i - 1, j, cur_step + 1, steps, path, ans)
                    helper(i + 1, j, cur_step + 1, steps, path, ans)
                    helper(i, j - 1, cur_step + 1, steps, path, ans)
                    helper(i, j + 1, cur_step + 1, steps, path, ans)
                    path.pop()
                    grid[i][j] = 0
        steps = 1
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    r0, c0 = i, j
                elif val == 0:
                    steps += 1
        grid[r0][c0] = 0
        ans = []
        helper(r0, c0, 0, steps, [], ans)
        return ans

soln = Solution()
A = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
print(soln.uniquePathsIII(A))
