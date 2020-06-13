class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        h, w = len(grid), len(grid[0])
        hw = h * w
        k %= hw
        ans = [[0] * w for _ in range(h)]
        for i in range(h):
            for j in range(w):
                idx = (i * w + j + k) % hw
                ni, nj = idx // w, idx % w
                ans[ni][nj] = grid[i][j]
        return ans
