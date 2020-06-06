class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        def dfs(a, b):
            if a not in graph:
                return -1.0
            stack = [(a, 1.0)]
            seen = {a}
            while stack:
                node, cost = stack.pop()
                if node == b:
                    return cost
                for nei, v in graph[node].items():
                    if nei not in seen:
                        seen.add(nei)
                        stack.append((nei, cost * v))
            return -1.0
                    
        graph = collections.defaultdict(dict)
        for (a, b), v in zip(equations, values):
            graph[a][a] = graph[b][b] = 1.0
            graph[a][b] = 1.0 * v
            graph[b][a] = 1.0 / v
        return [dfs(a, b) for a, b in queries]
        
