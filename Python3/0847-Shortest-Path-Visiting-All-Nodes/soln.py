class Solution:
    def shortestPathLength(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        # each state is a node in the search graph
        seen = set()
        final = (1 << len(graph)) - 1
        queue = collections.deque([(i, 0, 1 << i) for i in range(len(graph))])
        steps = 0
        while queue:
            node, steps, state = queue.popleft()
            if state == final: return steps
            for v in graph[node]:
                if (state | 1 << v, v) not in seen:
                    queue.append((v, steps + 1, state | 1 << v))
                    seen.add((state | 1 << v, v))
