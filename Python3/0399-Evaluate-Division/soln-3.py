class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = collections.defaultdict(dict)
        for (a, b), v in zip(equations, values):
            graph[a][a] = 1.0
            graph[b][b] = 1.0
            graph[a][b] = v
            graph[b][a] = 1.0 / v
        ans = []
        for a, b in queries:
            stack = [(key, val) for key, val in graph[a].items()]
            visited = {key for key, _ in stack}
            while stack:
                node, val = stack.pop()
                if node == b:
                    ans.append(val)
                    break
                for nei, r in graph[node].items():
                    if nei not in visited:
                        visited.add(nei)
                        stack.append((nei, val * r))
            else:
                ans.append(-1.0)
        return ans
