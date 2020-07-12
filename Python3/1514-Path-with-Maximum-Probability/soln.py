class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        # shortest path
        graph = [[] for _ in range(n)]
        for (u, v), p in zip(edges, succProb):
            graph[u].append((v, p))
            graph[v].append((u, p))
        probs = [0] * n
        probs[start] = 1
        frontier = [(-1, start)]
        processed = [False] * n
        while frontier:
            prob, u = heapq.heappop(frontier)
            prob = -prob
            if u == end:
                return prob
            if processed[u]:
                continue
            processed[u] = True
            for v, w in graph[u]:
                new_prob = prob * w
                if probs[v] < new_prob:
                    probs[v] = new_prob
                    heapq.heappush(frontier, (-new_prob, v))
        return probs[end]
