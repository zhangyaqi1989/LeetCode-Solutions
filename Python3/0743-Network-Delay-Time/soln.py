class Solution:
    def networkDelayTime(self, times, N, K):
        """
        :type times: List[List[int]]
        :type N: int
        :type K: int
        :rtype: int
        """
        network = collections.defaultdict(dict)
        for u, v, w in times:
            network[u][v] = w
        visit_time = {K : 0}
        queue = [(0, K)]
        while queue:
            time, node = heapq.heappop(queue)
            for nei, t in network[node].items():
                if nei not in visit_time or visit_time[nei] > time + t:
                    visit_time[nei] = time + t
                    heapq.heappush(queue, (time + t, nei))
        return max(visit_time.values()) if len(visit_time) == N else -1