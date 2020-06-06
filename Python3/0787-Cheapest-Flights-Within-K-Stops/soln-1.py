class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        graph = collections.defaultdict(dict)
        for a, b, w in flights:
            graph[a][b] = w
        pq = [(0, K + 1, src)] # cost, stops, cur
        while pq:
            cost, stops, cur = heapq.heappop(pq)
            if cur == dst:
                return cost
            if stops > 0:
                for nei, w in graph[cur].items():
                    heapq.heappush(pq, (cost + w, stops - 1, nei))
        return -1
