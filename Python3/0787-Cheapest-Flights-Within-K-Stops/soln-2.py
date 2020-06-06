class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        # run Bellman-Ford K + 1 times
        costs = [math.inf] * n
        costs[src] = 0
        for _ in range(K + 1):
            nxt_costs = costs[:]
            for u, v, w in flights:
                 if costs[u] + w < nxt_costs[v]:
                    nxt_costs[v] = costs[u] + w
            costs = nxt_costs
        return costs[dst] if costs[dst] != math.inf else -1 
