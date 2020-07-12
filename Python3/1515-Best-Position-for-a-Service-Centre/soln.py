class Solution:
    def getMinDistSum(self, positions: List[List[int]]) -> float:
        def compute_sum(x, y):
            return sum(math.hypot(x - px, y - py) for px, py in positions)
        step, EPS = 100.0, 1e-6
        x, y = 50, 50
        best = compute_sum(x, y)
        while step > EPS:
            for dx, dy in (0, -1), (0, 1), (1, 0), (-1, 0):
                nx, ny = x + dx * step, y + dy * step
                cur = compute_sum(nx, ny)
                if cur < best:
                    best = cur
                    x, y = nx, ny
                    break
            else:
                step /= 2.0
        return best
