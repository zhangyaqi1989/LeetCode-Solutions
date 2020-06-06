class Solution:
    def leadsToDestination(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
        visited = [False] * n
        def dfs(node):
            if not graph[node]:
                return node == destination
            visited[node] = True
            for nei in graph[node]:
                if visited[nei] or not dfs(nei):
                    return False
            visited[node] = False
            return True
        return dfs(source)
