class Solution:
    def shortestPathLength(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        dst = (1 << len(graph)) - 1
        queue = collections.deque([(i, 1 << i) for i in range(len(graph))])
        memo = set([(i, 1 << i) for i in range(len(graph))])
        step = 0
        while queue:
            size = len(queue)
            for _ in range(size):
                node, state = queue.popleft()
                if state == dst:
                    return step
                for nei in graph[node]:
                    new_state = (state | (1 << nei))
                    if (nei, new_state) not in memo:
                        memo.add((nei, new_state))
                        queue.append((nei, new_state))
            step += 1