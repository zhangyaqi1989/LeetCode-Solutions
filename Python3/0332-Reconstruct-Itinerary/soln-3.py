class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = collections.defaultdict(list)
        for u, v in tickets:
            graph[u].append(v)
        for u, adj in graph.items():
            adj.sort(reverse=True)
        path = []
        def dfs(node):
            while graph[node]:
                dfs(graph[node].pop())
            path.append(node)
        dfs("JFK")
        return path[::-1]
