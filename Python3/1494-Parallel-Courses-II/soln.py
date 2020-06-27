# This solution may be wrong
class Solution:
    def minNumberOfSemesters(self, n: int, dependencies: List[List[int]], k: int) -> int:
        graph = [[] for _ in range(n)]
        memo_indegrees = [0] * n
        for u, v in dependencies:
            u -= 1
            v -= 1
            memo_indegrees[v] += 1
            graph[u].append(v)
        levels = []
        indegrees = memo_indegrees[:]
        frees = {i for i in range(n) if not indegrees[i]}
        node_levels = {}
        level = 0
        while frees:
            nxt_level = set()
            levels.append(frees)
            for u in frees:
                node_levels[u] = level
                for v in graph[u]:
                    indegrees[v] -= 1
                    if indegrees[v] == 0:
                        nxt_level.add(v)
            frees = nxt_level
            level += 1
        levels.append(set())
        # print(levels)
        # print(node_levels)
        frees = [(0, -sum(v in levels[1] for v in graph[i]), i) for i in levels[0]]
        heapq.heapify(frees)
        ans = 0
        indegrees = memo_indegrees[:]
        while frees:
            ans += 1
            ntake = min(len(frees), k)
            for _ in range(ntake):
                level, _, u = heapq.heappop(frees)
                for v in graph[u]:
                    indegrees[v] -= 1
                    if indegrees[v] == 0:
                        level = node_levels[v]
                        heapq.heappush(frees, (level, -sum(vv in levels[level + 1] for vv in graph[v]), v))
        return ans
