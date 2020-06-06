class Solution:
    def numBusesToDestination(self, routes, S, T):
        """
        :type routes: List[List[int]]
        :type S: int
        :type T: int
        :rtype: int
        """
        # this is a BFS
        stop_to_routes = collections.defaultdict(list)
        for route_idx, stops in enumerate(routes):
            for stop in stops:
                stop_to_routes[stop].append(route_idx)
        stop_seen = {S}
        queue = collections.deque([S])
        step = 0
        while queue:
            size = len(queue)
            for _ in range(size):
                stop = queue.popleft()
                if stop == T:
                    return step
                for route_idx in stop_to_routes[stop]:
                    for next_stop in routes[route_idx]:
                        if next_stop not in stop_seen:
                            stop_seen.add(next_stop)
                            queue.append(next_stop)
                    routes[route_idx] = []
            step += 1
        return -1