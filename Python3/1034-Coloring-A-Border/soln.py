class Solution:
    def colorBorder(self, grid: List[List[int]], r0: int, c0: int, color: int) -> int:
        old_color = grid[r0][c0]
        if color == old_color:
            return grid
        m, n = len(grid), len(grid[0])
        stack = [(r0, c0)]
        grid[r0][c0] = color
        colored = set()
        while stack:
            i, j = stack.pop()
            colored.add((i, j))
            for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if 0 <= newi < m and 0 <= newj < n and grid[newi][newj] == old_color:
                    grid[newi][newj] = color
                    stack.append((newi, newj))
        inner = []
        for i, j in colored:
            if all(0 <= newi < m and 0 <= newj < n and (newi, newj) in colored for newi, newj in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]):
                inner.append((i, j))
        for i, j in inner:
            grid[i][j] = old_color
        return grid
