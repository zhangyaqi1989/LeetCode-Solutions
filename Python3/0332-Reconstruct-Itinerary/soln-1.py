class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        graph = collections.defaultdict(list)
        for start, end in sorted(tickets, reverse=True):
            graph[start].append(end)
        route = []
        stack = ['JFK']
        while stack:
            while stack and graph[stack[-1]]:
                stack.append(graph[stack[-1]].pop())
            route.append(stack.pop())
        return route[::-1]