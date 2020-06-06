class Solution:
    def leadsToDestination(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
        visited = [False] * n
        seen = set()
        def dfs(node):
            if node in seen:
                return True
            if visited[node]:
                return False
            visited[node] = True
            if not graph[node] and node != destination:
                return False
            for nei in graph[node]:
                if not dfs(nei):
                    return False
            seen.add(node)
            return True
        return dfs(source)
