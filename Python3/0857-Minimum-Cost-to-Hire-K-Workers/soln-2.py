class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], K: int) -> float:
        pairs = [(w/q, q) for q, w in zip(quality, wage)]
        sum_q = 0
        group = []
        mn = math.inf
        for ratio, q in sorted(pairs):
            heapq.heappush(group, (-q, ratio))
            sum_q += q
            if len(group) > K:
                val, _ = heapq.heappop(group)
                sum_q += val
            if len(group) == K:
                mn = min(mn, ratio * sum_q)
        return mn
