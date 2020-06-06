class Solution:
    def reachableNodes(self, edges: List[List[int]], M: int, N: int) -> int:
        graph = collections.defaultdict(dict)
        for i, j, n in edges:
            graph[i][j] = n
            graph[j][i] = n
        pq = [(0, 0)]
        dist = [math.inf] * N
        dist[0] = 0
        while pq:
            cost, node = heapq.heappop(pq)
            for nei, d in graph[node].items():
                d += 1
                if dist[nei] > cost + d and cost + d <= M:
                    dist[nei] = cost + d
                    heapq.heappush(pq, (dist[nei], nei))
        ans = sum(d <= M for d in dist)
        for i, j, n in edges:
            a = 0 if dist[i] == math.inf else M - dist[i]
            b = 0 if dist[j] == math.inf else M - dist[j]
            ans += min(a + b, n)
        return ans
