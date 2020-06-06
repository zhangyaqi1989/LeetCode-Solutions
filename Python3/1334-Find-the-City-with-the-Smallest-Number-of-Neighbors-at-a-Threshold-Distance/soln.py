class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], t: int) -> int:
        graph = collections.defaultdict(dict)
        for u, v, w in edges:
            graph[u][v] = w
            graph[v][u] = w
        def dijkstra(start, threshold):
            frontier = [(0, start)]
            costs = {start : 0}
            processed = [False] * n
            while frontier:
                cost, u = heapq.heappop(frontier)
                if processed[u]:
                    continue
                processed[u] = True
                for v, w in graph[u].items():
                    if w + cost <= threshold and (v not in costs or costs[v] > w + cost):
                        costs[v] = w + cost
                        heapq.heappush(frontier, (w + cost, v))
            return len(costs)
        neighbors = [dijkstra(i, t) for i in range(n)]
        # print(neighbors)
        return min(range(n), key=lambda i : (neighbors[i], -i))
