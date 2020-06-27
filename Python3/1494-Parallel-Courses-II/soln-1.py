class Solution:
    def minNumberOfSemesters(self, n: int, dependencies: List[List[int]], k: int) -> int:
        def compute_depth(u):
            if depths[u] == -1:
                depths[u] = 0
            for v in graph[u]:
                depths[u] = max(depths[u], 1 + compute_depth(v))
            return depths[u]
        graph = [[] for _ in range(n)]
        indegrees = [0] * n
        for u, v in dependencies:
            u -= 1
            v -= 1
            graph[u].append(v)
            indegrees[v] += 1
        depths = [-1] * n
        for u in range(n):
            depths[u] = compute_depth(u)
        frees = [(-depths[u], u) for u in range(n) if not indegrees[u]]
        heapq.heapify(frees)
        ans = 0
        while frees:
            ans += 1
            ntakes = min(len(frees), k)
            nxts = []
            for _ in range(ntakes):
                _, u = heapq.heappop(frees)
                for v in graph[u]:
                    indegrees[v] -= 1
                    if indegrees[v] == 0:
                        nxts.append((-depths[v], v))
            for item in nxts:
                heapq.heappush(frees, item)
        return ans
