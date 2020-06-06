class Solution:
    def leadsToDestination(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
        visited = set()
        def dfs(node):
            if node not in graph:
                return node == destination
            visited.add(node)
            for nei in graph[node]:
                if nei in visited or not dfs(nei):
                    return False
            visited.remove(node)
            return True
        return dfs(source)
