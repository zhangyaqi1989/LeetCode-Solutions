class Solution:
    def checkIfPrerequisite(self, n: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        graph = [[False] * n for _ in range(n)]
        for i in range(n):
            graph[i][i] = True
        for u, v in prerequisites:
            graph[u][v] = True
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    graph[i][j] = graph[i][j] | (graph[i][k] & graph[k][j])
        return [graph[u][v] for u, v in queries]
