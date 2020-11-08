class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        # The maximum cost seen
        H, W = len(heights), len(heights[0])
        costs = [[math.inf] * W for _ in range(H)]
        costs[0][0] = 0
        pq = [(0, 0, 0)]
        while pq:
            cost, r, c = heapq.heappop(pq)
            if r == H - 1 and c == W - 1:
                return cost
            for dr, dc in (0, 1), (0, -1), (1, 0), (-1, 0):
                newr, newc = r + dr, c + dc
                if 0 <= newr < H and 0 <= newc < W:
                    new_cost = max(cost, abs(heights[newr][newc] - heights[r][c]))
                    if new_cost < costs[newr][newc]:
                        costs[newr][newc] = new_cost
                        heapq.heappush(pq, (new_cost, newr, newc))
        return -1
