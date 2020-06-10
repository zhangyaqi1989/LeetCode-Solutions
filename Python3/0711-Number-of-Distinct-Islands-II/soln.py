class Solution:
    def numDistinctIslands2(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def dfs(start):
            "Do DFS from start = (r, c), return the coordinates of island."
            stack = [start]
            island = {start}
            m, n = len(grid), len(grid[0])
            while stack:
                i, j = stack.pop()
                for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                    if 0 <= newi < m and 0 <= newj < n and grid[newi][newj] == 1 :
                        grid[newi][newj] = 0
                        island.add((newi, newj))
                        stack.append((newi, newj))
            return island
        
        def canonical(shape):
            "Compute the canonical form of the island."
            def translate(shape):
                w = complex(min(z.real for z in shape),
                            min(z.imag for z in shape))
                return sorted(str(z - w) for z in shape)
            shape = [complex(x, y) for x, y in shape]
            ans = min([translate([z * (1j) ** k for z in shape]) 
                       for k in range(4)])
            ans = min(ans, *[translate([complex(z.imag, z.real) * (1j) ** k
                                       for z in shape])
                           for k in range(4)])
            return tuple(ans)
        shapes = set()
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    shape = dfs((i, j))
                    shapes.add(canonical(shape))
        return len(shapes)
