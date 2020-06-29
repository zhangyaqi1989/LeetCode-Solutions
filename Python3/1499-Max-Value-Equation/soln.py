class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        # maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k
        # yi + yj + xi - xj
        # stand at x
        # maximum of yj - xj
        n = len(points)
        evicted = [False] * n
        lo = 0
        pq = []
        ans = -math.inf
        for i, (x, y) in enumerate(points):
            while x - points[lo][0] > k:
                evicted[lo] = True
                lo += 1
            while pq and evicted[pq[0][1]]:
                heapq.heappop(pq)
            if pq:
                cur = x + y - pq[0][0]
                ans = max(ans, cur)
            heapq.heappush(pq, (-(y - x), i))
        return ans
