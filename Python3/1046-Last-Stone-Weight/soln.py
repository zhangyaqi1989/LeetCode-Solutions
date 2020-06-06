class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        pq = [-x for x in stones]
        heapq.heapify(pq)
        while len(pq) >= 2:
            x = -heapq.heappop(pq)
            y = -heapq.heappop(pq)
            if x != y:
                z = max(x, y) - min(x, y)
                heapq.heappush(pq, -z)
        return -pq[0] if pq else 0
        
