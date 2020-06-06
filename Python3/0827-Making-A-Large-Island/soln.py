class Solution:
    def largestIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def neighbor4(i, j):
            "Return valid 4 directional neighbors."
            m, n = len(grid), len(grid[0])
            for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if 0 <= newi < m and 0 <= newj < n:
                    yield newi, newj
        
        def dfs(r, c, ID):
            "Conduct dfs from (r, c), identify the island with ID and return area."
            area = 0
            grid[r][c] = ID
            stack = [(r, c)]
            while stack:
                i, j = stack.pop()
                area += 1
                for newi, newj in neighbor4(i, j):
                    if grid[newi][newj] == 1:
                        grid[newi][newj] = ID
                        stack.append((newi, newj))
            return area
        
        # 1. compute areas of each island
        areas = collections.Counter() # map ID to area
        ID_gen = itertools.count(2)
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    ID = next(ID_gen)
                    areas[ID] = dfs(i, j, ID)
                    
        # 2. loop over each 0 position and compute and maximum area
        mx_area = max(areas.values()) if areas else 0
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 0:
                    IDs = {grid[newi][newj] for newi, newj in neighbor4(i, j)}
                    area = sum(areas[ID] for ID in IDs) + 1
                    mx_area = max(mx_area, area)
        return mx_area
