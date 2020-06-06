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
        queue = collections.deque([K])
        delays = [0] + [math.inf] * (N)
        delays[K] = 0
        while queue:
            u = queue.popleft()
            for v, w in graph[u].items():
                if delays[v] > delays[u] + w:
                    delays[v] = delays[u] + w
                    queue.append(v)
        mx = max(delays)
        return mx if mx != math.inf else -1
