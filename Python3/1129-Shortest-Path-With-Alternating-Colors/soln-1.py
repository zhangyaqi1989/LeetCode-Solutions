class Solution:
    def shortestAlternatingPaths(self, n: int, red_edges: List[List[int]], blue_edges: List[List[int]]) -> List[int]:
        edges = [collections.defaultdict(set), collections.defaultdict(set)]
        for i, es in enumerate((red_edges, blue_edges)):
            for u, v in es:
                edges[i][u].add(v)
        costs = [math.inf] * n
        frontier = collections.deque([(0, 0), (0, 1)])
        visited = {(0, 0), (0, 1)}
        step = 0
        while frontier:
            sz = len(frontier)
            for _ in range(sz):
                node, color = frontier.popleft()
                costs[node] = min(costs[node], step)
                new_color = 1 - color
                for nei in edges[color][node]:
                    if (nei, new_color) not in visited:
                        visited.add((nei, new_color))
                        frontier.append((nei, new_color))
            step += 1
        return [(c if c != math.inf else -1) for c in costs]
