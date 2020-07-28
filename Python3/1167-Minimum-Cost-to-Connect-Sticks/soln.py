class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        pool = sticks[:]
        heapq.heapify(pool)
        ans = 0
        while len(pool) > 1:
            x, y = heapq.heappop(pool), heapq.heappop(pool)
            ans += x + y
            heapq.heappush(pool, x + y)
        return ans
