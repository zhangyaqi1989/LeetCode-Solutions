from functools import lru_cache

class Solution:
    def mostSimilar(self, n: int, roads: List[List[int]], names: List[str], targetPath: List[str]) -> List[int]:
        # find a path of the same length with mim
        graph = [[] for _ in range(n)]
        for u, v in roads:
            graph[u].append(v)
            graph[v].append(u)
        parents = collections.defaultdict(lambda : None)
        @lru_cache(None)
        def dp(idx, node):
            if idx == len(targetPath):
                return 0
            mn_cost = math.inf
            for nxt in graph[node]:
                temp = dp(idx + 1, nxt)
                if temp < mn_cost:
                    mn_cost = temp
                    parents[idx, node] = (idx + 1, nxt)
            mn_cost += (targetPath[idx] != names[node])
            return mn_cost
        mn = math.inf
        best_start = -1
        for start in range(n):
            temp = dp(0, start)
            if temp < mn:
                mn = temp
                best_start = start
        start = best_start
        path = []
        for i in range(len(targetPath)):
            path.append(start)
            _, start = parents[i, start]
        return path

