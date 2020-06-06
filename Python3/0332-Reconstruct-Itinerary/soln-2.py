class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = collections.defaultdict(list)
        for s, e in sorted(tickets, reverse=True):
            graph[s].append(e)
        visited = set()
        route = []
        stack = ['JFK']
        while stack:
            while stack and graph[stack[-1]]:
                stack.append(graph[stack[-1]].pop())
            route.append(stack.pop())
        return route[::-1]
