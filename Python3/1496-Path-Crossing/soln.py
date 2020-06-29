class Solution:
    def isPathCrossing(self, path: str) -> bool:
        visited = {(0, 0)}
        r, c = 0, 0
        dirs = {'N' : (0, -1), 'S' : (0, 1), 'E' : (1, 0), 'W' : (-1, 0)}
        for op in path:
            dr, dc = dirs[op]
            r += dr
            c += dc
            if (r, c) in visited:
                return True
            visited.add((r, c))
        return False
