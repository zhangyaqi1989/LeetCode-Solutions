class Solution:
    def leadsToDestination(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
        if destination in graph:
            return False
        marked = [False] * n
        def dfs(node):
            if not graph[node] and node != destination:
                return False
            marked[node] = True
            for nei in graph[node]:
                if not marked[nei]:
                    if not dfs(nei):
                        return False
                else:
                    return False
            marked[node] = False # in order to let it visit again
            return True
        return dfs(source)
