class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], K: int) -> float:
        workers = sorted([(w/q, q) for q, w in zip(quality, wage)])
        pq = []
        qsum = 0
        ans = math.inf
        for ratio, q in workers:
            qsum += q
            heapq.heappush(pq, -q)
            if len(pq) > K:
                qsum += heapq.heappop(pq)
            if len(pq) == K:
                ans = min(ans, qsum * ratio)
        return ans
