class Solution:
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        target = collections.defaultdict(list)
        for a, b in sorted(tickets, reverse=True):
            target[a] += [b]
        route = []
        def visit(airport):
            while target[airport]:
                visit(target[airport].pop())
            route.append(airport)
        visit('JFK')
        return route[::-1]