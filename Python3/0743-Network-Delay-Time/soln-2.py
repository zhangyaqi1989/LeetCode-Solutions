class Solution:
    def networkDelayTime(self, times, N, K):
        """
        :type times: List[List[int]]
        :type N: int
        :type K: int
        :rtype: int
        """
        graph = collections.defaultdict(dict)
        for u, v, w in times:
            graph[u][v] = w
        queue = [(0, K)]
        delays = [0] + [math.inf] * (N)
        delays[K] = 0
        while queue:
            cost, u = heapq.heappop(queue)
            for v, w in graph[u].items():
                if delays[v] > cost + w:
                    delays[v] = delays[u] + w
                    heapq.heappush(queue, (delays[u] + w, v))
        mx = max(delays)
        return mx if mx != math.inf else -1
