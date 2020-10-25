class Solution:
    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
        best = 0
        best_x, best_y = -1, -1
        for x0 in range(51):
            for y0 in range(51):
                temp = 0
                for x, y, q in towers:
                    d = math.hypot(x0 - x, y0 - y)
                    if d <= radius:
                        temp += int(q / (1 + d))
                if temp > best:
                    best = temp
                    best_x, best_y = x0, y0
        return best_x, best_y
