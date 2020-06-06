class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        INF = 1000000
        lows = [INF] * n
        ranks = [INF] * n
        graph = collections.defaultdict(list)
        for u, v in connections:
            graph[u].append(v)
            graph[v].append(u)
        self.time = 0
        def dfs(node, parent):
            lows[node] = self.time
            ranks[node] = self.time
            self.time += 1
            for nei in graph[node]:
                if ranks[nei] == INF:
                    dfs(nei, node)
            for nei in graph[node]:
                if nei != parent:
                    lows[node] = min(lows[node], lows[nei])
        dfs(0, -1)
        ans = []
        for u, v in connections:
            if lows[v] > ranks[u] or lows[u] > ranks[v]:
                ans.append([u, v])
        return ans
