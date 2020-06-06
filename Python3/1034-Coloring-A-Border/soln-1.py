class Solution:
    def colorBorder(self, grid: List[List[int]], r0: int, c0: int, color: int) -> List[List[int]]:
        if grid[r0][c0] == color:
            return grid
        def neighbor4(i, j):
            for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if 0 <= newi < len(grid) and 0 <= newj < len(grid[0]):
                    yield newi, newj
        component = {(r0, c0)}
        frontier = [(r0, c0)]
        oldc = grid[r0][c0]
        grid[r0][c0] = color
        
        while frontier:
            r, c = frontier.pop()
            for newr, newc in neighbor4(r, c):
                if grid[newr][newc] == oldc and (newr, newc) not in component:
                    component.add((newr, newc))
                    grid[newr][newc] = color
                    frontier.append((newr, newc))
        inside = []
        for r, c in component:
            ns = list(neighbor4(r, c))
            if len(ns) == 4 and all((nr, nc) in component for nr, nc in ns):
                inside.append((r, c))
        for r, c in inside:
            grid[r][c] = oldc
        return grid
