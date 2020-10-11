class Solution:
    def countSubgraphsForEachDiameter(self, n: int, edges: List[List[int]]) -> List[int]:
        dist = [[math.inf] * n for _ in range(n)]
        for u, v in edges:
            u -= 1
            v -= 1
            dist[u][v] = 1
            dist[v][u] = 1
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if dist[i][j] > dist[i][k] + dist[k][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]
        counter = [0] * (n - 1)
        for state in range(1 << n):
            nodes = []
            for i in range(n):
                if state & (1 << i):
                    nodes.append(i)
            nedges = sum(dist[i][j] == 1
                         for i, j in itertools.combinations(nodes, 2))
            if nedges == len(nodes) - 1 and len(nodes) > 1:
                max_dist = max(dist[i][j]
                              for i, j in itertools.combinations(nodes, 2))
                counter[max_dist - 1] += 1
        return counter
