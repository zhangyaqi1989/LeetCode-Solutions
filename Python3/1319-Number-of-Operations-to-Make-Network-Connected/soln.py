class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1
        graph = [[] for _ in range(n)]
        for u, v in connections:
            graph[u].append(v)
            graph[v].append(u)
        visited = [False] * n
        def dfs(node):
            visited[node] = True
            for nei in graph[node]:
                if not visited[nei]:
                    dfs(nei)
        cnt = 0
        for u in range(n):
            if not visited[u]:
                cnt += 1
                dfs(u)
        return cnt - 1
