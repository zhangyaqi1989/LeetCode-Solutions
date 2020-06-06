class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        # shortest path visiting all nodes
        # using BFS
        n = len(graph)
        target = (1 << n) - 1
        frontier = [(1 << i, i) for i in range(n)]
        levels = {node : 0 for node in frontier}
        step = 0
        while frontier:
            nxt_level = []
            for state, node in frontier:
                if state == target:
                    return levels[state, node]
                for nei in graph[node]:
                    new_state = state | (1 << nei)
                    if (new_state, nei) not in levels:
                        levels[(new_state, nei)] = step + 1
                        nxt_level.append((new_state, nei))
            frontier = nxt_level
            step += 1
        return -1
