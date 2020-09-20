class Solution:
    def isPrintable(self, grid: List[List[int]]) -> bool:
        limits = [[] for _ in range(61)]
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if not limits[val]:
                    limits[val] = [i, i, j, j]
                else:
                    limits[val][0] = min(limits[val][0], i)
                    limits[val][1] = max(limits[val][1], i)
                    limits[val][2] = min(limits[val][2], j)
                    limits[val][3] = max(limits[val][3], j)
        cands = []
        for val, limit in enumerate(limits):
            if limit:
                (mn_x, mx_x, mn_y, mx_y) = limit
                cands.append(((mx_x - mn_x + 1) * (mx_y - mn_y + 1), val))
        cands.sort()
        removed = [False] * 61
        nremoves = 0
        while nremoves < len(cands):
            for cnt, val in cands:
                if removed[val]:
                    continue
                mn_x, mx_x, mn_y, mx_y = limits[val]
                if all(grid[i][j] == val or removed[grid[i][j]] for i in range(mn_x, mx_x + 1) for j in range(mn_y, mx_y + 1)):
                    removed[val] = True
                    nremoves += 1
                    break
            else:
                return False
        return True
