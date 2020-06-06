class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        cnt = 0
        n = len(grid[0])
        for row in grid:
            lo, hi = 0, n
            while lo < hi:
                mid = (lo + hi) >> 1
                if row[mid] >= 0:
                    lo = mid + 1
                else:
                    hi = mid
            cnt += n - lo
        return cnt
