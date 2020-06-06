class Solution:
    def gardenNoAdj(self, N: int, paths: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(N)]
        for u, v in paths:
            u -= 1
            v -= 1
            graph[u].append(v)
            graph[v].append(u)
        colors = [0] * N
        for node in range(N):
            if colors[node] == 0:
                valids = [True] * 5
                for nei in graph[node]:
                    valids[colors[nei]] = False
                for c in range(1, 5):
                    if valids[c]:
                        colors[node] = c
                        break
        return colors
