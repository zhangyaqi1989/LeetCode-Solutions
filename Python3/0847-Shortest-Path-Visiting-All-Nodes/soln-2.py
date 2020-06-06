class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)
        target = (1 << n) - 1
        frontier = collections.deque([(i, 1 << i) for i in range(n)])
        step = 0
        seen = set()
        while frontier:
            sz = len(frontier)
            for _ in range(sz):
                node, state = frontier.popleft()
                if state == target:
                    return step
                for nei in graph[node]:
                    if (nei, (state | (1 << nei))) not in seen:
                        seen.add((nei, (state | (1 << nei))))
                        frontier.append((nei, (state | (1 << nei))))
            step += 1
