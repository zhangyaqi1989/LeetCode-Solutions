class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        graph = [[] for _ in range(n)]
        for u, v in connections:
            graph[u].append(v)
            graph[v].append(u)
        ranks = [math.inf] * n
        lows = [math.inf] * n
        timer = itertools.count()
        def dfs(node, parent=-1):
            time = next(timer)
            ranks[node] = time
            lows[node] = time
            for nei in graph[node]:
                if ranks[nei] == math.inf:
                    dfs(nei, node)
            for nei in graph[node]:
                if nei != parent:
                    lows[node] = min(lows[node], lows[nei])
        dfs(0, -1)
        ans = []
        for u, v in connections:
            if lows[u] > ranks[v] or lows[v] > ranks[u]:
                ans.append([u, v])
        return ans
