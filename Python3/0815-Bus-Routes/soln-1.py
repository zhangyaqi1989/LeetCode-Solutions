class Solution:
    def numBusesToDestination(self, routes: List[List[int]], S: int, T: int) -> int:
        stops = collections.defaultdict(list)
        for i, route in enumerate(routes):
            for stop in route:
                stops[stop].append(i)
        steps = 0
        queue = collections.deque([S])
        seen = {S}
        while queue:
            size = len(queue)
            for _ in range(size):
                stop = queue.popleft()
                if stop == T:
                    return steps
                for line in stops[stop]:
                    for nei in routes[line]:
                        if nei not in seen:
                            seen.add(nei)
                            queue.append(nei)
                    routes[line] = []
            steps += 1
        return -1
