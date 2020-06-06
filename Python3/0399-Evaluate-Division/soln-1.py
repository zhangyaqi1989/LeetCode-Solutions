class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = collections.defaultdict(dict)
        for value, (nume, deno) in zip(values, equations):
            graph[nume][deno] = value
            graph[deno][nume] = 1.0 / value
            graph[nume][nume] = 1.0
            graph[deno][deno] = 1.0
        for k, i, j in itertools.permutations(graph, 3):
            if k in graph[i] and j in graph[k]:
                graph[i][j] = graph[i][k] * graph[k][j]
        return [graph[a].get(b, -1.0) if a in graph else -1 for a, b in queries]
